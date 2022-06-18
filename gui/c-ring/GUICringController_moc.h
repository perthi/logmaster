/****************************************************************************
** Meta object code from reading C++ file 'GUICringController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "GUICringController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUICringController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GUICringController_t {
    QByteArrayData data[16];
    char stringdata0[271];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUICringController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUICringController_t qt_meta_stringdata_GUICringController = {
    {
QT_MOC_LITERAL(0, 0, 18), // "GUICringController"
QT_MOC_LITERAL(1, 19, 30), // "signalUpdateTranslationFromAPI"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 5), // "value"
QT_MOC_LITERAL(4, 57, 27), // "signalUpdateRotationFromAPI"
QT_MOC_LITERAL(5, 85, 30), // "signalUpdateRevolutionsFromAPI"
QT_MOC_LITERAL(6, 116, 18), // "slotRelativeMotion"
QT_MOC_LITERAL(7, 135, 9), // "direction"
QT_MOC_LITERAL(8, 145, 19), // "slotContinousMotion"
QT_MOC_LITERAL(9, 165, 19), // "slotDemoToggleMotor"
QT_MOC_LITERAL(10, 185, 17), // "slotDemoToggleLED"
QT_MOC_LITERAL(11, 203, 12), // "slotSoftStop"
QT_MOC_LITERAL(12, 216, 12), // "slotHardStop"
QT_MOC_LITERAL(13, 229, 20), // "slotAbsolutePosition"
QT_MOC_LITERAL(14, 250, 11), // "translation"
QT_MOC_LITERAL(15, 262, 8) // "rotation"

    },
    "GUICringController\0signalUpdateTranslationFromAPI\0"
    "\0value\0signalUpdateRotationFromAPI\0"
    "signalUpdateRevolutionsFromAPI\0"
    "slotRelativeMotion\0direction\0"
    "slotContinousMotion\0slotDemoToggleMotor\0"
    "slotDemoToggleLED\0slotSoftStop\0"
    "slotHardStop\0slotAbsolutePosition\0"
    "translation\0rotation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUICringController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       5,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    2,   73,    2, 0x08 /* Private */,
       8,    1,   78,    2, 0x08 /* Private */,
       9,    0,   81,    2, 0x08 /* Private */,
      10,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    2,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Double,    7,    3,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   14,   15,

       0        // eod
};

void GUICringController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GUICringController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalUpdateTranslationFromAPI((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->signalUpdateRotationFromAPI((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->signalUpdateRevolutionsFromAPI((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->slotRelativeMotion((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 4: _t->slotContinousMotion((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->slotDemoToggleMotor(); break;
        case 6: _t->slotDemoToggleLED(); break;
        case 7: _t->slotSoftStop(); break;
        case 8: _t->slotHardStop(); break;
        case 9: _t->slotAbsolutePosition((*reinterpret_cast< const double(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GUICringController::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUICringController::signalUpdateTranslationFromAPI)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GUICringController::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUICringController::signalUpdateRotationFromAPI)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (GUICringController::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUICringController::signalUpdateRevolutionsFromAPI)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GUICringController::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GUICringController.data,
    qt_meta_data_GUICringController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GUICringController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUICringController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GUICringController.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GUICringController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void GUICringController::signalUpdateTranslationFromAPI(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GUICringController::signalUpdateRotationFromAPI(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void GUICringController::signalUpdateRevolutionsFromAPI(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
