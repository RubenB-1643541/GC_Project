#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QStackedWidget>

#include "openglview.h"
#include "pausescreen.h"
#include "SettingsScreen.h"
#include "KeyBindsScreen.h"
#include "Settings.h"

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
    void swapToPauseScreen();
    void swapToOpenGLView();
    void swapToSettingsScreen();
    void swapToKeybindsScreen();
private:
    // Stacked widget
    QStackedWidget* _views;

    // Views
    OpenGLView* _open_gl_view;
    PauseScreen* _pause_screen;
    SettingsScreen* _settings_screen;
    KeyBindsScreen* _keybinds_screen;

    // Data
    Settings* _settings;
};

}


#endif // DISPLAYWINDOW_H
