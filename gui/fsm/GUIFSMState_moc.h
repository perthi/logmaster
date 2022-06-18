/****************************************************************************
** Meta object code from reading C++ file 'GUIFSMState.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "GUIFSMState.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUIFSMState.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GUIFsmState_t {
    QByteArrayData data[9];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUIFsmState_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUIFsmState_t qt_meta_stringdata_GUIFsmState = {
    {
QT_MOC_LITERAL(0, 0, 11), // "GUIFsmState"
QT_MOC_LITERAL(1, 12, 17), // "ShowStateChildren"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 6), // "string"
QT_MOC_LITERAL(4, 38, 15), // "OpenStateDialog"
QT_MOC_LITERAL(5, 54, 8), // "ShowMenu"
QT_MOC_LITERAL(6, 63, 12), // "ShowChildren"
QT_MOC_LITERAL(7, 76, 10), // "OpenDialog"
QT_MOC_LITERAL(8, 87, 10) // "SendAction"

    },
    "GUIFsmState\0ShowStateChildren\0\0string\0"
    "OpenStateDialog\0ShowMenu\0ShowChildren\0"
    "OpenDialog\0SendAction"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUIFsmState[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   50,    2, 0x08 /* Private */,
       6,    0,   51,    2, 0x08 /* Private */,
       7,    0,   52,    2, 0x08 /* Private */,
       8,    1,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void GUIFsmState::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GUIFsmState *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ShowStateChildren((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 1: _t->OpenStateDialog((*reinterpret_cast< string(*)>(_a[1]))); break;
        case 2: _t->ShowMenu(); break;
        case 3: _t->ShowChildren(); break;
        case 4: _t->OpenDialog(); break;
        case 5: _t->SendAction((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GUIFsmState::*)(string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUIFsmState::ShowStateChildren)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GUIFsmState::*)(string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUIFsmState::OpenStateDialog)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GUIFsmState::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GUIFsmState.data,
    qt_meta_data_GUIFsmState,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GUIFsmState::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUIFsmState::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GUIFsmState.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GUIFsmState::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void GUIFsmState::ShowStateChildren(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GUIFsmState::OpenStateDialog(string _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
