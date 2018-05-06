#ifndef KEYBINDSSCREEN_H
#define KEYBINDSSCREEN_H

#include <QFrame>
#include <QPushButton>

#include "qssfile.h"

namespace Ui {
class KeyBindsScreen;
}

namespace __3DWorld__ {

/**
 * @author Wald Habets
 * @brief The KeyBindsScreen class
 */
class KeyBindsScreen :
public QFrame {
    Q_OBJECT
public:
    ////////////////////////////////////////////////////////
    /// Construction
    ////////////////////////////////////////////////////////
    explicit KeyBindsScreen(QWidget *parent = 0);
    ~KeyBindsScreen();
signals:
    ////////////////////////////////////////////////////////
    /// Button Signals
    ////////////////////////////////////////////////////////
    void backButtonPressed();
private slots:
    ////////////////////////////////////////////////////////
    /// Button Handling
    ////////////////////////////////////////////////////////
    void onBackButtonPressed();
private:
    Ui::KeyBindsScreen *ui;

    QPushButton* _back_button;
};

}

#endif // KEYBINDSSCREEN_H
