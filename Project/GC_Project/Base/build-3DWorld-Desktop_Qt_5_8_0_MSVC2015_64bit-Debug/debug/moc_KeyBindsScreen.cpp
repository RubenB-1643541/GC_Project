/****************************************************************************
** Meta object code from reading C++ file 'KeyBindsScreen.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../3DWorld/KeyBindsScreen.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KeyBindsScreen.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata___3DWorld____KeyBindsScreen_t {
    QByteArrayData data[4];
    char stringdata0[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata___3DWorld____KeyBindsScreen_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata___3DWorld____KeyBindsScreen_t qt_meta_stringdata___3DWorld____KeyBindsScreen = {
    {
QT_MOC_LITERAL(0, 0, 27), // "__3DWorld__::KeyBindsScreen"
QT_MOC_LITERAL(1, 28, 17), // "backButtonPressed"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 19) // "onBackButtonPressed"

    },
    "__3DWorld__::KeyBindsScreen\0"
    "backButtonPressed\0\0onBackButtonPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data___3DWorld____KeyBindsScreen[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void __3DWorld__::KeyBindsScreen::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KeyBindsScreen *_t = static_cast<KeyBindsScreen *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->backButtonPressed(); break;
        case 1: _t->onBackButtonPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (KeyBindsScreen::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KeyBindsScreen::backButtonPressed)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject __3DWorld__::KeyBindsScreen::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata___3DWorld____KeyBindsScreen.data,
      qt_meta_data___3DWorld____KeyBindsScreen,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *__3DWorld__::KeyBindsScreen::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *__3DWorld__::KeyBindsScreen::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata___3DWorld____KeyBindsScreen.stringdata0))
        return static_cast<void*>(const_cast< KeyBindsScreen*>(this));
    return QFrame::qt_metacast(_clname);
}

int __3DWorld__::KeyBindsScreen::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void __3DWorld__::KeyBindsScreen::backButtonPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
