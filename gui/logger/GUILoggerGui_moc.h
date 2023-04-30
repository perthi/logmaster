/****************************************************************************
** Meta object code from reading C++ file 'GUILoggerGui.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GUILoggerGui.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUILoggerGui.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSGUILoggerGuiENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSGUILoggerGuiENDCLASS = QtMocHelpers::stringData(
    "GUILoggerGui",
    "NewMessages",
    "",
    "MsgSeries",
    "msgs",
    "GetAllMessages",
    "RegExpUpdated",
    "RegExpSyntaxUpdated",
    "OpenLogMasterDialog",
    "ClearLog",
    "Pause"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSGUILoggerGuiENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[13];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[10];
    char stringdata4[5];
    char stringdata5[15];
    char stringdata6[14];
    char stringdata7[20];
    char stringdata8[20];
    char stringdata9[9];
    char stringdata10[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSGUILoggerGuiENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSGUILoggerGuiENDCLASS_t qt_meta_stringdata_CLASSGUILoggerGuiENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "GUILoggerGui"
        QT_MOC_LITERAL(13, 11),  // "NewMessages"
        QT_MOC_LITERAL(25, 0),  // ""
        QT_MOC_LITERAL(26, 9),  // "MsgSeries"
        QT_MOC_LITERAL(36, 4),  // "msgs"
        QT_MOC_LITERAL(41, 14),  // "GetAllMessages"
        QT_MOC_LITERAL(56, 13),  // "RegExpUpdated"
        QT_MOC_LITERAL(70, 19),  // "RegExpSyntaxUpdated"
        QT_MOC_LITERAL(90, 19),  // "OpenLogMasterDialog"
        QT_MOC_LITERAL(110, 8),  // "ClearLog"
        QT_MOC_LITERAL(119, 5)   // "Pause"
    },
    "GUILoggerGui",
    "NewMessages",
    "",
    "MsgSeries",
    "msgs",
    "GetAllMessages",
    "RegExpUpdated",
    "RegExpSyntaxUpdated",
    "OpenLogMasterDialog",
    "ClearLog",
    "Pause"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGUILoggerGuiENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x08,    1 /* Private */,
       5,    0,   59,    2, 0x08,    3 /* Private */,
       6,    0,   60,    2, 0x08,    4 /* Private */,
       7,    0,   61,    2, 0x08,    5 /* Private */,
       8,    0,   62,    2, 0x08,    6 /* Private */,
       9,    0,   63,    2, 0x08,    7 /* Private */,
      10,    0,   64,    2, 0x08,    8 /* Private */,

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

Q_CONSTINIT const QMetaObject GUILoggerGui::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSGUILoggerGuiENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGUILoggerGuiENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGUILoggerGuiENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GUILoggerGui, std::true_type>,
        // method 'NewMessages'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const MsgSeries &, std::false_type>,
        // method 'GetAllMessages'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RegExpUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'RegExpSyntaxUpdated'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OpenLogMasterDialog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ClearLog'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Pause'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void GUILoggerGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        auto *_t = static_cast<GUILoggerGui *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->NewMessages((*reinterpret_cast< std::add_pointer_t<MsgSeries>>(_a[1]))); break;
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

const QMetaObject *GUILoggerGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUILoggerGui::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGUILoggerGuiENDCLASS.stringdata0))
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
