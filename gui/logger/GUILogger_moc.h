/****************************************************************************
** Meta object code from reading C++ file 'GUILogger.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUILogger.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUILogger.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSGUILoggerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSGUILoggerENDCLASS = QtMocHelpers::stringData(
    "GUILogger",
    "newMessages",
    "",
    "MsgSeries",
    "msgs",
    "newMessage",
    "cnt",
    "LMessage",
    "msg"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGUILoggerENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[10];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[5];
    char stringdata5[11];
    char stringdata6[4];
    char stringdata7[9];
    char stringdata8[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGUILoggerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGUILoggerENDCLASS_t qt_meta_stringdata_CLASSGUILoggerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "GUILogger"
        QT_MOC_LITERAL(10, 11),  // "newMessages"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 9),  // "MsgSeries"
        QT_MOC_LITERAL(33, 4),  // "msgs"
        QT_MOC_LITERAL(38, 10),  // "newMessage"
        QT_MOC_LITERAL(49, 3),  // "cnt"
        QT_MOC_LITERAL(53, 8),  // "LMessage"
        QT_MOC_LITERAL(62, 3)   // "msg"
    },
    "GUILogger",
    "newMessages",
    "",
    "MsgSeries",
    "msgs",
    "newMessage",
    "cnt",
    "LMessage",
    "msg"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGUILoggerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    2,   29,    2, 0x0a,    3 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 7,    6,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject GUILogger::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSGUILoggerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGUILoggerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGUILoggerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GUILogger, std::true_type>,
        // method 'newMessages'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const MsgSeries &, std::false_type>,
        // method 'newMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const LMessage &, std::false_type>
    >,
    nullptr
} };

void GUILogger::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        auto *_t = static_cast<GUILogger *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newMessages((*reinterpret_cast< std::add_pointer_t<MsgSeries>>(_a[1]))); break;
        case 1: _t->newMessage((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<LMessage>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GUILogger::*)(const MsgSeries & );
            if (_t _q_method = &GUILogger::newMessages; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *GUILogger::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUILogger::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGUILoggerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "GUILoggerBase"))
        return static_cast< GUILoggerBase*>(this);
    return QObject::qt_metacast(_clname);
}

int GUILogger::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void GUILogger::newMessages(const MsgSeries & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
