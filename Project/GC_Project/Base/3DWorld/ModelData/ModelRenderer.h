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
    ModelRenderer(Model * model);
    void setModelObj(ModelObject * model);
    void draw(GLenum s_mode, GLenum f_mode);
    void move(Point3D point) {_model->move(point);}
    void drawModel();
    void executePicking();

private:
    Model * _model = NULL;
};
}

#endif MODEL_RENDER
