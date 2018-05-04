#ifndef PAUSESCREEN_H
#define PAUSESCREEN_H

#include <QFrame>
#include <QPushButton>

namespace Ui {
class PauseScreen;
}
namespace __3DWorld__ {

class PauseScreen : public QFrame {
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
private slots:
    ////////////////////////////////////////////////////////
    /// Button Handling
    ////////////////////////////////////////////////////////
    void onContinueButtonPressed();
    void onQuitButtonPressed();
private:
    Ui::PauseScreen *ui;

    QPushButton* _continue_button;
    QPushButton* _quit_button;
};

}

#endif // PAUSESCREEN_H
