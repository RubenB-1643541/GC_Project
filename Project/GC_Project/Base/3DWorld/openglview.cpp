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
    // Parent cal
    QOpenGLWidget::initializeGL();

    _timer->start(TIMER_INTERVAL);
    return;
}

void OpenGLView::resizeGL(int w, int h) {
    return;
}

void OpenGLView::paintGL() {
    glPushMatrix();
    glFrustum(0, this->width(), this->height(), 0, 20000, -10000); // Render plane

    // Update Camera
    _camera_key_handler->updateCamera();
    Point3D p = _camera->getPosition();
    Point3D l = _camera->getLooksAt();
    gluLookAt(
        p.x(), p.y(), p.z(),
        l.x(), l.y(), l.z(),
        0.0, 1.0, 0.0
    );
    _headlamp->setPosition(p);
    _headlamp->openGlRender(GL_LIGHT1);

    // Draw Models
    for (ModelRenderer* renderer: _model_renderers) {
        renderer->draw();
    }


    glPushMatrix();
    return;
}

////////////////////////////////////////////////////////
/// Rending
////////////////////////////////////////////////////////
void OpenGLView::addModelRenderer(ModelRenderer *renderer) {
    _model_renderers.append(renderer);
    return;
}

////////////////////////////////////////////////////////
/// KeyEvents
////////////////////////////////////////////////////////
void OpenGLView::keyPressEvent(QKeyEvent* event) {
    return;
}
void OpenGLView::keyReleaseEvent(QKeyEvent* event) {
    return;
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
    return;
}

}

