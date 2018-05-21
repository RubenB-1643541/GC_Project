#include "entitycollection.h"

namespace __3DWorld__ {


EntityCollection::EntityCollection()
{
    _entities = new QVector<Entity *>;
}

void EntityCollection::AddEntity(Entity *entity) {
    _entities->push_back(entity);
}

void EntityCollection::UpdateEntities() {

    for(int i = 0; i < _entities->size(); ++i) {
        _entities->at(i)->update();
    }
}

}
