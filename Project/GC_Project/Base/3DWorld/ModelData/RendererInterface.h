#ifndef RENDERERINTERFACE_H
#define RENDERERINTERFACE_H

#include <windows.h> // Needed to compile gl.h
#include <gl/GL.h>

namespace __3DWorld__ {

/**
 * @author Wald Habets
 * @brief The RendererInterface class
 */
class RendererInterface {
public:
    virtual void draw(GLenum s_mode, GLenum f_mode) = 0;
};

}

#endif // RENDERERINTERFACE_H
