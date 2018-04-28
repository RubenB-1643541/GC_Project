#include "displaywindow.h"
#include "ui_displaywindow.h"
#include "Model/modelrender.h"
#include <QDebug>

namespace __3DWorld__ {

DisplayWindow::DisplayWindow(QWidget *parent) :
    QMainWindow(parent) {
    _open_gl_view = new OpenGLView();
    ModelRender * render = new ModelRender(_open_gl_view);
    render->LoadModel("velociraptor_mesh_materials.dae");
    _open_gl_view->addModelRenderer(render);
    this->setCentralWidget(_open_gl_view);
    this->setMinimumSize(1280, 720);
}

DisplayWindow::~DisplayWindow() {

}

}
