/****************************************************************************
** Meta object code from reading C++ file 'createrule.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../createrule.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'createrule.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CreateRule_t {
    QByteArrayData data[12];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateRule_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateRule_t qt_meta_stringdata_CreateRule = {
    {
QT_MOC_LITERAL(0, 0, 10), // "CreateRule"
QT_MOC_LITERAL(1, 11, 15), // "AddRuleComplete"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 12), // "RuleTemplate"
QT_MOC_LITERAL(4, 41, 4), // "temp"
QT_MOC_LITERAL(5, 46, 7), // "AddRule"
QT_MOC_LITERAL(6, 54, 4), // "Rule"
QT_MOC_LITERAL(7, 59, 8), // "SolveDes"
QT_MOC_LITERAL(8, 68, 4), // "name"
QT_MOC_LITERAL(9, 73, 3), // "des"
QT_MOC_LITERAL(10, 77, 19), // "on_Create_triggered"
QT_MOC_LITERAL(11, 97, 22) // "on_pushButton_released"

    },
    "CreateRule\0AddRuleComplete\0\0RuleTemplate\0"
    "temp\0AddRule\0Rule\0SolveDes\0name\0des\0"
    "on_Create_triggered\0on_pushButton_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateRule[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   42,    2, 0x0a /* Public */,
       7,    2,   45,    2, 0x0a /* Public */,
      10,    0,   50,    2, 0x08 /* Private */,
      11,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    8,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CreateRule::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CreateRule *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->AddRuleComplete((*reinterpret_cast< RuleTemplate(*)>(_a[1]))); break;
        case 1: _t->AddRule((*reinterpret_cast< Rule(*)>(_a[1]))); break;
        case 2: _t->SolveDes((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->on_Create_triggered(); break;
        case 4: _t->on_pushButton_released(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CreateRule::*)(RuleTemplate );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CreateRule::AddRuleComplete)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CreateRule::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CreateRule.data,
    qt_meta_data_CreateRule,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CreateRule::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateRule::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CreateRule.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CreateRule::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CreateRule::AddRuleComplete(RuleTemplate _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
