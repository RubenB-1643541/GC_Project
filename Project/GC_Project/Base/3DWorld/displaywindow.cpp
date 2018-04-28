#include "displaywindow.h"
#include "ui_displaywindow.h"
#include "Model/modelrender.h"
#include <QDebug>

namespace __3DWorld__ {

DisplayWindow::DisplayWindow(QWidget *parent) :
    QMainWindow(parent) {
    _open_gl_view = new OpenGLView();
    ModelRender * render = new ModelRender(_open_gl_view);
    render->LoadModel("bobomb battlefeild.obj");

    ModelRender * render2 = new ModelRender(_open_gl_view);
    render2->LoadModel("spider.obj");
    _open_gl_view->addModelRenderer(render2);
    _open_gl_view->addModelRenderer(render);
    this->setCentralWidget(_open_gl_view);
    this->setMinimumSize(1280, 720);
}

DisplayWindow::~DisplayWindow() {

}

}
