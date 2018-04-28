#ifndef MODELRENDER_H
#define MODELRENDER_H

#include "modelloader.h"
#include "modeldata.h"
#include "shaders.h"
#include <QOpenGLWidget>
#include <QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>
#include "openglview.h"



class ModelRender : QOpenGLFunctions
{
public:
    ModelRender(QOpenGLWidget * widget);
    void Draw();
    void SetModel(ModelObject * obj) {_obj = obj;}
    void LoadModel(QString path);
    void Initialize();
    void Paint();
    void Resize(int w, int h);

private:
    void DrawMeshFromNode(const Node *node);
    void DrawNode(const QMatrix4x4 model, const Node *node, QMatrix4x4 parent);
    void CreateShaderProgram();
    void ResizeGL();
    void CreateGeometry();

    ModelLoader _loader;
    QMatrix4x4 _projection;
    QMatrix4x4 _view;
    QOpenGLShaderProgram _shaders;
    QOpenGLVertexArrayObject _vertrex_object;
    QOpenGLBuffer _vbo;
    QOpenGLBuffer _nbo;
    QOpenGLBuffer _ibo;
    GLsizei _cnt;
    QOpenGLWidget * _widget;
    ModelObject * _obj;

};

#endif // MODELRENDER_H
