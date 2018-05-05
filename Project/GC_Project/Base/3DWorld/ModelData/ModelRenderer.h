#ifndef MODEL_RENDER
#define MODEL_RENDER

#include "ModelData/Model.h"
#include "ModelData/ModelObject.h"

namespace __3DWorld__ {

/**
 * @author Wald Habets
 * @brief
 */



class ModelRenderer {
public:
    ModelRenderer();
    ModelRenderer(ModelObject * model);
    void setModelObj(ModelObject * model);
    void draw(ShadingMode s_mode, FrameMode f_mode);

private:
    Model * _model = NULL;
};
}

#endif MODEL_RENDER
