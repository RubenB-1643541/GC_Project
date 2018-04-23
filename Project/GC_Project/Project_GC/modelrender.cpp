#include "modelrender.h"

ModelRender::ModelRender() : _vbo(QOpenGLBuffer::VertexBuffer), _nbo(QOpenGLBuffer::VertexBuffer),_ibo(QOpenGLBuffer::IndexBuffer)
{

}

void ModelRender::initializeGL() {
    QOpenGLFunctions::initializeOpenGLFunctions();
    CreateShaderProgram();
    _shaders.bind();

    _shaders.setUniformValue("light.position",   QVector4D( -1.0f,  1.0f, 1.0f, 1.0f ));
    _shaders.setUniformValue("light.intensity",  QVector3D(  1.0f,  1.0f, 1.0f  ));

    CreateGeometry();
    _view.setToIdentity();
    _view.lookAt(QVector3D(0.0f, 0.0f, 1.2f),    // Camera Position
                 QVector3D(0.0f, 0.0f, 0.0f),    // Point camera looks towards
                 QVector3D(0.0f, 1.0f, 0.0f));

    glEnable(GL_DEPTH_TEST);

    glClearColor(.9f, .9f, .93f ,1.0f);
}

void ModelRender::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    _shaders.bind();
    _vertrex_object.bind();
    Draw();
    _vertrex_object.release();
    update();
}

void ModelRender::ResizeGL() {
    glViewport(0, 0, w, h);
    _projection.setToIdentity();
    _projection.perspective(60.0f, (float)w/h, .3f, 1000);
    update();
}

void ModelRender::CreateShaderProgram() {

}

void ModelRender::CreateGeometry() {
    if(!m_loader.Load("velociraptor_mesh_materials.dae")) {
        qDebug() << "ModelLoader failed to load model" << m_pgm.log();
        exit(1);
    }

    // Get the loaded model data from the model-loader: (v)ertices, (n)ormals, and (i)ndices
    QVector<float> *v;
    QVector<float> *n;
    QVector<uint> *i;
    _loader.GetBufferData(&v, &n, &i);

    _vertrex_object.create();
    _vertrex_object.bind();

    _vbo.create();
    _vbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    _vbo.bind();
    _vbo.allocate(&(*v)[0], v->size() * sizeof((*v)[0]));

    _shaders.enableAttributeArray(0);
    _shaders.setAttributeBuffer(0, GL_FLOAT, 0, 3);

    _nbo.create();
    _nbo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    _nbo.bind();
    _nbo.allocate(&(*n)[0], n->size() * sizeof((*n)[0]));

    _shaders.enableAttributeArray(1);
    _shaders.setAttributeBuffer(1, GL_FLOAT, 0, 3);

    _ibo.create();
    _ibo.setUsagePattern(QOpenGLBuffer::StaticDraw);
    _ibo.bind();
    _ibo.allocate(&(*i)[0], i->size() * sizeof((*i)[0]));

    _vertrex_object.release();
}

void ModelRender::DrawNode(const QMatrix4x4 model, const Node *node, QMatrix4x4 parent) {
    QMatrix4x4 local = parent * node->transformation;
    QMatrix4x4 mv = _view * model * local;
    
    _shaders.setUniformValue("MV", mv);
    _shaders.setUniformValue("N", mv.normalMatrix());
    _shaders.setUniformValue("MVP", _projection * mv);
    DrawMeshFromNode(node);

    for(int i = 0; i < node->nodes.size(); ++i) {
        DrawNode(model, &node->nodes[i], local);
    }    
}

void ModelRender::Draw() {
    QMatrix4x4 model;
    model.translate(-0.2f, 0.0f, .5f);
    model.rotate(55.0f, 0.0f, 1.0f, 0.0f);
    
    DrawNode(model, _loader.GetNodeData().data(), QMatrix4x4());
    
}

void ModelRender::DrawMeshFromNode(const Node *node) {
    for(int i = 0; i < node->meshes.size(); ++i) {
        const Mesh& m = *node->meshes[i];
        if(m.material->name == QString("DefaultMaterial")) {
            _shaders.setUniformValue("material.Ka", QVector3D(0.05f, 0.2f, 0.05f ));
            _shaders.setUniformValue("material.Kd", QVector3D(  0.3f,  0.5f, 0.3f  ));
            _shaders.setUniformValue("material.Ks", QVector3D(  0.6f,  0.6f, 0.6f  ));
            _shaders.setUniformValue("material.shininess", 50.f);
        } else {
            _shaders.setUniformValue("material.Ka", m.material->ambient);
            _shaders.setUniformValue("material.Kd", m.material->diffuse);
            _shaders.setUniformValue("material.Ks", m.material->specular);
            _shaders.setUniformValue("material.shininess", m.material->shininess);
        }
        glDrawElements(GL_TRIANGLES, m.indexCount, GL_UNSIGNED_INT, (const GLvoid*) (m.indexOffset * sizeof(GLuint)));
    }
    
}
