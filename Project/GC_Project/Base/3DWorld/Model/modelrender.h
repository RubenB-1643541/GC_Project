#ifndef MODELRENDER_H
#define MODELRENDER_H

#include "modelloader.h"
#include "modeldata.h"
#include <QOpenGLWidget>
#include <QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QOpenGLFunctions>



class ModelRender : QOpenGLFunctions
{
public:
    ModelRender(QOpenGLWidget widget);
    void CreateShaderProgram();
    void ResizeGL();
    void CreateGeometry();

    void Draw();

private:
    void DrawMeshFromNode(const Node *node);
    void DrawNode(const QMatrix4x4 model, const Node *node, QMatrix4x4 parent);

    ModelLoader _loader;
    QMatrix4x4 _projection;
    QMatrix4x4 _view;
    QOpenGLShaderProgram _shaders;
    QOpenGLVertexArrayObject _vertrex_object;
    QOpenGLBuffer _vbo;
    QOpenGLBuffer _nbo;
    QOpenGLBuffer _ibo;
    GLsizei _cnt;
    QOpenGLWidget _widget;

};

#endif // MODELRENDER_H
