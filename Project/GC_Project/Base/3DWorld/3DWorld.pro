#-------------------------------------------------
#
# Project created by QtCreator 2018-04-21T16:47:09
#
#-------------------------------------------------

LIBS    += -lopengl32 glu32.lib
QT      += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3DWorld
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



FORMS    += displaywindow.ui \
    pausescreen.ui \
    SettingsScreen.ui \
    KeyBindsScreen.ui

win32: LIBS += -L"C:/Program Files/Assimp/lib/x64/" -lassimp

INCLUDEPATH += "C:/Program Files/Assimp/include"
DEPENDPATH += "C:/Program Files/Assimp/include"

RESOURCES += \
    resources.qrc

DISTFILES +=

win32: LIBS += -L$$PWD/../SOIL/lib/ -lSOIL

INCLUDEPATH += $$PWD/../SOIL/src
DEPENDPATH += $$PWD/../SOIL/src

HEADERS += \
    Camera.h \
    CameraKeyHandler.h \
    CameraMouseHandler.h \
    DisplayList.h \
    displaywindow.h \
    enititycreator.h \
    HeadLamp.h \
    KeyBindsScreen.h \
    modelloader.h \
    openglview.h \
    pausescreen.h \
    picking.h \
    Point3D.h \
    qssfile.h \
    Settings.h \
    SettingsScreen.h \
    Texture.h \
    Vector3D.h \
    mvc.hpp \
    Entities/entitycollection.h \
    Entities/spider.h \
    Entities/thwomp.h \
    ModelData/GroupRenderer.h \
    ModelData/Model.h \
    ModelData/modelentity.h \
    ModelData/ModelGroup.h \
    ModelData/ModelRenderer.h \
    ModelData/RendererInterface.h \
    Entities/star.h \
    Entities/mario.h \
    Entities/runaway.h \
    ModelData/entity.h \
    ModelData/groupentity.h

SOURCES += \
    Camera.cpp \
    CameraKeyHandler.cpp \
    CameraMouseHandler.cpp \
    DisplayList.cpp \
    displaywindow.cpp \
    enititycreator.cpp \
    HeadLamp.cpp \
    KeyBindsScreen.cpp \
    main.cpp \
    modelloader.cpp \
    openglview.cpp \
    pausescreen.cpp \
    picking.cpp \
    Point3D.cpp \
    qssfile.cpp \
    Settings.cpp \
    SettingsScreen.cpp \
    Texture.cpp \
    Vector3D.cpp \
    Entities/entitycollection.cpp \
    Entities/spider.cpp \
    Entities/thwomp.cpp \
    ModelData/GroupRenderer.cpp \
    ModelData/Model.cpp \
    ModelData/modelentity.cpp \
    ModelData/ModelGroup.cpp \
    ModelData/ModelRenderer.cpp \
    Entities/star.cpp \
    Entities/mario.cpp \
    Entities/runaway.cpp \
    ModelData/groupentity.cpp
