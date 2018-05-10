#include "ModelData/ModelObject.h"

namespace __3DWorld__ {

ModelObject::ModelObject(QString path) {
    _loader.load(path.toLocal8Bit().constData());
    _meshes = _loader.getMeshes();
}

void ModelObject::draw() {

    glBegin(GL_TRIANGLES);

    for (MLMesh mesh : _meshes) {
        //qDebug() << "nr vertices" << mesh.vertices.size();
        for (unsigned int i: mesh.indices) {
            MLVertex vertex = mesh.vertices[i];

            /*Vector3D v;
            v.setTo(vertex.position);
            v.normalize();*/
            //Vector3D v = vertex.normal;

            glNormal3d(
                vertex.normal.x(),
                vertex.normal.y(),
                vertex.normal.z()
            );

            glVertex3d(
                vertex.position.x(),
                vertex.position.y(),
                vertex.position.z()
            );
        }
    }
    glEnd();
}

GLuint ModelObject::initialize() {
    GLuint display_id = glGenLists(1);
    glNewList(display_id, GL_COMPILE_AND_EXECUTE);
    glBegin(GL_TRIANGLES);
    for (MLMesh mesh : _meshes) {
        //qDebug() << "nr vertices" << mesh.vertices.size();
        for (unsigned int i: mesh.indices) {
            MLVertex vertex = mesh.vertices[i];

            /*Vector3D v;
            v.setTo(vertex.position);
            v.normalize();*/
            //Vector3D v = vertex.normal;

            glNormal3d(
                vertex.normal.x(),
                vertex.normal.y(),
                vertex.normal.z()
            );

            glVertex3d(
                vertex.position.x(),
                vertex.position.y(),
                vertex.position.z()
            );
        }
    }
    glEnd();
    glEndList();
    return display_id;
}



}
