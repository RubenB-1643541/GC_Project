#-------------------------------------------------
#
# Project created by QtCreator 2018-04-13T21:03:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project_GC
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp \
    modelloader.cpp

HEADERS  += \
    modelloader.h \
    modeldata.h

FORMS    +=

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/'../../../../../../../../../Program Files/Assimp/lib/x86/' -lassimp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/'../../../../../../../../../Program Files/Assimp/lib/x86/' -lassimpd

INCLUDEPATH += $$PWD/'../../../../../../../../../Program Files/Assimp/include'
DEPENDPATH += $$PWD/'../../../../../../../../../Program Files/Assimp/include'
