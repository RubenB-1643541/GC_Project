#ifndef MODELRENDER_H
#define MODELRENDER_H

#include "modelloader.h"
#include "modeldata.h"
#include "shaders.h"
#include "Point3D.h"
#include <QOpenGLWidget>
#include <QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>

#include <soil/Simple OpenGL Image Library/src/SOIL.h>

//http://ogldev.atspace.co.uk/www/tutorial22/tutorial22.html

namespace __3DWorld__ {

class ModelRender : QOpenGLFunctions
{
public:
    ModelRender();
    void Draw();
    void SetModel(ModelObject * obj) {_obj = obj;}
    void LoadModel(QString path);
    void LoadModel(QString path, Point3D * position);
    void LoadModel(QString path, Point3D * position, Point3D * rotation);
    void LoadModel(QString path, Point3D * position, Point3D * rotation, float size);
    void Initialize();
    void Paint();
    void Resize(int w, int h);
    void SetView(Point3D lookat, Point3D position);

private:
    void DrawMeshFromNode(const Node *node);
    void DrawNode(const QMatrix4x4 model, const Node *node, QMatrix4x4 parent);
    void CreateShaderProgram();
    void ResizeGL();
    void CreateGeometry();
    void InitializeTextures();

    ModelLoader _loader;
    QMatrix4x4 _projection;
    QMatrix4x4 _view;
    QOpenGLShaderProgram _shaders;
    QOpenGLVertexArrayObject _vertrex_object;
    QOpenGLBuffer _vbo;
    QOpenGLBuffer _nbo;
    QOpenGLBuffer _ibo;
    GLsizei _cnt;
    ModelObject * _obj;
    GLuint _texture;

};

}

#endif // MODELRENDER_H
