/********************************************************************************
** Form generated from reading UI file 'SettingsScreen.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSSCREEN_H
#define UI_SETTINGSSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_SettingsScreen
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *saveButton;
    QComboBox *renderCombo;
    QComboBox *shadingCombo;
    QSpacerItem *verticalSpacer_2;
    QLabel *renderLabel;
    QSpacerItem *verticalSpacer;
    QLabel *shadingLabel;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QFrame *SettingsScreen)
    {
        if (SettingsScreen->objectName().isEmpty())
            SettingsScreen->setObjectName(QStringLiteral("SettingsScreen"));
        SettingsScreen->resize(707, 478);
        gridLayout_2 = new QGridLayout(SettingsScreen);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        saveButton = new QPushButton(SettingsScreen);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setMinimumSize(QSize(0, 40));
        saveButton->setMaximumSize(QSize(300, 16777215));

        gridLayout_2->addWidget(saveButton, 6, 0, 1, 1);

        renderCombo = new QComboBox(SettingsScreen);
        renderCombo->setObjectName(QStringLiteral("renderCombo"));
        renderCombo->setMinimumSize(QSize(0, 40));
        renderCombo->setMaximumSize(QSize(300, 16777215));

        gridLayout_2->addWidget(renderCombo, 4, 0, 1, 1);

        shadingCombo = new QComboBox(SettingsScreen);
        shadingCombo->setObjectName(QStringLiteral("shadingCombo"));
        shadingCombo->setMinimumSize(QSize(0, 40));
        shadingCombo->setMaximumSize(QSize(300, 16777215));

        gridLayout_2->addWidget(shadingCombo, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 7, 0, 1, 1);

        renderLabel = new QLabel(SettingsScreen);
        renderLabel->setObjectName(QStringLiteral("renderLabel"));

        gridLayout_2->addWidget(renderLabel, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 0, 1, 1);

        shadingLabel = new QLabel(SettingsScreen);
        shadingLabel->setObjectName(QStringLiteral("shadingLabel"));

        gridLayout_2->addWidget(shadingLabel, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 5, 0, 1, 1);


        retranslateUi(SettingsScreen);

        QMetaObject::connectSlotsByName(SettingsScreen);
    } // setupUi

    void retranslateUi(QFrame *SettingsScreen)
    {
        SettingsScreen->setWindowTitle(QApplication::translate("SettingsScreen", "Form", Q_NULLPTR));
        saveButton->setText(QApplication::translate("SettingsScreen", "Save", Q_NULLPTR));
        renderLabel->setText(QApplication::translate("SettingsScreen", "Rendering Model", Q_NULLPTR));
        shadingLabel->setText(QApplication::translate("SettingsScreen", "Shading", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingsScreen: public Ui_SettingsScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSSCREEN_H
