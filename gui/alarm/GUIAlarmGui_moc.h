/****************************************************************************
** Meta object code from reading C++ file 'GUIAlarmGui.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUIAlarmGui.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUIAlarmGui.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSGUIAlarmGuiENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSGUIAlarmGuiENDCLASS = QtMocHelpers::stringData(
    "GUIAlarmGui",
    "NewMessage",
    "",
    "cnt",
    "LMessage",
    "msg",
    "NewMessages2",
    "QMap<int,LMessage>",
    "msgs",
    "GetAllMessages"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGUIAlarmGuiENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[12];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[9];
    char stringdata5[4];
    char stringdata6[13];
    char stringdata7[19];
    char stringdata8[5];
    char stringdata9[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGUIAlarmGuiENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGUIAlarmGuiENDCLASS_t qt_meta_stringdata_CLASSGUIAlarmGuiENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "GUIAlarmGui"
        QT_MOC_LITERAL(12, 10),  // "NewMessage"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 3),  // "cnt"
        QT_MOC_LITERAL(28, 8),  // "LMessage"
        QT_MOC_LITERAL(37, 3),  // "msg"
        QT_MOC_LITERAL(41, 12),  // "NewMessages2"
        QT_MOC_LITERAL(54, 18),  // "QMap<int,LMessage>"
        QT_MOC_LITERAL(73, 4),  // "msgs"
        QT_MOC_LITERAL(78, 14)   // "GetAllMessages"
    },
    "GUIAlarmGui",
    "NewMessage",
    "",
    "cnt",
    "LMessage",
    "msg",
    "NewMessages2",
    "QMap<int,LMessage>",
    "msgs",
    "GetAllMessages"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGUIAlarmGuiENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   32,    2, 0x0a,    1 /* Public */,
       6,    1,   37,    2, 0x0a,    4 /* Public */,
       9,    0,   40,    2, 0x0a,    6 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject GUIAlarmGui::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSGUIAlarmGuiENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGUIAlarmGuiENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGUIAlarmGuiENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GUIAlarmGui, std::true_type>,
        // method 'NewMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const LMessage &, std::false_type>,
        // method 'NewMessages2'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QMap<int,LMessage> &, std::false_type>,
        // method 'GetAllMessages'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void GUIAlarmGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        auto *_t = static_cast<GUIAlarmGui *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->NewMessage((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<LMessage>>(_a[2]))); break;
        case 1: _t->NewMessages2((*reinterpret_cast< std::add_pointer_t<QMap<int,LMessage>>>(_a[1]))); break;
        case 2: _t->GetAllMessages(); break;
        default: ;
        }
    }
}

const QMetaObject *GUIAlarmGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUIAlarmGui::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGUIAlarmGuiENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GUIAlarmGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
