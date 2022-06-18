/****************************************************************************
** Meta object code from reading C++ file 'GUILoggerGui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "GUILoggerGui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUILoggerGui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GUILoggerGui_t {
    QByteArrayData data[11];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUILoggerGui_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUILoggerGui_t qt_meta_stringdata_GUILoggerGui = {
    {
QT_MOC_LITERAL(0, 0, 12), // "GUILoggerGui"
QT_MOC_LITERAL(1, 13, 11), // "NewMessages"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "MsgSeries"
QT_MOC_LITERAL(4, 36, 4), // "msgs"
QT_MOC_LITERAL(5, 41, 14), // "GetAllMessages"
QT_MOC_LITERAL(6, 56, 13), // "RegExpUpdated"
QT_MOC_LITERAL(7, 70, 19), // "RegExpSyntaxUpdated"
QT_MOC_LITERAL(8, 90, 19), // "OpenLogMasterDialog"
QT_MOC_LITERAL(9, 110, 8), // "ClearLog"
QT_MOC_LITERAL(10, 119, 5) // "Pause"

    },
    "GUILoggerGui\0NewMessages\0\0MsgSeries\0"
    "msgs\0GetAllMessages\0RegExpUpdated\0"
    "RegExpSyntaxUpdated\0OpenLogMasterDialog\0"
    "ClearLog\0Pause"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUILoggerGui[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,
       9,    0,   56,    2, 0x08 /* Private */,
      10,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GUILoggerGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GUILoggerGui *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NewMessages((*reinterpret_cast< const MsgSeries(*)>(_a[1]))); break;
        case 1: _t->GetAllMessages(); break;
        case 2: _t->RegExpUpdated(); break;
        case 3: _t->RegExpSyntaxUpdated(); break;
        case 4: _t->OpenLogMasterDialog(); break;
        case 5: _t->ClearLog(); break;
        case 6: _t->Pause(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GUILoggerGui::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GUILoggerGui.data,
    qt_meta_data_GUILoggerGui,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GUILoggerGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUILoggerGui::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GUILoggerGui.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GUILoggerGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
