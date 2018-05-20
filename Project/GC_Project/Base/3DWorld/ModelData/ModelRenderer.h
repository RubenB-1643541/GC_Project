#ifndef PRIMITIVEMODEL_H
#define PRIMITIVEMODEL_H

#include "RendererInterface.h"
#include "model.h"

#include <windows.h> // Needed to compile gl.h
#include <gl/GL.h>

namespace __3DWorld__ {

/**
 * @author Wald Habets
 * @brief The PrimitiveModel class
 */
class ModelRenderer :
public RendererInterface {
public:
    ModelRenderer(Model* model);
    void draw(GLenum s_mode, GLenum f_mode);
    void onPick();
private:
    void executeBehavior();

    Model* _model;

    bool _is_active;
};

}

#endif // PRIMITIVEMODEL_H
