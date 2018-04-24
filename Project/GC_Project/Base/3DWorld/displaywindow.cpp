#include "displaywindow.h"
#include "ui_displaywindow.h"
#include "Model/modelrender.h"
#include <QDebug>

namespace __3DWorld__ {

DisplayWindow::DisplayWindow(QWidget *parent) :
    QMainWindow(parent) {
    _open_gl_view = new OpenGLView();
    this->setCentralWidget(_open_gl_view);
    this->setMinimumSize(1280, 720);
}

DisplayWindow::~DisplayWindow() {

}

}
