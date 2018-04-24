#ifndef MODEL_H
#define MODEL_H

#include "modelobject.h"

namespace __3DWorld__ {

/**
 * @brief The Model class
 * Deze klasse houdt de positie, rotatie etc bij van een modelobject samen met een pointer naar het modelobject dat gerenderd moet worden
 */
class Model {
public:
    Model();

    void setModelObject(ModelObject* model_object);

private:
    ModelObject* _model_object;

};

}

#endif // MODEL_H
