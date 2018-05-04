#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QStackedWidget>

#include "openglview.h"
#include "pausescreen.h"

namespace __3DWorld__ {

/**
 * @author Wald Habets
 * @brief The DisplayWindow class
 */
class DisplayWindow : public QMainWindow {
    Q_OBJECT
public:
    ////////////////////////////////////////////////////////
    /// Construction
    ////////////////////////////////////////////////////////
    explicit DisplayWindow(QWidget *parent = 0);
    ~DisplayWindow();
public slots:
    ////////////////////////////////////////////////////////
    /// Change displayed widget
    ////////////////////////////////////////////////////////
    void setPauseScreen();
    void setOpenGLView();
private:
    // Stacked widget
    QStackedWidget* _views;

    // Views
    OpenGLView* _open_gl_view;
    PauseScreen* _pause_screen;
};

}


#endif // DISPLAYWINDOW_H
