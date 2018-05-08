#include "enititycreator.h"
#include "openglview.h"

namespace __3DWorld__ {



EntityCreator::EntityCreator(EntityCollection * collection, OpenGLView * view)
{
    _collection = collection;
    _view = view;

    //createOverWordl();
    //createSpider();
    loadData();
}

bool EntityCreator::loadData() {
    QFile file("WorldData/WorldData.json");
    if(!file.open(QIODevice::ReadOnly)) {
        qWarning("Data could not be loaded");
        return false;
    }
    QByteArray saveData = file.readAll();
    QJsonDocument document = QJsonDocument::fromJson(saveData);
    _object = document.object();
    loadOverWorld(_object["over_world"].toObject());
    if(_object.contains("entities") && _object["entities"].isArray())
        loadEntities(_object["entities"].toArray());
}

void EntityCreator::createOverWordl() {
    ModelObject * overworld_model = new ModelObject("Models/Bobomb/bobomb battlefeild.obj");
    ModelRenderer * overworld_renderer = new ModelRenderer(overworld_model);
    _view->addModelRenderer(overworld_renderer);

}

void EntityCreator::createSpider() {
    ModelObject * spider_model_obj = new ModelObject("Models/Spider/spider.obj");
    Model * spider_model = new Model(spider_model_obj, TYPE::DYNAMIC);
    spider_model->scale(0.05);
    spider_model->rotate(180, Point3D(0, 1, 0));
    spider_model->move(Point3D(21, 25.5, 7));
    ModelRenderer * spider_renderer = new ModelRenderer(spider_model);
    _view->addModelRenderer(spider_renderer);

    Spider * spider_entity = new Spider(spider_model);
    _collection->AddEntity(spider_entity);
}

void EntityCreator::loadOverWorld(QJsonObject obj) {
    ModelObject * overworld_obj = new ModelObject(obj["data"].toString());
    Model * overworld_model = new Model(overworld_obj, TYPE::STATIC);
    overworld_model->move(loadPosition(obj["position"].toObject()));
    overworld_model->scale(obj["size"].toDouble());
    overworld_model->rotate(loadRotationAngl(obj["rotation"].toObject()), loadRotationVec(obj["rotation"].toObject()));
    ModelRenderer * overworld_renderer = new ModelRenderer(overworld_model);
    _view->addModelRenderer(overworld_renderer);
}

void EntityCreator::loadEntities(QJsonArray array) {
    for(int i = 0; i < array.size() ; ++i) {
        loadEntity(array.at(i).toObject());
    }
}

void EntityCreator::loadEntity(QJsonObject obj) {
    ModelObject * entity_model_obj = new ModelObject(obj["data"].toString());
    Model * entity_model = new Model(entity_model_obj, TYPE::DYNAMIC);
    entity_model->scale(obj["size"].toDouble());
    entity_model->rotate(loadRotationAngl(obj["rotation"].toObject()), loadRotationVec(obj["rotation"].toObject()));
    entity_model->move(loadPosition(obj["position"].toObject()));
    ModelRenderer * entity_renderer = new ModelRenderer(entity_model);
    _view->addModelRenderer(entity_renderer);

    loadEntityBehavior(obj["behavior"].toString(), entity_model);
}

void EntityCreator::loadEntityBehavior(QString behavior, Model *model) {
    if(behavior == "Spider") {
        Spider * spider_entity = new Spider(model);
        _collection->AddEntity(spider_entity);
    }
    else if(behavior == "Thwomp") {
        Thwomp * thwomp_entity = new Thwomp(model);
        _collection->AddEntity(thwomp_entity);
    }
}

Point3D EntityCreator::loadPosition(QJsonObject obj) {
    Point3D pos;
    pos.setX(obj["x"].toDouble());
    pos.setY(obj["y"].toDouble());
    pos.setZ(obj["z"].toDouble());
    return pos;
}

Point3D EntityCreator::loadRotationVec(QJsonObject obj) {
    Point3D rot;
    rot.setX(obj["x"].toDouble());
    rot.setY(obj["y"].toDouble());
    rot.setZ(obj["z"].toDouble());
    return rot;
}

float EntityCreator::loadRotationAngl(QJsonObject obj) {
    return obj["angle"].toDouble();
}

}
