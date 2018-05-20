#include "picking.h"

namespace __3DWorld__ {

Picking::Picking()
{

}

int Picking::pick(const std::vector<RendererInterface*> &renderers, GLenum sm, GLenum rm) {
    GLuint select_buffer[512];
    glSelectBuffer(512, select_buffer);

    glRenderMode(GL_SELECT);
    glInitNames();

    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);

    GLdouble projection[16];
    glGetDoublev(GL_PROJECTION_MATRIX, projection);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
        glLoadIdentity();
        gluPickMatrix(viewport[2]/2, viewport[3]/2, 5, 5, viewport);
        glMultMatrixd(projection);

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glRenderMode(GL_SELECT);
    qDebug() << "num objects:" << renderers.size();
    glInitNames();
    for (unsigned int i = 0; i < renderers.size(); i++) {
       glPushName(i);
       renderers[i]->draw(sm, rm);
       glPopName();
    }

    //glMatrixMode(GL_MODELVIEW);
    GLint hits = glRenderMode(GL_RENDER);
    qDebug() << "hits:" << hits;

    GLuint smallestZ = 0xffffffff;

    int firstHit = -1;
    GLuint *ptr = (GLuint*)select_buffer;

    for (GLint i = 0; i < hits; i++) {
        GLuint thing = *ptr; qDebug() << "thing" << thing;
        GLuint min_z = *(ptr + 1); qDebug() << "min:" << min_z;
        GLuint max_z = *(ptr + 2);
        GLuint name = *(ptr + 3); qDebug() << "name:" << name;

        if (min_z < smallestZ) {
            smallestZ = min_z;
            firstHit = name;
        }

        ptr += 4;
    }

    renderers[firstHit]->onPick();

    qDebug() << firstHit;
    return firstHit;
}

}
