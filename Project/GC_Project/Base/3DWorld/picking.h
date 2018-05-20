#ifndef PICKING_H
#define PICKING_H

#include <windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <QDebug>
#include "ModelData/RendererInterface.h"
#include "Camera.h"
namespace __3DWorld__ {

class Picking
{
public:
    Picking();
    int pick(const std::vector<RendererInterface*> &renderers, GLenum sm, GLenum rm);
    void handleResult(std::vector<RendererInterface*> &renderers, int result);
private:

};

}

#endif // PICKING_H
