#include "displaywindow.h"
#include "ui_displaywindow.h"
#include "Model/modelrender.h"
#include <QDebug>

namespace __3DWorld__ {

DisplayWindow::DisplayWindow(QWidget *parent) :
    QMainWindow(parent) {
    _open_gl_view = new OpenGLView();
    ModelRender * render = new ModelRender();
    render->LoadModel("Models/Bobomb/bobomb battlefeild.obj");
    _open_gl_view->addModelRenderer(render);
    ModelRender * render2 = new ModelRender();
    render2->LoadModel("Models/Bench/bench.obj");
    _open_gl_view->addModelRenderer(render2);

    this->setCentralWidget(_open_gl_view);
    this->setMinimumSize(1280, 720);
}

DisplayWindow::~DisplayWindow() {

}

}
