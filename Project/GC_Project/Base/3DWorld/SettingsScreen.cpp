#include "SettingsScreen.h"
#include "ui_SettingsScreen.h"

namespace __3DWorld__ {

////////////////////////////////////////////////////////
/// Construction
////////////////////////////////////////////////////////
SettingsScreen::SettingsScreen(Settings* settings, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::SettingsScreen) {
    ui->setupUi(this);

    _settings = settings;

    setStyleSheet(Frost::QSSFile(":/qss/StyleSheets/settingsscreen.qss").toString());

    _shading_combo = ui->shadingCombo;
    _shading_combo->addItem("Smooth Shading");
    _shading_combo->addItem("Flat Shading");
    _render_combo = ui->renderCombo;
    _render_combo->addItem("Fill Faces");
    _render_combo->addItem("Wireframe Only");

    _save_button = ui->saveButton;

    connect(_save_button, SIGNAL(clicked(bool)), this, SLOT(onSaveButtonPressed()));
}

SettingsScreen::~SettingsScreen() {
    delete ui;
}

////////////////////////////////////////////////////////
/// Construction
////////////////////////////////////////////////////////
void SettingsScreen::onSaveButtonPressed() {
    switch (_shading_combo->currentIndex()) {
    case 0:
        _settings->setShadingMode(SMOOTH);
        break;
    case 1:
        _settings->setShadingMode(FLAT);
        break;
    }

    switch (_render_combo->currentIndex()) {
    case 0:
        _settings->setRenderMode(FILL);
        break;
    case 1:
        _settings->setRenderMode(WIREFRAME);
        break;
    }

    _settings->setChanged(true);
    _settings->updateViews();
    emit saveButtonPressed();
}

}


