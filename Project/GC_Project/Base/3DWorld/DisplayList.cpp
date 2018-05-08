#include "DisplayList.h"

namespace __3DWorld__ {

DisplayList::DisplayList() {

}

GLuint DisplayList::create(std::string path) {
    ModelLoader loader;
    loader.load(path);
    std::vector<MLMesh> meshes = loader.getMeshes();

    GLuint index = glGenLists(1);
    int error = glGetError();
    if (error == GL_INVALID_VALUE)
        qDebug() << "GL_INVALID_VALUE" << error;
    if (error == GL_INVALID_OPERATION)
        qDebug() << "GL_INVALID_OPERATION" << error;

    glNewList(index, GL_COMPILE);
    // Draw Meshes
    glBegin(GL_TRIANGLES);
    for (MLMesh mesh : meshes) {
        //qDebug() << "nr vertices" << mesh.vertices.size();
        for (unsigned int i: mesh.indices) {
            MLVertex vertex = mesh.vertices[i];

            // Normal for light direction
            glNormal3d(
                vertex.normal.x(),
                vertex.normal.y(),
                vertex.normal.z()
            );
            glTexCoord3d(
                vertex.position.x(),
                vertex.position.y(),
                vertex.position.z()
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

    return index;
}

}
