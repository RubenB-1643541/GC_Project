#ifndef PRIMITIVEMODEL_H
#define PRIMITIVEMODEL_H

#include "Model/modeldata.h"
#include "Model/modelloader.h"
#include "modelobject.h"

#include <windows.h> // Needed to compile gl.h
#include <gl/GL.h>
#include <gl/GLU.h>

namespace __3DWorld__ {

enum ShadingMode {
    FLAT = GL_FLAT,
    SMOOTH = GL_SMOOTH
};
enum FrameMode {
    WIREFRAME = GL_LINE,
    FILL = GL_FILL
};

class PrimitiveModel {
public:
    PrimitiveModel();
    void draw(ShadingMode s_mode, FrameMode f_mode);
private:

    ModelObject* _obj;
    ModelLoader _loader;

    std::vector<MLMesh> _meshes;
};

}

#endif // PRIMITIVEMODEL_H
