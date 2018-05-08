#ifndef ENITITYCREATOR_H
#define ENITITYCREATOR_H

#include "Entities/entitycollection.h"
#include "ModelData/ModelRenderer.h"
#include "openglview.h"
#include "Entities/spider.h"

#include "Texture.h"
#include "DisplayList.h"

#include <Windows.h>
#include <gl/GL.h>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
namespace __3DWorld__ {

class EntityCreator
{
public:
    EntityCreator(OpenGLView* view);
    EntityCreator(EntityCollection * collection, OpenGLView * view);

    bool loadData(std::string path);
private:
    void loadModels(QJsonArray array);
    void loadTextures(QJsonArray array);
    void loadEntities(QJsonArray array);

    void loadModel(QJsonObject obj);
    void loadTexture(QJsonObject obj);
    void loadEntity(QJsonObject obj);

    void loadEntityBehavior(QString behavior, Model * model);
    Point3D loadPosition(QJsonObject obj);
    Point3D loadRotationVec(QJsonObject obj);
    float loadRotationAngl(QJsonObject obj);

    std::vector<GLuint> _models;
    std::vector<GLuint> _textures;

    EntityCollection * _collection;
    OpenGLView * _view;
    QJsonObject _object;
};

}

#endif // ENITITYCREATOR_H
