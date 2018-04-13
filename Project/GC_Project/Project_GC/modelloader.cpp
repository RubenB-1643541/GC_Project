#include "modelloader.h"

ModelLoader::ModelLoader()
{

}

bool ModelLoader::Load(QString pathToFile) {
    Assimp::Importer importer;
    const aiScene * scene = importer.ReadFile(pathToFile.toStdString(),
                                              aiProcess_GenSmoothNormals |
                                              aiProcess_CalcTangentSpace |
                                              aiProcess_Triangulate |
                                              aiProcess_JoinIdenticalVertices |
                                              aiProcess_SortByPType
                                              );
    if(!scene) {
        qDebug() << "Error loading file: (assimp:) " << importer.GetErrorString();
        return false;
    }

    //Load Materials
    if(scene->HasMaterials()) {
        for(int i = 0; i < scene->mNumMaterials; ++i) {
            QSharedPointer<MaterialInfo> mater = ProcessMaterial(scene->mMaterials[i]);
            m_materials.push_back(mater);
        }
    }

    //Loading Meshes
    if (scene->HasMeshes())
    {
        for (int i = 0; i < scene->mNumMeshes; ++i)
        {
            m_meshes.push_back(ProcessMesh(scene->mMeshes[i]));
        }
    }
    else
    {
        qDebug() << "Error: No meshes found";
        return false;
    }
    //Loading Nodes
    if (scene->mRootNode != NULL)
    {
        Node *rootNode = new Node;
        ProcessNode(scene, scene->mRootNode, 0, *rootNode);
        m_rootNode.reset(rootNode);
    }
    else
    {
        qDebug() << "Error loading model";
        return false;
    }

    return true;

}

void ModelLoader::GetBufferData(QVector<float> **vertices, QVector<float> **normals, QVector<unsigned int> **indices) {
    *vertices = &m_vertices;
    *normals = &m_normals;
    *indices = &m_indices;
}

QSharedPointer<MaterialInfo> ModelLoader::ProcessMaterial(aiMaterial * material) {
    QSharedPointer<MaterialInfo> mater(new MaterialInfo);

    aiString mname;
    material->Get(AI_MATKEY_NAME, mname);
    if (mname.length > 0)
        mater->name = mname.C_Str();

    int shadingModel;
    material->Get(AI_MATKEY_SHADING_MODEL, shadingModel);

    if (shadingModel != aiShadingMode_Phong && shadingModel != aiShadingMode_Gouraud)
    {
        qDebug() << "This mesh's shading model is not implemented in this loader, setting to default material";
        mater->name = "DefaultMaterial";
    }
    else
    {
        aiColor3D dif(0.f,0.f,0.f);
        aiColor3D amb(0.f,0.f,0.f);
        aiColor3D spec(0.f,0.f,0.f);
        float shine = 0.0;

        material->Get(AI_MATKEY_COLOR_AMBIENT, amb);
        material->Get(AI_MATKEY_COLOR_DIFFUSE, dif);
        material->Get(AI_MATKEY_COLOR_SPECULAR, spec);
        material->Get(AI_MATKEY_SHININESS, shine);

        mater->ambient = QVector3D(amb.r, amb.g, amb.b);
        mater->diffuse = QVector3D(dif.r, dif.g, dif.b);
        mater->specular = QVector3D(spec.r, spec.g, spec.b);
        mater->shininess = shine;

        mater->ambient *= .2;
        if (mater->shininess == 0.0)
            mater->shininess = 30;
    }
    return mater;
}

QSharedPointer<Mesh> ModelLoader::ProcessMesh(aiMesh *mesh)
{
    QSharedPointer<Mesh> newMesh(new Mesh);
    newMesh->name = mesh->mName.length != 0 ? mesh->mName.C_Str() : "";
    newMesh->indexOffset = m_indices.size();
    unsigned int indexCountBefore = m_indices.size();
    int vertindexoffset = m_vertices.size()/3;

    // Get Vertices
    if (mesh->mNumVertices > 0)
    {
        for (uint i = 0; i < mesh->mNumVertices; ++i)
        {
            aiVector3D &vec = mesh->mVertices[i];

            m_vertices.push_back(vec.x);
            m_vertices.push_back(vec.y);
            m_vertices.push_back(vec.z);
        }
    }

    // Get Normals
    if (mesh->HasNormals())
    {
        for (uint i = 0; i < mesh->mNumVertices; ++i)
        {
            aiVector3D &vec = mesh->mNormals[i];
            m_normals.push_back(vec.x);
            m_normals.push_back(vec.y);
            m_normals.push_back(vec.z);
        };
    }

    // Get mesh indexes
    for (uint t = 0; t < mesh->mNumFaces; ++t)
    {
        aiFace* face = &mesh->mFaces[t];
        if (face->mNumIndices != 3)
        {
            qDebug() << "Warning: Mesh face with not exactly 3 indices, ignoring this primitive.";
            continue;
        }

        m_indices.push_back(face->mIndices[0]+vertindexoffset);
        m_indices.push_back(face->mIndices[1]+vertindexoffset);
        m_indices.push_back(face->mIndices[2]+vertindexoffset);
    }

    newMesh->indexCount = m_indices.size() - indexCountBefore;
    newMesh->material = m_materials.at(mesh->mMaterialIndex);

    return newMesh;
}

void ModelLoader::ProcessNode(const aiScene *scene, aiNode *node, Node *parentNode, Node &newNode)
{
    newNode.name = node->mName.length != 0 ? node->mName.C_Str() : "";

    newNode.transformation = QMatrix4x4(node->mTransformation[0]);

    newNode.meshes.resize(node->mNumMeshes);
    for (uint imesh = 0; imesh < node->mNumMeshes; ++imesh)
    {
        QSharedPointer<Mesh> mesh = m_meshes[node->mMeshes[imesh]];
        newNode.meshes[imesh] = mesh;
    }

    for (uint ich = 0; ich < node->mNumChildren; ++ich)
    {
        newNode.nodes.push_back(Node());
        ProcessNode(scene, node->mChildren[ich], parentNode, newNode.nodes[ich]);
    }
}
