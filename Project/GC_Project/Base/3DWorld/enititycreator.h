#ifndef ENITITYCREATOR_H
#define ENITITYCREATOR_H

#include "Entities/entitycollection.h"
#include "ModelData/ModelRenderer.h"
#include "openglview.h"
#include "Entities/spider.h"
namespace __3DWorld__ {



class EntityCreator
{
public:
    EntityCreator(EntityCollection * collection, OpenGLView * view);

private:
    void createSpider();
    void createOverWordl();
    EntityCollection * _collection;
    OpenGLView * _view;

};

}

#endif // ENITITYCREATOR_H
