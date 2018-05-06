#ifndef SETTINGS_H
#define SETTINGS_H

#include <windows.h> // needed for gl.h to work
#include <gl/GL.h>
#include "mvc.hpp"

namespace __3DWorld__ {

enum ShadingMode {
    SMOOTH,
    FLAT
};
enum RenderMode {
    FILL,
    WIREFRAME
};

/**
 * @author Wald Habets
 * @brief The Settings class
 */
class Settings :
public ModelInterface {
public:
    ////////////////////////////////////////////////////////
    /// Construction
    ////////////////////////////////////////////////////////
    Settings();

    ////////////////////////////////////////////////////////
    /// Query
    ////////////////////////////////////////////////////////
    void setShadingMode(const ShadingMode mode);
    void setRenderMode(const RenderMode mode);

    GLenum getShadingMode() const;
    GLenum getRenderMode() const;
private:
    ShadingMode _shading_mode;
    RenderMode _render_mode;
};

}

#endif // SETTINGS_H
