#include "openglview.h"
#include <QDebug>

namespace __3DWorld__ {

////////////////////////////////////////////////////////
/// Construction
////////////////////////////////////////////////////////
OpenGLView::OpenGLView() : QOpenGLWidget() {
    this->setMouseTracking(true);
    this->setCursor(Qt::BlankCursor);

    // Timer for updating view
    _timer = new QTimer();
    connect(_timer, SIGNAL(timeout()), this, SLOT(update()));

    setFocusPolicy(Qt::StrongFocus);

    // Camera
    _camera = new Camera();
    _mouse_dx = 0;
    _mouse_dy = 0;
    _camera_key_handler = new CameraKeyHandler(_camera);
    _camera_mouse_handler = new CameraMouseHandler(_camera);
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
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
    glEnable(GL_LIGHT0);

    // Global lighting
    //*
    GLfloat global_ambient[] = { 0.4, 0.4, 0.4, 1 };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

    GLfloat diffuse[] = { 1, 1, 1, 1 };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    GLfloat light_position[] = { 1, 1, 1, 1 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_DEPTH_TEST);

    // background color
    // 87CEEB
    glClearColor(0.53, 0.81, 0.92 ,1.0f);


    //for (ModelRender* renderer: _model_renderers) {
        //renderer->SetView(_camera->getLooksAt(), _camera->getPosition());
        //renderer->Initialize();
    //}


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
    //for (ModelRender* renderer: _model_renderers) {
        //renderer->Resize(w, h);
    //}
    _model_renderers.at(0)->move(Point3D(0, -40, 0));

    return;
}

void OpenGLView::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();

    // Update Camera
    updateCamera();

    // begin Test
    /*
    glPushMatrix();

    GLfloat diffuse[] = {0.54f, 0.89f, 0.63f, 1.0f};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);

    glShadeModel(GL_SMOOTH);
    // */
    // Draw Object
    /*
    GLfloat diff [] = { 0.7f , 0.5f , 0.0f };
    glMaterialfv (GL_FRONT, GL_DIFFUSE, diff);
    // */
    /*
    GLUquadricObj* quadric = gluNewQuadric();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    //gluQuadricDrawStyle(quadric, GLU_FILL);
    gluSphere(quadric, 3.0, 25, 25),
    gluDeleteQuadric(quadric);

    glPopMatrix();
    // */
    // end Test

    for(ModelRenderer * renderer : _model_renderers) {
        renderer->draw(ShadingMode::SMOOTH, FrameMode::FILL);
    }

    //PrimitiveModel model;
    //model.draw(ShadingMode::SMOOTH, FrameMode::FILL);

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    return;
}

////////////////////////////////////////////////////////
/// Rending
////////////////////////////////////////////////////////

void OpenGLView::addModelRenderer(ModelRenderer *renderer) {
    _model_renderers.append(renderer);
}

////////////////////////////////////////////////////////
/// KeyEvents
////////////////////////////////////////////////////////
void OpenGLView::keyPressEvent(QKeyEvent* event) {
    // Todo change shift to different key -> caps != lower case
    if (event->isAutoRepeat()) { return; }
    else if (event->key() == Qt::Key_Up)     { _camera_key_handler->keyDown(CameraKeyHandler::Key::Rotate_Up); }
    else if (event->key() == Qt::Key_Down)   { _camera_key_handler->keyDown(CameraKeyHandler::Key::Rotate_Down); }
    else if (event->key() == Qt::Key_Left)   { _camera_key_handler->keyDown(CameraKeyHandler::Key::Rotate_Left); }
    else if (event->key() == Qt::Key_Right)  { _camera_key_handler->keyDown(CameraKeyHandler::Key::Rotate_Right); }
    else if (event->key() == Qt::Key_Space)  { _camera_key_handler->keyDown(CameraKeyHandler::Key::Strafe_Up); }
    else if (event->key() == Qt::Key_Shift)  { _camera_key_handler->keyDown(CameraKeyHandler::Key::Strafe_Down); }
    else if (event->text() == 'z') { _camera_key_handler->keyDown(CameraKeyHandler::Key::Strafe_Forward); }
    else if (event->text() == 's') { _camera_key_handler->keyDown(CameraKeyHandler::Key::Strafe_Back); }
    else if (event->text() == 'q') { _camera_key_handler->keyDown(CameraKeyHandler::Key::Strafe_Left); }
    else if (event->text() == 'd') { _camera_key_handler->keyDown(CameraKeyHandler::Key::Strafe_Right); }
    else if (event->text() == 'l') { _headlamp->toggle(); }
    else if (event->key() == Qt::Key_Escape) { emit escapePressed(); }
    return;
}
void OpenGLView::keyReleaseEvent(QKeyEvent* event) {
    if (event->isAutoRepeat()) { return; }
    else if (event->key() == Qt::Key_Up)     { _camera_key_handler->keyUp(CameraKeyHandler::Key::Rotate_Up); }
    else if (event->key() == Qt::Key_Down)   { _camera_key_handler->keyUp(CameraKeyHandler::Key::Rotate_Down); }
    else if (event->key() == Qt::Key_Left)   { _camera_key_handler->keyUp(CameraKeyHandler::Key::Rotate_Left); }
    else if (event->key() == Qt::Key_Right)  { _camera_key_handler->keyUp(CameraKeyHandler::Key::Rotate_Right); }
    else if (event->key() == Qt::Key_Space)  { _camera_key_handler->keyUp(CameraKeyHandler::Key::Strafe_Up); }
    else if (event->key() == Qt::Key_Shift)  { _camera_key_handler->keyUp(CameraKeyHandler::Key::Strafe_Down); }
    else if (event->text() == 'z') { _camera_key_handler->keyUp(CameraKeyHandler::Key::Strafe_Forward); }
    else if (event->text() == 's') { _camera_key_handler->keyUp(CameraKeyHandler::Key::Strafe_Back); }
    else if (event->text() == 'q') { _camera_key_handler->keyUp(CameraKeyHandler::Key::Strafe_Left); }
    else if (event->text() == 'd') { _camera_key_handler->keyUp(CameraKeyHandler::Key::Strafe_Right); }
    return;
}
void OpenGLView::mouseMoveEvent(QMouseEvent *event) {
    _camera_mouse_handler->registerMouseMovement(
        QPoint((width() / 2), (height() / 2)),      // screen center
        event->pos()                                // new pos
    );

    // set cursor back to center
    this->cursor().setPos(mapToGlobal(QPoint(
        width() / 2,
        height() / 2
    )));
}

////////////////////////////////////////////////////////
/// Update
////////////////////////////////////////////////////////
void OpenGLView::updateCamera() {
    _camera_mouse_handler->updateCamera();
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

