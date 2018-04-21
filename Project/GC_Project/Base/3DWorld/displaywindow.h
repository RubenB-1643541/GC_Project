#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

#include "openglview.h"

namespace __3DWorld__ {

/**
 * @author Wald Habets
 * @brief The DisplayWindow class
 */
class DisplayWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit DisplayWindow(QWidget *parent = 0);
    ~DisplayWindow();

private:
    OpenGLView* _open_gl_view;
};

}


#endif // DISPLAYWINDOW_H
