#ifndef ENTITYCOLLECTION_H
#define ENTITYCOLLECTION_H

#include "ModelData/modelentity.h"
#include <QVector>

namespace __3DWorld__ {



class EntityCollection
{
public:
    EntityCollection();
    void AddEntity(ModelEntity * entity);
    void UpdateEntities();

private:
    QVector<ModelEntity *> * _entities = NULL;
};

}
#endif // ENTITYCOLLECTION_H
