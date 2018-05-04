/********************************************************************************
** Form generated from reading UI file 'pausescreen.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAUSESCREEN_H
#define UI_PAUSESCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_PauseScreen
{
public:
    QGridLayout *gridLayout;
    QPushButton *quitButton;
    QPushButton *continueButton;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QFrame *PauseScreen)
    {
        if (PauseScreen->objectName().isEmpty())
            PauseScreen->setObjectName(QStringLiteral("PauseScreen"));
        PauseScreen->resize(632, 424);
        gridLayout = new QGridLayout(PauseScreen);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(9, 9, -1, 9);
        quitButton = new QPushButton(PauseScreen);
        quitButton->setObjectName(QStringLiteral("quitButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(quitButton->sizePolicy().hasHeightForWidth());
        quitButton->setSizePolicy(sizePolicy);
        quitButton->setMinimumSize(QSize(0, 40));
        quitButton->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(quitButton, 2, 0, 1, 1);

        continueButton = new QPushButton(PauseScreen);
        continueButton->setObjectName(QStringLiteral("continueButton"));
        sizePolicy.setHeightForWidth(continueButton->sizePolicy().hasHeightForWidth());
        continueButton->setSizePolicy(sizePolicy);
        continueButton->setMinimumSize(QSize(0, 40));
        continueButton->setMaximumSize(QSize(300, 16777215));

        gridLayout->addWidget(continueButton, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 0, 1, 1);


        retranslateUi(PauseScreen);

        QMetaObject::connectSlotsByName(PauseScreen);
    } // setupUi

    void retranslateUi(QFrame *PauseScreen)
    {
        PauseScreen->setWindowTitle(QApplication::translate("PauseScreen", "Form", Q_NULLPTR));
        quitButton->setText(QApplication::translate("PauseScreen", "Quit", Q_NULLPTR));
        continueButton->setText(QApplication::translate("PauseScreen", "Continue", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PauseScreen: public Ui_PauseScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAUSESCREEN_H
