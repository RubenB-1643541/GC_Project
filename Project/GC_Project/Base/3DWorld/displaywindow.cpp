#include "displaywindow.h"
#include "ui_displaywindow.h"
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

    ModelObject * temp_model1 = new ModelObject("Models/Bobomb/bobomb battlefeild.obj");
    ModelRenderer * renderer1 = new ModelRenderer(temp_model1);
    _open_gl_view->addModelRenderer(renderer1);


    ModelObject * temp_model2 = new ModelObject("Models/Spider/spider.obj");
    ModelRenderer * renderer2 = new ModelRenderer(temp_model2);
    _open_gl_view->addModelRenderer(renderer2);

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
