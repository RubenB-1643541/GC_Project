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

class ModelRender : QOpenGLFunctions
{
public:
    ModelRender(QOpenGLWidget * widget);
    void Draw(QMatrix4x4 cam_view);
    void SetModel(ModelObject * obj) {_obj = obj;}
    void LoadModel(QString path);
    void Initialize();
    void Paint(QMatrix4x4 cam_view);
    void Resize(int w, int h);

private:
    void DrawMeshFromNode(const Node *node);
    void DrawNode(QMatrix4x4 cam_view, const QMatrix4x4 model, const Node *node, QMatrix4x4 parent);
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
