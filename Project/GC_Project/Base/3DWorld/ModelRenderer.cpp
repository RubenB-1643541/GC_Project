#include "ModelRenderer.h"

namespace __3DWorld__ {

ModelRenderer::ModelRenderer(std::string path) {
    _loader.load(path);
    _meshes = _loader.getMeshes();
}
void ModelRenderer::draw(GLenum s_mode, GLenum f_mode) {
    glPushMatrix();

    // Material for light interaction
    // Todo
    GLfloat diffuse_color[] = { 0.55f, 0.51f, 0.47f, 1.0f }; // Grey
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_color);
    GLfloat specular_color[] = { 0.55f, 0.51f, 0.47f, 1.0f };
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular_color);
    GLfloat ambient_color[] = { 0.55f, 0.51f, 0.47f, 1.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_color);
    glMateriali(GL_FRONT, GL_SHININESS, 5);

    glShadeModel(s_mode);                       // Type of shader (flat, smooth)
    glPolygonMode(GL_FRONT_AND_BACK, f_mode);   // Type of frame (wirefram, filled)

    // Draw Meshes
    glBegin(GL_TRIANGLES);
    for (MLMesh mesh : _meshes) {
        //qDebug() << "nr vertices" << mesh.vertices.size();
        for (unsigned int i: mesh.indices) {
            MLVertex vertex = mesh.vertices[i];

            // Normal for light direction
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

    glPopMatrix();
}

}


