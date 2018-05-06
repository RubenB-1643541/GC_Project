#ifndef PRIMITIVEMODEL_H
#define PRIMITIVEMODEL_H

#include "Model/modeldata.h"
#include "modelloader.h"
#include "modelobject.h"

#include <windows.h> // Needed to compile gl.h
#include <gl/GL.h>
#include <gl/GLU.h>

namespace __3DWorld__ {

/**
 * @author Wald Habets
 * @brief The PrimitiveModel class
 */
class ModelRenderer {
public:
    ModelRenderer(std::string path);
    void draw(GLenum s_mode, GLenum f_mode);
private:

    ModelObject* _obj;
    ModelLoader _loader;

    std::vector<MLMesh> _meshes;
};

}

#endif // PRIMITIVEMODEL_H
