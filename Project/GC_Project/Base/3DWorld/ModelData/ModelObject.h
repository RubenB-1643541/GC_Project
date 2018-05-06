#ifndef MODEL_OBJECT
#define MODEL_OBJECT

#include "Model/modelloader.h"

#include <windows.h> // Needed to compile gl.h
#include <gl/GL.h>
#include <gl/GLU.h>

namespace __3DWorld__ {

/**
 * @author Wald Habets
 * @brief
 */

enum ShadingMode {
    FLAT = GL_FLAT,
    SMOOTH = GL_SMOOTH
};
enum FrameMode {
    WIREFRAME = GL_LINE,
    FILL = GL_FILL
};

class ModelObject {
public:
    ModelObject(QString Path);
    void draw(ShadingMode s_mode, FrameMode f_mode);
    GLuint initialize();



private:

    ModelLoader _loader;

    std::vector<MLMesh> _meshes;
};
}

#endif MODEL_OBJECT
