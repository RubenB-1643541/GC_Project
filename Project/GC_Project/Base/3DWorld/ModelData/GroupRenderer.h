#ifndef GROUPRENDERER_H
#define GROUPRENDERER_H

#include "RendererInterface.h"
#include "ModelRenderer.h"
#include "ModelGroup.h"

#include <windows.h>
#include <gl/GL.h>

namespace __3DWorld__ {

/**
 * @author Wald Habets
 * @brief The GroupRenderer class
 */
class GroupRenderer :
public RendererInterface {
public:
    GroupRenderer(ModelGroup* group);
    void draw(GLenum s_mode, GLenum f_mode);
    void addModelRenderer(ModelRenderer* model_renderer);
private:
    ModelGroup* _group;
    std::vector<ModelRenderer*> _model_renderers;
};

}

#endif // GROUPRENDERER_H
