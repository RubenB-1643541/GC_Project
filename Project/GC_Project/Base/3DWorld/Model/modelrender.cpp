#include "modelrender.h"

namespace __3DWorld__ {

ModelRender::ModelRender() : _vbo(QOpenGLBuffer::VertexBuffer), _nbo(QOpenGLBuffer::VertexBuffer), _ibo(QOpenGLBuffer::IndexBuffer)
{

}

void ModelRender::CreateShaderProgram() {
    if ( !_shaders.addShaderFromSourceCode( QOpenGLShader::Vertex, vertexShader)) {
        qDebug() << "Error in vertex shader:" << _shaders.log();
        exit(1);
    }
    if ( !_shaders.addShaderFromSourceCode( QOpenGLShader::Fragment, fragmentShader)) {
        qDebug() << "Error in fragment shader:" << _shaders.log();
        exit(1);
    }
    if ( !_shaders.link() ) {
        qDebug() << "Error linking shader program:" << _shaders.log();
        exit(1);
    }
}

void ModelRender::CreateGeometry() {

    QVector<float> *v;
    QVector<float> *n;
    QVector<uint> *i;

    v = _obj->GetVertices();
    n = _obj->GetNormals();
    i = _obj->GetIndices();

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
    model.translate(_obj->GetPosition()->x(), _obj->GetPosition()->y(), _obj->GetPosition()->z());
    model.rotate(20.0f, _obj->GetRotation()->x(), _obj->GetRotation()->y(), _obj->GetRotation()->z());
    model.scale(_obj->GetSize());
    DrawNode(model, _obj->GetNode().data(), QMatrix4x4());
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
        /*
        int width, height;
        unsigned char * pixels = SOIL_load_image("Models/Bobomb/1B46C8C_c.bmp", &width, &height, 0, SOIL_LOAD_RGB);
        glGenTextures(1, &_texture);
        glBindTexture(GL_TEXTURE_2D, _texture);
        glTexImage2D(GL_TEXTURE_2D, 0, (GLint)1024, (GLsizei)1024, (GLsizei) 1024, 0, GL_RGB, GL_UNSIGNED_BYTE, (void*)pixels);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
*/
        glDrawElements(GL_TRIANGLES, m.indexCount, GL_UNSIGNED_INT, (const GLvoid*) (m.indexOffset * sizeof(GLuint)));
    }
    
}

void ModelRender::LoadModel(QString path) {
    _loader.Load(path);
    _obj = new ModelObject();
    _loader.GetBufferData(_obj);
    _loader.GetNodeData(_obj);
}

void ModelRender::LoadModel(QString path, Point3D * position) {
    LoadModel(path);
    _obj->SetPosition(position);
}
void ModelRender::LoadModel(QString path, Point3D * position, Point3D * rotation) {
    LoadModel(path);
    _obj->SetPosition(position);
    _obj->SetRotation(rotation);
}
void ModelRender::LoadModel(QString path, Point3D *position, Point3D *rotation, float size) {
    LoadModel(path, position, rotation);
    _obj->SetSize(size);
}

void ModelRender::Initialize() {
    QOpenGLFunctions::initializeOpenGLFunctions();
    CreateShaderProgram();
    _shaders.bind();

    _shaders.setUniformValue("light.position",   QVector4D( -1.0f,  1.0f, 1.0f, 1.0f ));
    _shaders.setUniformValue("light.intensity",  QVector3D(  1.0f,  1.0f, 1.0f  ));
    InitializeTextures();
    CreateGeometry();
}

void ModelRender::Paint() {
    _shaders.bind();
    _vertrex_object.bind();
    Draw();
    _vertrex_object.release();
}

void ModelRender::Resize(int w, int h) {
    _projection.perspective(80.0f, (float)w/h, .3f, 1000);//80 en 1000 hebben invloed op de hoek
}

void ModelRender::SetView(Point3D lookat, Point3D position) {
    _view.setToIdentity();
    _view.lookAt(QVector3D(position.x(), position.y(), position.z()),
                 QVector3D(lookat.x(), lookat.y(), lookat.z()),
                 QVector3D(0.0f, 1.0f, 0.0f));
}
//https://open.gl/textures
void ModelRender::InitializeTextures() {

    /*
    float pixels[] = {
        0.0f, 0.0f, 0.0f,   1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,   0.0f, 0.0f, 0.0f
    };
    glGenTextures(1, &_texture);
    glBindTexture(GL_TEXTURE_2D, _texture);
    glTexImage2D(GL_TEXTURE_2D, 0, (GLint)1024, (GLsizei)1024, (GLsizei) 1024, 0, GL_RGB, GL_UNSIGNED_BYTE, (void*)pixels);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    */
}

}
