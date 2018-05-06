#ifndef SETTINGSSCREEN_H
#define SETTINGSSCREEN_H

#include <QFrame>
#include <QPushButton>
#include <QComboBox>

#include "qssfile.h"
#include "Settings.h"

namespace Ui {
class SettingsScreen;
}

namespace __3DWorld__ {

/**
 * @author Wald Habets
 * @brief The SettingsScreen class
 */
class SettingsScreen :
public QFrame {
    Q_OBJECT

public:
    ////////////////////////////////////////////////////////
    /// Construction
    ////////////////////////////////////////////////////////
    explicit SettingsScreen(Settings* settings, QWidget *parent = 0);
    ~SettingsScreen();
signals:
    ////////////////////////////////////////////////////////
    /// Button Signals
    ////////////////////////////////////////////////////////
    void saveButtonPressed();
private slots:
    ////////////////////////////////////////////////////////
    /// Button Handling
    ////////////////////////////////////////////////////////
    void onSaveButtonPressed();
private:
    Ui::SettingsScreen *ui;

    Settings* _settings;

    QComboBox* _shading_combo;
    QComboBox* _render_combo;

    QPushButton* _save_button;
};

}

#endif // SETTINGSSCREEN_H
