#include "pausescreen.h"
#include "ui_pausescreen.h"
#include "qssfile.h"

namespace __3DWorld__ {

////////////////////////////////////////////////////////
/// Construction
////////////////////////////////////////////////////////
PauseScreen::PauseScreen(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::PauseScreen) {
    ui->setupUi(this);

    setStyleSheet(Frost::QSSFile(":/qss/pausescreen.qss").toString());

    // Get UI elements
    _continue_button = ui->continueButton;
    _quit_button = ui->quitButton;

    // Connect
    connect(_continue_button, SIGNAL(clicked(bool)), this, SLOT(onContinueButtonPressed()));
    connect(_quit_button, SIGNAL(clicked(bool)), this, SLOT(onQuitButtonPressed()));
}

PauseScreen::~PauseScreen()
{
    delete ui;
}

////////////////////////////////////////////////////////
/// Button Handling
////////////////////////////////////////////////////////
void PauseScreen::onContinueButtonPressed() {
    emit continueButtonPressed();
}
void PauseScreen::onQuitButtonPressed() {
    QApplication::instance()->quit();
}

}
