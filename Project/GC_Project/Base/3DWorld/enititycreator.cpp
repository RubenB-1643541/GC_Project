#include "enititycreator.h"
#include "openglview.h"

namespace __3DWorld__ {



EntityCreator::EntityCreator(EntityCollection * collection, OpenGLView * view)
{
    _collection = collection;
    _view = view;

    createOverWordl();
    createSpider();
}

void EntityCreator::createOverWordl() {
    ModelObject * overworld_model = new ModelObject("Models/Bobomb/bobomb battlefeild.obj");
    ModelRenderer * overworld_renderer = new ModelRenderer(overworld_model);
    _view->addModelRenderer(overworld_renderer);

}

void EntityCreator::createSpider() {
    ModelObject * spider_model_obj = new ModelObject("Models/Spider/spider.obj");
    Model * spider_model = new Model(spider_model_obj, TYPE::DYNAMIC);
    spider_model->scale(0.1);
    ModelRenderer * spider_renderer = new ModelRenderer(spider_model);
    _view->addModelRenderer(spider_renderer);

    Spider * spider_entity = new Spider(spider_model);
    _collection->AddEntity(spider_entity);
}

}
