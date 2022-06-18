/****************************************************************************
** Meta object code from reading C++ file 'GUICringAbsolutePos.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "GUICringAbsolutePos.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUICringAbsolutePos.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GUICringAbsolutePos_t {
    QByteArrayData data[15];
    char stringdata0[328];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUICringAbsolutePos_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUICringAbsolutePos_t qt_meta_stringdata_GUICringAbsolutePos = {
    {
QT_MOC_LITERAL(0, 0, 19), // "GUICringAbsolutePos"
QT_MOC_LITERAL(1, 20, 32), // "signalUpdateTextfieldTranslation"
QT_MOC_LITERAL(2, 53, 0), // ""
QT_MOC_LITERAL(3, 54, 11), // "translation"
QT_MOC_LITERAL(4, 66, 29), // "signalUpdateTextfieldRotation"
QT_MOC_LITERAL(5, 96, 8), // "rotation"
QT_MOC_LITERAL(6, 105, 35), // "signalApplyAbsolutePositionIn..."
QT_MOC_LITERAL(7, 141, 26), // "slotSetTranslationAbsolute"
QT_MOC_LITERAL(8, 168, 8), // "relValue"
QT_MOC_LITERAL(9, 177, 23), // "slotSetRotationAbsolute"
QT_MOC_LITERAL(10, 201, 30), // "slotUpdateTextfieldTranslation"
QT_MOC_LITERAL(11, 232, 27), // "slotUpdateTextfieldRotation"
QT_MOC_LITERAL(12, 260, 25), // "slotApplyAbsolutePosition"
QT_MOC_LITERAL(13, 286, 29), // "slotUpdateRevolutionsInternal"
QT_MOC_LITERAL(14, 316, 11) // "revolutions"

    },
    "GUICringAbsolutePos\0"
    "signalUpdateTextfieldTranslation\0\0"
    "translation\0signalUpdateTextfieldRotation\0"
    "rotation\0signalApplyAbsolutePositionInternal\0"
    "slotSetTranslationAbsolute\0relValue\0"
    "slotSetRotationAbsolute\0"
    "slotUpdateTextfieldTranslation\0"
    "slotUpdateTextfieldRotation\0"
    "slotApplyAbsolutePosition\0"
    "slotUpdateRevolutionsInternal\0revolutions"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUICringAbsolutePos[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       6,    2,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   70,    2, 0x0a /* Public */,
       9,    1,   73,    2, 0x0a /* Public */,
      10,    1,   76,    2, 0x0a /* Public */,
      11,    1,   79,    2, 0x0a /* Public */,
      12,    0,   82,    2, 0x0a /* Public */,
      13,    1,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    3,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

void GUICringAbsolutePos::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GUICringAbsolutePos *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalUpdateTextfieldTranslation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->signalUpdateTextfieldRotation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->signalApplyAbsolutePositionInternal((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 3: _t->slotSetTranslationAbsolute((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->slotSetRotationAbsolute((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->slotUpdateTextfieldTranslation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->slotUpdateTextfieldRotation((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->slotApplyAbsolutePosition(); break;
        case 8: _t->slotUpdateRevolutionsInternal((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GUICringAbsolutePos::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUICringAbsolutePos::signalUpdateTextfieldTranslation)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GUICringAbsolutePos::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUICringAbsolutePos::signalUpdateTextfieldRotation)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GUICringAbsolutePos::*)(double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUICringAbsolutePos::signalApplyAbsolutePositionInternal)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GUICringAbsolutePos::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GUICringAbsolutePos.data,
    qt_meta_data_GUICringAbsolutePos,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GUICringAbsolutePos::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUICringAbsolutePos::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GUICringAbsolutePos.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GUICringAbsolutePos::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void GUICringAbsolutePos::signalUpdateTextfieldTranslation(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GUICringAbsolutePos::signalUpdateTextfieldRotation(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GUICringAbsolutePos::signalApplyAbsolutePositionInternal(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
