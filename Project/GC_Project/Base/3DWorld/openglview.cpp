#include "openglview.h"
#include "Model/modelrender.h"
#include <QDebug>

namespace __3DWorld__ {

////////////////////////////////////////////////////////
/// Construction
////////////////////////////////////////////////////////
OpenGLView::OpenGLView() : QOpenGLWidget() {
    // Timer for updating view
    _timer = new QTimer();
    connect(_timer, SIGNAL(timeout()), this, SLOT(update()));

    setFocusPolicy(Qt::StrongFocus);

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

    /// Todo
    /// - Shaders

    // enable
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat light_position [] = {0.1f, 0.1f, 0.1f, 0.1f};
    GLfloat light_diffuse []={ 1.0, 1.0, 1.0, 1.0 };
    glLightfv (GL_LIGHT0, GL_POSITION, light_position);
    glLightfv (GL_LIGHT0, GL_DIFFUSE, light_diffuse);

    glEnable(GL_DEPTH_TEST);

    // background color
    // 87CEEB
    glClearColor(0.53, 0.81, 0.92 ,1.0f);

    _timer->start(TIMER_INTERVAL);
    return;
}

void OpenGLView::resizeGL(int w, int h) {
    // Set viewport
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set perspective projection matrix
    gluPerspective(
        /* field of view */ 40.0,
        /* aspect ratio  */ (GLdouble)w/(GLdouble)h,
        /* near clipping */ 1.0,
        /* far clipping  */ 1000.0
    );

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    return;
}

void OpenGLView::paintGL() {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    // Update Camera
    updateCamera();

    // Draw Models
    for (ModelRender* renderer: _model_renderers) {
        renderer->Draw();
    }

    // begin Test
    // Draw Object
    GLfloat diff [] = { 0.7f , 0.5f , 0.0f };
    glMaterialfv (GL_FRONT, GL_DIFFUSE, diff);
    GLUquadricObj* quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluSphere(quadric, 3.0, 25, 25),
    gluDeleteQuadric(quadric);
    // end Test

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    return;
}

////////////////////////////////////////////////////////
/// Rending
////////////////////////////////////////////////////////
void OpenGLView::addModelRenderer(ModelRender *renderer) {
    _model_renderers.append(renderer);
    return;
}

////////////////////////////////////////////////////////
/// KeyEvents
////////////////////////////////////////////////////////
void OpenGLView::keyPressEvent(QKeyEvent* event) {
    if (event->isAutoRepeat()) { return; }
    else if (event->key() == Qt::Key_Up)     { _camera_key_handler->keyDown(CameraKeyHandler::Key::Rotate_Up); }
    else if (event->key() == Qt::Key_Down)   { _camera_key_handler->keyDown(CameraKeyHandler::Key::Rotate_Down); }
    else if (event->key() == Qt::Key_Left)   { _camera_key_handler->keyDown(CameraKeyHandler::Key::Rotate_Left); }
    else if (event->key() == Qt::Key_Right)  { _camera_key_handler->keyDown(CameraKeyHandler::Key::Rotate_Right); }
    else if (event->text() == 'a') { _camera_key_handler->keyDown(CameraKeyHandler::Key::Strafe_Up); }
    else if (event->text() == 'e') { _camera_key_handler->keyDown(CameraKeyHandler::Key::Strafe_Down); }
    else if (event->text() == 'z') { _camera_key_handler->keyDown(CameraKeyHandler::Key::Strafe_Forward); }
    else if (event->text() == 's') { _camera_key_handler->keyDown(CameraKeyHandler::Key::Strafe_Back); }
    else if (event->text() == 'q') { _camera_key_handler->keyDown(CameraKeyHandler::Key::Strafe_Left); }
    else if (event->text() == 'd') { _camera_key_handler->keyDown(CameraKeyHandler::Key::Strafe_Right); }
    else if (event->text() == 'l') { _headlamp->toggle(); }
    return;
}
void OpenGLView::keyReleaseEvent(QKeyEvent* event) {
    if (event->isAutoRepeat()) { return; }
    else if (event->key() == Qt::Key_Up)     { _camera_key_handler->keyUp(CameraKeyHandler::Key::Rotate_Up); }
    else if (event->key() == Qt::Key_Down)   { _camera_key_handler->keyUp(CameraKeyHandler::Key::Rotate_Down); }
    else if (event->key() == Qt::Key_Left)   { _camera_key_handler->keyUp(CameraKeyHandler::Key::Rotate_Left); }
    else if (event->key() == Qt::Key_Right)  { _camera_key_handler->keyUp(CameraKeyHandler::Key::Rotate_Right); }
    else if (event->text() == 'a') { _camera_key_handler->keyUp(CameraKeyHandler::Key::Strafe_Up); }
    else if (event->text() == 'e') { _camera_key_handler->keyUp(CameraKeyHandler::Key::Strafe_Down); }
    else if (event->text() == 'z') { _camera_key_handler->keyUp(CameraKeyHandler::Key::Strafe_Forward); }
    else if (event->text() == 's') { _camera_key_handler->keyUp(CameraKeyHandler::Key::Strafe_Back); }
    else if (event->text() == 'q') { _camera_key_handler->keyUp(CameraKeyHandler::Key::Strafe_Left); }
    else if (event->text() == 'd') { _camera_key_handler->keyUp(CameraKeyHandler::Key::Strafe_Right); }
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

