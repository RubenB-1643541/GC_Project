#ifndef OPENGLVIEW_H
#define OPENGLVIEW_H

#include <QOpenGLWidget>
#include <QTimer>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <QKeyEvent>

#include "Camera.h"
#include "CameraKeyHandler.h"
#include "CameraMouseHandler.h"
#include "HeadLamp.h"
#include "Model/modelrender.h"
#include "PrimitiveModel.h"

namespace __3DWorld__ {

/**
 * @author Wald Habets
 * @brief The OpenGLView class
 */
class OpenGLView : public QOpenGLWidget {
    Q_OBJECT
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
    /// Rendering
    ////////////////////////////////////////////////////////
    void addModelRenderer(ModelRender* renderer);

    ////////////////////////////////////////////////////////
    /// KeyEvents
    ////////////////////////////////////////////////////////
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void mouseMoveEvent(QMouseEvent *event);
signals:
    void escapePressed();
private:
    ////////////////////////////////////////////////////////
    /// Update
    ////////////////////////////////////////////////////////
    void updateCamera();

    ////////////////////////////////////////////////////////
    /// Member Variables
    ////////////////////////////////////////////////////////
    QTimer* _timer;

    Camera* _camera;
    QPoint _prev_mouse_pos;
    int _mouse_dx, _mouse_dy;
    CameraKeyHandler* _camera_key_handler;
    CameraMouseHandler* _camera_mouse_handler;
    HeadLamp* _headlamp;

    QVector<ModelRender *> _model_renderers;

    ////////////////////////////////////////////////////////
    /// Static
    ////////////////////////////////////////////////////////
    static const int TIMER_INTERVAL = 16;
};

}

#endif // OPENGLVIEW_H
