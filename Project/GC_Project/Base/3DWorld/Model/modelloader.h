#ifndef MODELLOADER_H
#define MODELLOADER_H

#include "modelobject.h"
#include <QString>
#include <QVector>
#include <QMatrix4x4>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/Importer.hpp>

#include "Point3D.h"

namespace __3DWorld__ {

struct MLVertex {
    Point3D position;
};
struct MLMesh {
    unsigned int num_vertices;
    std::vector<MLVertex> vertices;
};

class ModelLoader
{
public:
    ModelLoader();
    void load(std::string path);
    std::vector<MLMesh> getMeshes() { return _meshes; }
private:
    /*  Model Data  */
    std::vector<MLMesh> _meshes;
    /*  Functions   */
    void loadModel(std::string path);
    void processNode(aiNode *node, const aiScene *scene);
    MLMesh processMesh(aiMesh *mesh, const aiScene *scene);
};

}

#endif // MODELLOADER_H
