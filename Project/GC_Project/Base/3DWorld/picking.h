#ifndef PICKING_H
#define PICKING_H

#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <QDebug>
namespace __3DWorld__ {

class Picking
{
public:
    Picking();
    void startPicking();
    void endPicking();
    void procesHits();
    int getResult();
    bool isPicking() {return _started;}
private:
    void createBuffer();
    int _buffer_size;
    GLuint * _selectBuffer;
    GLint _hits;
    int _first_hit;
    bool _started;
};

}

#endif // PICKING_H
