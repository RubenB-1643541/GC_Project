#include "PrimitiveModel.h"

namespace __3DWorld__ {

PrimitiveModel::PrimitiveModel() {
    _loader.load("bobomb battlefeild.obj");
    _meshes = _loader.getMeshes();
}
void PrimitiveModel::draw(ShadingMode s_mode, FrameMode f_mode) {
    glPushMatrix();

    // Material for light interaction
    GLfloat diffuse[] = {0.54f, 0.89f, 0.63f, 1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse);

    /*
    GLfloat shinniness[] = { 12.8f };
    glMaterialfv(GL_FRONT, GL_SHININESS, diffuse);
    *//*
    GLfloat ambient[] = {0.54f, 0.89f, 0.63f, 1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
    *//*
    GLfloat specular[] = {0.54f, 0.89f, 0.63f, 1.0f};
    glMaterialfv(GL_FRONT, GL_SPECULAR, diffuse);
    */

    glShadeModel(s_mode);                       // Type of shader (flat, smooth)
    glPolygonMode(GL_FRONT_AND_BACK, f_mode);   // Type of frame (wirefram, filled)

    // Draw Meshes
    for (MLMesh mesh : _meshes) {
        glBegin(GL_TRIANGLES);
        for (MLVertex vertex: mesh.vertices) {
            glVertex3d(
                vertex.position.x(),
                vertex.position.y(),
                vertex.position.z()
            );
        }
        glEnd();
    }

    glPopMatrix();
}

}


