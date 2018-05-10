#ifndef PICKING_H
#define PICKING_H

#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <QDebug>
#include <QMouseEvent>
namespace __3DWorld__ {

class Picking
{
public:
    Picking();
    void startPicking(QMouseEvent * event, int heigth, int width);
    void endPicking();
    void procesHits();
    bool isPicking() {return _started;}
    void resetDrawing();
    void startDrawing();
    void endDrawing();
    int getResult() {return _result;}
private:
    GLint _hits;
    int _first_hit;
    bool _started;
    int _draw;
    int _result;

    using uint = unsigned int;
    int _selectBufferSize = 100;
    std::vector<uint> _selectBuffer = std::vector<uint>(_selectBufferSize);
};

}

#endif // PICKING_H
