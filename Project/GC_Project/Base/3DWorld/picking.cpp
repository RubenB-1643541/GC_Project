#include "picking.h"

namespace __3DWorld__ {

Picking::Picking()
{
    _buffer_size = 512;
    _started = false;
}

void Picking::createBuffer() {
    _selectBuffer = new GLuint[_buffer_size];
    glSelectBuffer(_buffer_size, _selectBuffer);
}

void Picking::startPicking() {
    _started = true;
    qDebug() << "Picking started";
    glRenderMode(GL_SELECT);
    glInitNames();
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);

    GLdouble pm[16];
    glGetDoublev(GL_PROJECTION_MATRIX, pm);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    //gluPickMatrix(point.x, (viewport[3] - point.y), 5.0, 5.0, viewport);
    glMultMatrixd(pm);
}

void Picking::endPicking() {
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    _hits = glRenderMode(GL_RENDER);
    _started = false;
    qDebug() << "Picking finished";
}

void Picking::procesHits() {
    GLuint min_minz = 0xffffffff;

    _first_hit = -1;
    GLuint * ptr = (GLuint *) _selectBuffer;
    for(GLint i = 0; i < _hits; ++i) {
        GLuint nr_names = *ptr;
        ++ptr;

        GLuint minz = *ptr;
        ++ptr;

        GLuint maxz = *ptr;
        ++ptr;

        for(GLuint j = 0; j < nr_names; ++j) {
            if(minz < min_minz) {
                min_minz = minz;
                _first_hit = *ptr;
            }
            ++ptr;
        }
    }
    qDebug() << "Picking result" << _first_hit;
}

}
