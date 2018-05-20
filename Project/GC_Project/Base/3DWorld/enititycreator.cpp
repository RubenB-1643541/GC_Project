#include "enititycreator.h"
#include "openglview.h"
#include "Texture.h"

namespace __3DWorld__ {

EntityCreator::EntityCreator(OpenGLView *view) {
    _collection = nullptr;
    _view = view;
}

EntityCreator::EntityCreator(EntityCollection * collection, OpenGLView * view) {
    _collection = collection;
    _view = view;
}

bool EntityCreator::loadData(std::string path) {
    // "WorldData/WorldData.json"
    QFile file(path.c_str());
    if(!file.open(QIODevice::ReadOnly)) {
        qWarning("Data could not be loaded");
        return false;
    }

    QByteArray saveData = file.readAll();
    QJsonDocument document = QJsonDocument::fromJson(saveData);
    _object = document.object();

    if (_object.contains("models") && _object["models"].isArray()) {
        loadModels(_object["models"].toArray());
    } else {
        qDebug() << "Error: could not load models";
    }

    if (_object.contains("textures") && _object["textures"].isArray()) {
        loadTextures(_object["textures"].toArray());
    } else {
        qDebug() << "Error: could not load textures";
    }

    if (_object.contains("groups") && _object["groups"].isArray()) {
        loadGroups(_object["groups"].toArray());
    } else {
        qDebug() << "Error: could not load groups";
    }

    if (_object.contains("entities") && _object["entities"].isArray()) {
        loadEntities(_object["entities"].toArray());
    } else {
        qDebug() << "Error: could not load entities";
    }
}

void EntityCreator::loadModels(QJsonArray array) {
    _models.resize(array.size());
    qDebug() << _models.size();
    for(int i = 0; i < array.size(); i++) {
        loadModel(array.at(i).toObject());
    }
}
void EntityCreator::loadModel(QJsonObject obj) {
    if (obj["id"].toInt() < _models.size()) {
        _models[obj["id"].toInt()] = DisplayList::create(obj["path"].toString().toStdString());
    }
}

void EntityCreator::loadTextures(QJsonArray array) {
    _textures.resize(array.size());
    for(int i = 0; i < array.size(); i++) {
        loadTexture(array.at(i).toObject());
    }
}

void EntityCreator::loadTexture(QJsonObject obj) {
    if (obj["id"].toInt() < _models.size()) {
        _textures[obj["id"].toInt()] = Texture::create(obj["path"].toString().toStdString());
    }
}

void EntityCreator::loadGroups(QJsonArray array) {
    qDebug() << "Group size" << array.size();
    _groups.resize(array.size());
    for (int i = 0; i < array.size(); i++) {
        loadGroup(array.at(i).toObject());
    }
}

void EntityCreator::loadGroup(QJsonObject obj) {
    ModelGroup* group = new ModelGroup();

    group->translate(
        loadPosition(obj["position"].toObject())
    );
    group->rotate(
        loadRotationAngl(obj["rotation"].toObject()),
        loadRotationVec(obj["rotation"].toObject())
    );
    group->scale(
        obj["size"].toDouble()
    );

    GroupRenderer* group_renderer = new GroupRenderer(group);
    qDebug() << "LoadGroup:" << obj["group_id"].toInt();
    _groups[obj["id"].toInt()] = group_renderer;
    _view->addModelRenderer(group_renderer);
}

void EntityCreator::loadEntities(QJsonArray array) {
    for(int i = 0; i < array.size() ; ++i) {
        loadEntity(array.at(i).toObject());
    }
}

void EntityCreator::loadEntity(QJsonObject obj) {
    // Get model
    GLuint model   = _models[obj["model_id"].toInt()];

    Model* entity;
    if (obj["texture_id"].toInt() > -1) {
        GLuint texture = _textures[obj["texture_id"].toInt()];
        entity = new Model(model, texture);
    } else {
        entity = new Model(model);
    }

    // Set Tranformation info
    entity->translate(
        loadPosition(obj["position"].toObject())
    );
    entity->rotate(
        loadRotationAngl(obj["rotation"].toObject()),
        loadRotationVec(obj["rotation"].toObject())
    );
    entity->scale(
        obj["size"].toDouble()
    );

    if (obj.contains("group_id")) {
        qDebug() << "LoadEntity:" << obj["group_id"].toInt();
        _groups[obj["group_id"].toInt()]->addModelRenderer(new ModelRenderer(entity));
    } else {
        _view->addModelRenderer(new ModelRenderer(entity));
    }

    if(_collection != nullptr && obj.contains("behavior")) {
        loadEntityBehavior(obj["behavior"].toString(), entity);
    }

}

void EntityCreator::loadEntityBehavior(QString behavior, Model * model) {
    ModelEntity * entity;
    if(behavior == "Spider") {
        entity = new Spider(model);
    }
    else if(behavior == "Thwomp") {
        entity = new Thwomp(model);
    }
    else if(behavior == "Star") {
        entity = new Star(model);
    }
    _collection->AddEntity(entity);
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
