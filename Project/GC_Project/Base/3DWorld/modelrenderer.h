#ifndef MODELRENDERER_H
#define MODELRENDERER_H

#include <C:/Users/super/Documents/ComputerGraphics/Project/GC_Project/Project/GC_Project/Project_GC/modelloader.h>

#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>


#include


class ModelRenderer
{
public:
    ModelRenderer();
    void LoadModel(String path);
    void Draw();


private:
    void DrawMeshFromNode(const Node *node);
    void CreateShaderProgram();
    void ResizeGL();
    void CreateGeometry();
    void DrawNode(const QMatrix4x4 model, const Node *node, QMatrix4x4 parent);

    ModelLoader _loader;
    QMatrix4x4 _projection;
    QMatrix4x4 _view;
    QOpenGLShaderProgram _shaders;
    QOpenGLVertexArrayObject _vertrex_object;
    QOpenGLBuffer _vbo;
    QOpenGLBuffer _nbo;
    QOpenGLBuffer _ibo;
    GLsizei _cnt;    ModelRenderer();
};

#endif // MODELRENDERER_H
