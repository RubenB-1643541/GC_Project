#include "displaywindow.h"
#include "ui_displaywindow.h"
#include <QDebug>

namespace __3DWorld__ {

DisplayWindow::DisplayWindow(QWidget *parent) :
    QMainWindow(parent) {
    _open_gl_view = new OpenGLView();
    setCentralWidget(_open_gl_view);
}

DisplayWindow::~DisplayWindow() {

}

}
