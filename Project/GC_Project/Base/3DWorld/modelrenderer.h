#ifndef MODELRENDERER_H
#define MODELRENDERER_H

#include "model.h"

namespace __3DWorld__ {

enum class ShaderType {

};

class ModelRenderer {
public:
    ModelRenderer();

    void draw();
    void setShaderType(ShaderType shader);
private:
    Model* _model;
};

}

#endif // MODELRENDERER_H
