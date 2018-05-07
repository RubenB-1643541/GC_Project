#ifndef ENITITYCREATOR_H
#define ENITITYCREATOR_H

#include "Entities/entitycollection.h"
#include "ModelData/ModelRenderer.h"
#include "openglview.h"
#include "Entities/spider.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
namespace __3DWorld__ {



class EntityCreator
{
public:
    EntityCreator(EntityCollection * collection, OpenGLView * view);

private:
    bool loadData();
    void createSpider();
    void createOverWordl();
    void loadOverWorld(QJsonObject obj);
    void loadEntities(QJsonArray array);
    void loadEntity(QJsonObject obj);
    void loadEntityBehavior(QString behavior, Model * model);
    Point3D loadPosition(QJsonObject obj);
    Point3D loadRotationVec(QJsonObject obj);
    float loadRotationAngl(QJsonObject obj);

    EntityCollection * _collection;
    OpenGLView * _view;
    QJsonObject _object;
};

}

#endif // ENITITYCREATOR_H
