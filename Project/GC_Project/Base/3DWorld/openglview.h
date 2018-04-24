#ifndef OPENGLVIEW_H
#define OPENGLVIEW_H

#include <QOpenGLWidget>
#include <QTimer>
#include <gl/GL.h>
#include <gl/GLU.h>

#include "Camera.h"
#include "CameraKeyHandler.h"
#include "HeadLamp.h"

namespace __3DWorld__ {

/**
 * @author Wald Habets
 * @brief The OpenGLView class
 */
class OpenGLView : public QOpenGLWidget {
public:
    ////////////////////////////////////////////////////////
    /// Construction
    ////////////////////////////////////////////////////////
    OpenGLView();

    ////////////////////////////////////////////////////////
    /// QOpenGLWidget reimplementations
    ////////////////////////////////////////////////////////
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    ////////////////////////////////////////////////////////
    /// KeyEvents
    ////////////////////////////////////////////////////////
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
private:
    ////////////////////////////////////////////////////////
    /// Update
    ////////////////////////////////////////////////////////
    void updateCamera();

    QTimer* _timer;

    Camera* _camera;
    CameraKeyHandler* _camera_key_handler;
    HeadLamp* _headlamp;
};

}

#endif // OPENGLVIEW_H
