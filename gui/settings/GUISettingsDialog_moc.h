/****************************************************************************
** Meta object code from reading C++ file 'GUISettingsDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "GUISettingsDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GUISettingsDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GUISettingsDialog_t {
    QByteArrayData data[12];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GUISettingsDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GUISettingsDialog_t qt_meta_stringdata_GUISettingsDialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "GUISettingsDialog"
QT_MOC_LITERAL(1, 18, 15), // "DoRetranslateUi"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 11), // "UpdateStyle"
QT_MOC_LITERAL(4, 47, 9), // "OkClicked"
QT_MOC_LITERAL(5, 57, 18), // "CurrentItemChanged"
QT_MOC_LITERAL(6, 76, 14), // "settingsChoice"
QT_MOC_LITERAL(7, 91, 12), // "StyleChanged"
QT_MOC_LITERAL(8, 104, 5), // "style"
QT_MOC_LITERAL(9, 110, 15), // "LanguageChanged"
QT_MOC_LITERAL(10, 126, 8), // "language"
QT_MOC_LITERAL(11, 135, 13) // "RetranslateUi"

    },
    "GUISettingsDialog\0DoRetranslateUi\0\0"
    "UpdateStyle\0OkClicked\0CurrentItemChanged\0"
    "settingsChoice\0StyleChanged\0style\0"
    "LanguageChanged\0language\0RetranslateUi"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GUISettingsDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   51,    2, 0x0a /* Public */,
       5,    1,   52,    2, 0x0a /* Public */,
       7,    1,   55,    2, 0x0a /* Public */,
       9,    1,   58,    2, 0x0a /* Public */,
      11,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,

       0        // eod
};

void GUISettingsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GUISettingsDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DoRetranslateUi(); break;
        case 1: _t->UpdateStyle(); break;
        case 2: _t->OkClicked(); break;
        case 3: _t->CurrentItemChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->StyleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->LanguageChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->RetranslateUi(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GUISettingsDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUISettingsDialog::DoRetranslateUi)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GUISettingsDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GUISettingsDialog::UpdateStyle)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GUISettingsDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_GUISettingsDialog.data,
    qt_meta_data_GUISettingsDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GUISettingsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GUISettingsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GUISettingsDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int GUISettingsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void GUISettingsDialog::DoRetranslateUi()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void GUISettingsDialog::UpdateStyle()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
