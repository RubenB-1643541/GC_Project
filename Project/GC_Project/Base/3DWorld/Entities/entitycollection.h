#ifndef ENTITYCOLLECTION_H
#define ENTITYCOLLECTION_H

#include "ModelData/modelentity.h"
#include "ModelData/entity.h"
#include <QVector>

namespace __3DWorld__ {



class EntityCollection
{
public:
    EntityCollection();
    void AddEntity(Entity * entity);
    void UpdateEntities();

private:
    QVector<Entity *> * _entities = NULL;
};

}
#endif // ENTITYCOLLECTION_H
