#include "openglview.h"
#include <QDebug>
#include "enititycreator.h"
#include "Entities/entitycollection.h"

namespace __3DWorld__ {

////////////////////////////////////////////////////////
/// Construction
////////////////////////////////////////////////////////
OpenGLView::OpenGLView(Settings* settings) : QOpenGLWidget() {
    this->setMouseTracking(true);
    this->setCursor(Qt::BlankCursor);

    qDebug() << isValid();
    makeCurrent();

    // Timer for updating view
    _timer = new QTimer();
    connect(_timer, SIGNAL(timeout()), this, SLOT(update()));

    _settings = settings;
    _settings->addView(this);

    //_entities = new EntityCollection();
    //EntityCreator * creator = new EntityCreator(_entities, this);

    update();

    setFocusPolicy(Qt::StrongFocus);

    // Camera
    _camera = new Camera();
    _mouse_dx = 0;
    _mouse_dy = 0;
    _camera_key_handler = new CameraKeyHandler(_camera);
    _camera_mouse_handler = new CameraMouseHandler(_camera);
    _headlamp = new HeadLamp();


    // eventueel eigen file formaat
    // met models en hun meta data (rotatie, schalering, etc...
    // dan file parsen en zo models toevoegen

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
    //glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    //glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
    glEnable(GL_LIGHT0);

    // Global lighting

    GLfloat diffuse[] = { 0.98, 0.98, 0.62, 0.1 };     // sun yellow
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    //GLfloat specular[] = { 0.98, 0.98, 0.62, 0.1 };     // sun yellow
    //glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    //GLfloat ambient[] = { 1.0, 0.8, 0.0, 1.0 };     // sun yellow
    //glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    GLfloat light_position[] = { 35, 40, 35, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    //glLighti(GL_LIGHT0, GL_SPOT_CUTOFF, 90);

    glEnable(GL_DEPTH_TEST);

    // background color
    // 87CEEB
    glClearColor(0.53, 0.81, 0.92 ,1.0f);

    // Temp
    GLuint l_world = DisplayList::create("bobomb battlefeild.obj");
    GLuint l_tree  = DisplayList::create("tree.obj");
    GLuint l_star  = DisplayList::create("star.obj");
    GLuint t_tree = Texture::create("leafs.png");
    GLuint t_world = Texture::create("stone.png");
    GLuint t_star = Texture::create("body.png");
    Model* world = new Model(l_world, t_world);
    world->rotate(0, Point3D(0, 0, 1));
    addModelRenderer(new ModelRenderer(world));
    Model* star = new Model(l_star, t_star);
    star->translate(Point3D(40, 40, 40));
    star->rotate(-30, Point3D(1, 0, 0)); // gets overriden
    star->rotate(45, Point3D(0, 1, 0));
    star->scale(2.0);
    addModelRenderer(new ModelRenderer(star));
    Model* tree1 = new Model(l_tree, t_tree);
    tree1->translate(Point3D(15, 12, 30));
    tree1->rotate(-90, Point3D(1, 0, 0));
    tree1->scale(0.1);
    addModelRenderer(new ModelRenderer(tree1));
    Model* tree2 = new Model(l_tree, t_tree);
    tree2->translate(Point3D(-25, 12, 10));
    tree2->rotate(-90, Point3D(1, 0, 0));
    tree2->scale(0.1);
    addModelRenderer(new ModelRenderer(tree2));
    Model* tree3 = new Model(l_tree, t_tree);
    tree3->translate(Point3D(35, 17, -25));
    tree3->rotate(-90, Point3D(1, 0, 0));
    tree3->scale(0.1);
    addModelRenderer(new ModelRenderer(tree3));

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

    return;
}

void OpenGLView::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    // Update Camera
    updateCamera();

    // Draw Models
    for (ModelRenderer* renderer: _model_renderers) {
        renderer->draw(
            _shading_mode,
            _render_mode
        );
    }

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();

    //_entities->UpdateEntities();

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
    else if (event->key() == Qt::Key_Up)    { _camera_key_handler->keyDown(CameraKeyHandler::Key::Rotate_Up); }
    else if (event->key() == Qt::Key_Down)  { _camera_key_handler->keyDown(CameraKeyHandler::Key::Rotate_Down); }
    else if (event->key() == Qt::Key_Left)  { _camera_key_handler->keyDown(CameraKeyHandler::Key::Rotate_Left); }
    else if (event->key() == Qt::Key_Right) { _camera_key_handler->keyDown(CameraKeyHandler::Key::Rotate_Right); }
    else if (event->key() == Qt::Key_Space) { _camera_key_handler->keyDown(CameraKeyHandler::Key::Strafe_Up); }
    else if (event->key() == Qt::Key_Alt)   { _camera_key_handler->keyDown(CameraKeyHandler::Key::Strafe_Down); }
    else if (event->text() == 'z') { _camera_key_handler->keyDown(CameraKeyHandler::Key::Strafe_Forward); }
    else if (event->text() == 's') { _camera_key_handler->keyDown(CameraKeyHandler::Key::Strafe_Back); }
    else if (event->text() == 'q') { _camera_key_handler->keyDown(CameraKeyHandler::Key::Strafe_Left); }
    else if (event->text() == 'd') { _camera_key_handler->keyDown(CameraKeyHandler::Key::Strafe_Right); }
    else if (event->text() == 'l') { _headlamp->toggle(); }
    else if (event->key() == Qt::Key_Escape) { emit escapePressed(); }
    else if (event->text() == 'g') { glDisable(GL_LIGHT0); }
    return;
}
void OpenGLView::keyReleaseEvent(QKeyEvent* event) {
    if (event->isAutoRepeat()) { return; }
    else if (event->key() == Qt::Key_Up)    { _camera_key_handler->keyUp(CameraKeyHandler::Key::Rotate_Up); }
    else if (event->key() == Qt::Key_Down)  { _camera_key_handler->keyUp(CameraKeyHandler::Key::Rotate_Down); }
    else if (event->key() == Qt::Key_Left)  { _camera_key_handler->keyUp(CameraKeyHandler::Key::Rotate_Left); }
    else if (event->key() == Qt::Key_Right) { _camera_key_handler->keyUp(CameraKeyHandler::Key::Rotate_Right); }
    else if (event->key() == Qt::Key_Space) { _camera_key_handler->keyUp(CameraKeyHandler::Key::Strafe_Up); }
    else if (event->key() == Qt::Key_Alt)   { _camera_key_handler->keyUp(CameraKeyHandler::Key::Strafe_Down); }
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
/// settings
////////////////////////////////////////////////////////
void OpenGLView::update() {
    _shading_mode = _settings->getShadingMode();
    _render_mode = _settings->getRenderMode();
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

