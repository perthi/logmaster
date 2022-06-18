/****************************************************************************
** Meta object code from reading C++ file 'GUICringGraphicalIndicators.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "GUICringGraphicalIndicators.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUICringGraphicalIndicators.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GUICringGraphicalIndicators_t {
    QByteArrayData data[7];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUICringGraphicalIndicators_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUICringGraphicalIndicators_t qt_meta_stringdata_GUICringGraphicalIndicators = {
    {
QT_MOC_LITERAL(0, 0, 27), // "GUICringGraphicalIndicators"
QT_MOC_LITERAL(1, 28, 17), // "slotTranslationC1"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 11), // "translation"
QT_MOC_LITERAL(4, 59, 17), // "slotTranslationC2"
QT_MOC_LITERAL(5, 77, 12), // "slotRotation"
QT_MOC_LITERAL(6, 90, 8) // "rotation"

    },
    "GUICringGraphicalIndicators\0"
    "slotTranslationC1\0\0translation\0"
    "slotTranslationC2\0slotRotation\0rotation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUICringGraphicalIndicators[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    1,   32,    2, 0x0a /* Public */,
       5,    1,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    6,

       0        // eod
};

void GUICringGraphicalIndicators::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GUICringGraphicalIndicators *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotTranslationC1((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 1: _t->slotTranslationC2((*reinterpret_cast< const double(*)>(_a[1]))); break;
        case 2: _t->slotRotation((*reinterpret_cast< const double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GUICringGraphicalIndicators::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GUICringGraphicalIndicators.data,
    qt_meta_data_GUICringGraphicalIndicators,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GUICringGraphicalIndicators::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUICringGraphicalIndicators::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GUICringGraphicalIndicators.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GUICringGraphicalIndicators::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
