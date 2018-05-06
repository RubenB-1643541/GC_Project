#include "Settings.h"

namespace __3DWorld__ {

////////////////////////////////////////////////////////
/// Construction
////////////////////////////////////////////////////////
Settings::Settings() {
    _shading_mode = ShadingMode::SMOOTH;
    _render_mode = RenderMode::FILL;
}

////////////////////////////////////////////////////////
/// Query
////////////////////////////////////////////////////////
void Settings::setShadingMode(const ShadingMode mode) {
    _shading_mode = mode;
}

void Settings::setRenderMode(const RenderMode mode) {
    _render_mode = mode;
}
GLenum Settings::getShadingMode() const {
    switch(_shading_mode) {
    case SMOOTH:
        return GL_SMOOTH;
    case FLAT:
        return GL_FLAT;
    }
}
GLenum Settings::getRenderMode() const {
    switch(_render_mode) {
    case FILL:
        return GL_FILL;
    case WIREFRAME:
        return GL_LINE;
    }
}

}
