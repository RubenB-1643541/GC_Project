#ifndef PICKING_H
#define PICKING_H

#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
namespace __3DWorld__ {

class Picking
{
public:
    Picking();
    void startPicking();
    void endPicking();
    void procesHits();
private:
    void createBuffer();
    int _buffer_size;
    GLuint * _selectBuffer;
    GLint _hits;
    int _first_hit;
};

}

#endif // PICKING_H
