#ifndef SPIDER_H
#define SPIDER_H

#include "ModelData/modelentity.h"

namespace __3DWorld__ {

class Spider : public ModelEntity {
public:
    Spider(Model * model);
    void update();

private:
    int _timer;


};


}



#endif // MODELENTITY_H
