#include "KeyBindsScreen.h"
#include "ui_KeyBindsScreen.h"

namespace __3DWorld__ {

////////////////////////////////////////////////////////
/// Construction
////////////////////////////////////////////////////////
KeyBindsScreen::KeyBindsScreen(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::KeyBindsScreen) {
    ui->setupUi(this);

    setStyleSheet(Frost::QSSFile(":/qss/StyleSheets/keybindsscreen.qss").toString());

    _back_button = ui->backButton;

    connect(_back_button, SIGNAL(clicked(bool)), this, SLOT(onBackButtonPressed()));
}

KeyBindsScreen::~KeyBindsScreen() {
    delete ui;
}

////////////////////////////////////////////////////////
/// Button Handling
////////////////////////////////////////////////////////
void KeyBindsScreen::onBackButtonPressed() {
    emit backButtonPressed();
}

}
