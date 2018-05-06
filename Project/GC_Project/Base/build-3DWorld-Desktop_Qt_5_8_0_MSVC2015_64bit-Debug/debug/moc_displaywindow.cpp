/****************************************************************************
** Meta object code from reading C++ file 'displaywindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../3DWorld/displaywindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'displaywindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata___3DWorld____DisplayWindow_t {
    QByteArrayData data[6];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata___3DWorld____DisplayWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata___3DWorld____DisplayWindow_t qt_meta_stringdata___3DWorld____DisplayWindow = {
    {
QT_MOC_LITERAL(0, 0, 26), // "__3DWorld__::DisplayWindow"
QT_MOC_LITERAL(1, 27, 17), // "swapToPauseScreen"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 16), // "swapToOpenGLView"
QT_MOC_LITERAL(4, 63, 20), // "swapToSettingsScreen"
QT_MOC_LITERAL(5, 84, 20) // "swapToKeybindsScreen"

    },
    "__3DWorld__::DisplayWindow\0swapToPauseScreen\0"
    "\0swapToOpenGLView\0swapToSettingsScreen\0"
    "swapToKeybindsScreen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data___3DWorld____DisplayWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void __3DWorld__::DisplayWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DisplayWindow *_t = static_cast<DisplayWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->swapToPauseScreen(); break;
        case 1: _t->swapToOpenGLView(); break;
        case 2: _t->swapToSettingsScreen(); break;
        case 3: _t->swapToKeybindsScreen(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject __3DWorld__::DisplayWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata___3DWorld____DisplayWindow.data,
      qt_meta_data___3DWorld____DisplayWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *__3DWorld__::DisplayWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *__3DWorld__::DisplayWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata___3DWorld____DisplayWindow.stringdata0))
        return static_cast<void*>(const_cast< DisplayWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int __3DWorld__::DisplayWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
