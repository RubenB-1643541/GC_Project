#include "displaywindow.h"
#include "ui_displaywindow.h"
#include "Model/modelrender.h"
#include <QDebug>

namespace __3DWorld__ {

////////////////////////////////////////////////////////
/// Construction
////////////////////////////////////////////////////////
DisplayWindow::DisplayWindow(QWidget *parent) :
    QMainWindow(parent) {
    _views = new QStackedWidget(this);
    _open_gl_view = new OpenGLView();
    _pause_screen = new PauseScreen();

    _views->addWidget(_open_gl_view);
    _views->addWidget(_pause_screen);

    this->setCentralWidget(_views);
    this->setMinimumSize(1280, 720);

    // Connections
    connect(_open_gl_view, SIGNAL(escapePressed()), this, SLOT(setPauseScreen()));
    connect(_pause_screen, SIGNAL(continueButtonPressed()), this, SLOT(setOpenGLView()));

    // Models
    ModelRender * render = new ModelRender(_open_gl_view);
    render->LoadModel("bobomb battlefeild.obj");

    ModelRender * render2 = new ModelRender(_open_gl_view);
    render2->LoadModel("spider.obj");
    _open_gl_view->addModelRenderer(render2);
    _open_gl_view->addModelRenderer(render);
}

DisplayWindow::~DisplayWindow() {

}

////////////////////////////////////////////////////////
/// Change displayed widget
////////////////////////////////////////////////////////
void DisplayWindow::setPauseScreen() {
    _views->setCurrentWidget(_pause_screen);
}

void DisplayWindow::setOpenGLView() {
    _views->setCurrentWidget(_open_gl_view);
}

}
