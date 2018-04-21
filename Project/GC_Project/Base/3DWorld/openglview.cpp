#include "openglview.h"

namespace __3DWorld__ {

////////////////////////////////////////////////////////
/// Construction
////////////////////////////////////////////////////////
OpenGLView::OpenGLView() {
    // Timer for updating view
    _timer = new QTimer();
    connect(_timer, SIGNAL(timeout()), this, SLOT(update()));

    // Camera
    _camera = new Camera();
    _camera_key_handler = new CameraKeyHandler(_camera);
    _headlamp = new HeadLamp();

    return;
}

////////////////////////////////////////////////////////
/// QOpenGLWidget reimplementations
////////////////////////////////////////////////////////
void OpenGLView::initializeGL() {
    return;
}

void OpenGLView::resizeGL(int w, int h) {
    return;
}

void OpenGLView::paintGL() {
    return;
}

////////////////////////////////////////////////////////
/// KeyEvents
////////////////////////////////////////////////////////
void OpenGLView::keyPressEvent(QKeyEvent* event) {

}
void OpenGLView::keyReleaseEvent(QKeyEvent* event) {

}

////////////////////////////////////////////////////////
/// Update
////////////////////////////////////////////////////////
void OpenGLView::updateCamera() {
    _camera_key_handler->updateCamera();
    Point3D p = _camera->getPosition();
    Point3D l = _camera->getLooksAt();
    gluLookAt(
        p.x(), p.y(), p.z(),
        l.x(), l.y(), l.z(),
        0.0, 0.1, 0.0
    );
    _headlamp->setPosition(p);
    _headlamp->openGlRender(GL_LIGHT1);
}

}

