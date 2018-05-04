#include "displaywindow.h"
#include "ui_displaywindow.h"
#include "Model/modelrender.h"
#include <QDebug>

namespace __3DWorld__ {

DisplayWindow::DisplayWindow(QWidget *parent) :
    QMainWindow(parent) {
    _open_gl_view = new OpenGLView();
    ModelRender * render = new ModelRender();
    render->LoadModel("Models/Bobomb/bobomb battlefeild.obj", new Point3D(0, -10, 0), new Point3D(0,0,0), 1);
    _open_gl_view->addModelRenderer(render);

    ModelRender * render2 = new ModelRender();
    render2->LoadModel("Models/Bench/bench.obj", new Point3D(-26, 1.37, 10), new Point3D(0, 10, 0), 0.4);
    _open_gl_view->addModelRenderer(render2);

    ModelRender * render3 = new ModelRender();
    render3->LoadModel("Models/Spider/spider.obj", new Point3D(1,1.3,-2), new Point3D(0,0,70), 0.05);
    _open_gl_view->addModelRenderer(render3);


    this->setCentralWidget(_open_gl_view);
    this->setMinimumSize(1280, 720);
}

DisplayWindow::~DisplayWindow() {

}

}
