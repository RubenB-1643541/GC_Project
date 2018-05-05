#include "PrimitiveModel.h"

namespace __3DWorld__ {

PrimitiveModel::PrimitiveModel() {
    _loader.load("bobomb battlefeild.obj");
    _meshes = _loader.getMeshes();
}
void PrimitiveModel::draw(ShadingMode s_mode, FrameMode f_mode) {
    glPushMatrix();

    // Material for light interaction
    /*
    GLfloat diffuse[] = {0.54f, 0.89f, 0.63f, 1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);
    // */
    /*
    GLfloat shinniness[] = { 12.8f };
    glMaterialfv(GL_FRONT, GL_SHININESS, diffuse);
    // */
    /*
    GLfloat ambient[] = {0.54f, 0.89f, 0.63f, 1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    // */
    /*
    GLfloat specular[] = {0.54f, 0.89f, 0.63f, 0.5f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
    // */
    glMateriali(GL_FRONT, GL_SHININESS, 20);

    glShadeModel(s_mode);                       // Type of shader (flat, smooth)
    glPolygonMode(GL_FRONT_AND_BACK, f_mode);   // Type of frame (wirefram, filled)

    /*
    for (MLMesh mesh : _meshes) {
        glDrawElements(GL_TRIANGLES, mesh.num_faces, GL_UNSIGNED_INT, 0);
    }
    // */

    // Draw Meshes
    //*
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

    // */

    glPopMatrix();
}

}


