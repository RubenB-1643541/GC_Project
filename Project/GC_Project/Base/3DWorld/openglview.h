#ifndef OPENGLVIEW_H
#define OPENGLVIEW_H

#include <QOpenGLWidget>
#include <QTimer>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <QKeyEvent>
#include <QOpenGLContext>

#include "Camera.h"
#include "CameraKeyHandler.h"
#include "CameraMouseHandler.h"
#include "HeadLamp.h"
#include "ModelData/RendererInterface.h"
#include "Settings.h"
#include "mvc.hpp"
#include "DisplayList.h"
#include "Texture.h"
#include "picking.h"
#include "Entities/entitycollection.h"

namespace __3DWorld__ {

/**
 * @author Wald Habets
 * @brief The OpenGLView class
 */
class EntityCreator;

class OpenGLView :
public QOpenGLWidget,
public ViewInterface {
    Q_OBJECT
public:
    ////////////////////////////////////////////////////////
    /// Construction
    ////////////////////////////////////////////////////////
    OpenGLView(Settings* settings);

    ////////////////////////////////////////////////////////
    /// QOpenGLWidget reimplementations
    ////////////////////////////////////////////////////////
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    ////////////////////////////////////////////////////////
    /// Rendering
    ////////////////////////////////////////////////////////
    void addModelRenderer(RendererInterface* renderer);

    ////////////////////////////////////////////////////////
    /// KeyEvents
    ////////////////////////////////////////////////////////
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent * event);

    ////////////////////////////////////////////////////////
    /// settings
    ////////////////////////////////////////////////////////
    void update();
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
    Settings* _settings;
    GLenum _shading_mode;
    GLenum _render_mode;

    Camera* _camera;
    QPoint _prev_mouse_pos;
    int _mouse_dx, _mouse_dy;
    CameraKeyHandler* _camera_key_handler;
    CameraMouseHandler* _camera_mouse_handler;
    HeadLamp* _headlamp;

    std::vector<RendererInterface*> _model_renderers;
    EntityCollection * _entities;

    EntityCreator* _creator;

    bool _global_light;
    bool _picking = false;

    Picking * _picker;

    ////////////////////////////////////////////////////////
    /// Static
    ////////////////////////////////////////////////////////
    static const int TIMER_INTERVAL = 16;

};

}

#endif // OPENGLVIEW_H
