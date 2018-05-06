/****************************************************************************
** Meta object code from reading C++ file 'pausescreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../3DWorld/pausescreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pausescreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata___3DWorld____PauseScreen_t {
    QByteArrayData data[9];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata___3DWorld____PauseScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata___3DWorld____PauseScreen_t qt_meta_stringdata___3DWorld____PauseScreen = {
    {
QT_MOC_LITERAL(0, 0, 24), // "__3DWorld__::PauseScreen"
QT_MOC_LITERAL(1, 25, 21), // "continueButtonPressed"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 21), // "settingsButtonPressed"
QT_MOC_LITERAL(4, 70, 21), // "keybindsButtonPressed"
QT_MOC_LITERAL(5, 92, 23), // "onContinueButtonPressed"
QT_MOC_LITERAL(6, 116, 23), // "onSettingsButtonPressed"
QT_MOC_LITERAL(7, 140, 23), // "onKeybindsButtonPressed"
QT_MOC_LITERAL(8, 164, 19) // "onQuitButtonPressed"

    },
    "__3DWorld__::PauseScreen\0continueButtonPressed\0"
    "\0settingsButtonPressed\0keybindsButtonPressed\0"
    "onContinueButtonPressed\0onSettingsButtonPressed\0"
    "onKeybindsButtonPressed\0onQuitButtonPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data___3DWorld____PauseScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void __3DWorld__::PauseScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PauseScreen *_t = static_cast<PauseScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->continueButtonPressed(); break;
        case 1: _t->settingsButtonPressed(); break;
        case 2: _t->keybindsButtonPressed(); break;
        case 3: _t->onContinueButtonPressed(); break;
        case 4: _t->onSettingsButtonPressed(); break;
        case 5: _t->onKeybindsButtonPressed(); break;
        case 6: _t->onQuitButtonPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PauseScreen::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PauseScreen::continueButtonPressed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PauseScreen::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PauseScreen::settingsButtonPressed)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PauseScreen::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PauseScreen::keybindsButtonPressed)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject __3DWorld__::PauseScreen::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata___3DWorld____PauseScreen.data,
      qt_meta_data___3DWorld____PauseScreen,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *__3DWorld__::PauseScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *__3DWorld__::PauseScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata___3DWorld____PauseScreen.stringdata0))
        return static_cast<void*>(const_cast< PauseScreen*>(this));
    return QFrame::qt_metacast(_clname);
}

int __3DWorld__::PauseScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void __3DWorld__::PauseScreen::continueButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void __3DWorld__::PauseScreen::settingsButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void __3DWorld__::PauseScreen::keybindsButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
