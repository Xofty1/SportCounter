/****************************************************************************
** Meta object code from reading C++ file 'createcompetition.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../createcompetition.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'createcompetition.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CreateCompetition_t {
    QByteArrayData data[10];
    char stringdata0[232];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateCompetition_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateCompetition_t qt_meta_stringdata_CreateCompetition = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CreateCompetition"
QT_MOC_LITERAL(1, 18, 11), // "signalGroup"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 15), // "vector<double>*"
QT_MOC_LITERAL(4, 47, 21), // "signalCompetitionType"
QT_MOC_LITERAL(5, 69, 31), // "on_pushButton_add_group_clicked"
QT_MOC_LITERAL(6, 101, 34), // "on_pushButton_delete_group_cl..."
QT_MOC_LITERAL(7, 136, 26), // "on_pushButton_back_clicked"
QT_MOC_LITERAL(8, 163, 36), // "on_radioButton_olympic_games_..."
QT_MOC_LITERAL(9, 200, 31) // "on_radioButton_biathlon_clicked"

    },
    "CreateCompetition\0signalGroup\0\0"
    "vector<double>*\0signalCompetitionType\0"
    "on_pushButton_add_group_clicked\0"
    "on_pushButton_delete_group_clicked\0"
    "on_pushButton_back_clicked\0"
    "on_radioButton_olympic_games_clicked\0"
    "on_radioButton_biathlon_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateCompetition[] = {

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
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   55,    2, 0x08 /* Private */,
       6,    0,   56,    2, 0x08 /* Private */,
       7,    0,   57,    2, 0x08 /* Private */,
       8,    0,   58,    2, 0x08 /* Private */,
       9,    0,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CreateCompetition::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CreateCompetition *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signalGroup((*reinterpret_cast< vector<double>*(*)>(_a[1]))); break;
        case 1: _t->signalCompetitionType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_add_group_clicked(); break;
        case 3: _t->on_pushButton_delete_group_clicked(); break;
        case 4: _t->on_pushButton_back_clicked(); break;
        case 5: _t->on_radioButton_olympic_games_clicked(); break;
        case 6: _t->on_radioButton_biathlon_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CreateCompetition::*)(vector<double> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CreateCompetition::signalGroup)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CreateCompetition::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CreateCompetition::signalCompetitionType)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CreateCompetition::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_CreateCompetition.data,
    qt_meta_data_CreateCompetition,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CreateCompetition::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateCompetition::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CreateCompetition.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CreateCompetition::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void CreateCompetition::signalGroup(vector<double> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CreateCompetition::signalCompetitionType(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
