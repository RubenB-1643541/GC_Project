#include "picking.h"

namespace __3DWorld__ {

Picking::Picking()
{
    _started = false;
    _result = 0;
}

void Picking::startPicking(QMouseEvent * event, int heigth, int width) {

    std::fill(_selectBuffer.begin(), _selectBuffer.end(), 0);
    glSelectBuffer(_selectBufferSize, &_selectBuffer[0]);

    glRenderMode(GL_SELECT);

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();

    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    gluPickMatrix(event->x(), heigth - event->y(), 5,5,viewport);
    const float aspect = static_cast<float>(viewport[2]) / viewport[3];
    gluPerspective(45.0, aspect, 1.0, 1000.0);

    /*
    createBuffer();
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
    gluPickMatrix(event->x(), (viewport[3] - event->y()), 5.0, 5.0, viewport);
    glMultMatrixd(pm);
    */
}

void Picking::endPicking() {
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();

    _hits = glRenderMode(GL_RENDER);
    _started = false;
    qDebug() << "Picking finished - hits: " << _hits;
}

void Picking::procesHits() {

    if (_hits > 0) {
        int id = 0;
        for (int i = 0; i < _hits; i++) {

            qDebug() << "Level: " << _selectBuffer.at(id + 0);
            qDebug() << "Min: " << (double)_selectBuffer.at(id + 1) / UINT_MAX;
            qDebug() << "Max: " << (double)_selectBuffer.at(id + 2) / UINT_MAX;
            qDebug() << "ID: " << _selectBuffer.at(id + 3);
            _result = _selectBuffer.at(id + 3);
            id += 4;

        }
    }
    /*
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
        qDebug() << "Picking result - firsthit:" << _first_hit << " minz: " << minz << " maxz: " << maxz;
    }
    qDebug() << "Picking final result - firsthit:" << _first_hit;
    */
}

void Picking::startDrawing() {
    qDebug() << "Picking draw: " << _draw;
    glLoadName(_draw);
    ++_draw;
}

void Picking::endDrawing() {
    glPopName();
}

void Picking::resetDrawing() {
    _draw = 0;
    glInitNames();
    glPushName(_draw);
    ++_draw;
}

}
