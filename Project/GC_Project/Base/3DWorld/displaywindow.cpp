#include "displaywindow.h"
#include "ui_displaywindow.h"
#include <QDebug>

namespace __3DWorld__ {

////////////////////////////////////////////////////////
/// Construction
////////////////////////////////////////////////////////
DisplayWindow::DisplayWindow(QWidget *parent) :
    QMainWindow(parent) {
    _settings = new Settings();

    _views = new QStackedWidget(this);
    _open_gl_view = new OpenGLView(_settings);
    _pause_screen = new PauseScreen();
    _settings_screen = new SettingsScreen(_settings);
    _keybinds_screen = new KeyBindsScreen();

    _views->addWidget(_open_gl_view);
    _views->addWidget(_pause_screen);
    _views->addWidget(_settings_screen);
    _views->addWidget(_keybinds_screen);

    this->setCentralWidget(_views);
    this->setMinimumSize(1280, 720);

    // Connections

    connect(_open_gl_view, SIGNAL(escapePressed()), this, SLOT(setPauseScreen()));
    connect(_pause_screen, SIGNAL(continueButtonPressed()), this, SLOT(setOpenGLView()));

    /*
    ModelObject * temp_model1 = new ModelObject("Models/Bobomb/bobomb battlefeild.obj");
    ModelRenderer * renderer1 = new ModelRenderer(temp_model1);
    _open_gl_view->addModelRenderer(renderer1);


    ModelObject * temp_model2 = new ModelObject("Models/Spider/spider.obj");
    ModelRenderer * renderer2 = new ModelRenderer(temp_model2);
    _open_gl_view->addModelRenderer(renderer2);
    */

    connect(_open_gl_view, SIGNAL(escapePressed()), this, SLOT(swapToPauseScreen()));
    connect(_keybinds_screen, SIGNAL(backButtonPressed()), this, SLOT(swapToPauseScreen()));
    connect(_settings_screen, SIGNAL(saveButtonPressed()), this, SLOT(swapToPauseScreen()));
    connect(_pause_screen, SIGNAL(continueButtonPressed()), this, SLOT(swapToOpenGLView()));
    connect(_pause_screen, SIGNAL(settingsButtonPressed()), this, SLOT(swapToSettingsScreen()));
    connect(_pause_screen, SIGNAL(keybindsButtonPressed()), this, SLOT(swapToKeybindsScreen()));

}

DisplayWindow::~DisplayWindow() {
    delete _settings;
    delete _open_gl_view;
    delete _pause_screen;
    delete _settings_screen;
    delete _keybinds_screen;

    delete _views;
}

////////////////////////////////////////////////////////
/// Change displayed widget
////////////////////////////////////////////////////////
void DisplayWindow::swapToPauseScreen() {
    _views->setCurrentWidget(_pause_screen);
}
void DisplayWindow::swapToOpenGLView() {
    _views->setCurrentWidget(_open_gl_view);
}
void DisplayWindow::swapToSettingsScreen() {
    _views->setCurrentWidget(_settings_screen);
}
void DisplayWindow::swapToKeybindsScreen() {
    _views->setCurrentWidget(_keybinds_screen);
}

}
