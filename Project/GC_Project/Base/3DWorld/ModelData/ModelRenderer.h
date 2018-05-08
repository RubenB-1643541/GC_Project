#ifndef PRIMITIVEMODEL_H
#define PRIMITIVEMODEL_H

#include "modelloader.h"
#include "model.h"

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
    ModelRenderer(Model* model);
    void draw(GLenum s_mode, GLenum f_mode);
private:

    Model* _model;
    ModelLoader _loader;

    std::vector<MLMesh> _meshes;
};

}

#endif // PRIMITIVEMODEL_H
