#ifndef PAUSESCREEN_H
#define PAUSESCREEN_H

#include <QFrame>
#include <QPushButton>

namespace Ui {
class PauseScreen;
}
namespace __3DWorld__ {


/**
 * @author Wald Habets
 * @brief The PauseScreen class
 */
class PauseScreen :
public QFrame {
    Q_OBJECT
public:
    ////////////////////////////////////////////////////////
    /// Construction
    ////////////////////////////////////////////////////////
    explicit PauseScreen(QWidget *parent = 0);
    ~PauseScreen();
signals:
    ////////////////////////////////////////////////////////
    /// Button Signals
    ////////////////////////////////////////////////////////
    void continueButtonPressed();
    void settingsButtonPressed();
    void keybindsButtonPressed();
private slots:
    ////////////////////////////////////////////////////////
    /// Button Handling
    ////////////////////////////////////////////////////////
    void onContinueButtonPressed();
    void onSettingsButtonPressed();
    void onKeybindsButtonPressed();
    void onQuitButtonPressed();
private:
    Ui::PauseScreen *ui;

    QPushButton* _continue_button;
    QPushButton* _settings_button;
    QPushButton* _keybinds_button;
    QPushButton* _quit_button;
};

}

#endif // PAUSESCREEN_H
