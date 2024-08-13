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
    QByteArrayData data[17];
    char stringdata0[185];
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
QT_MOC_LITERAL(5, 46, 8), // "isRevise"
QT_MOC_LITERAL(6, 55, 14), // "makerule_clear"
QT_MOC_LITERAL(7, 70, 7), // "AddRule"
QT_MOC_LITERAL(8, 78, 4), // "Rule"
QT_MOC_LITERAL(9, 83, 8), // "SolveDes"
QT_MOC_LITERAL(10, 92, 4), // "name"
QT_MOC_LITERAL(11, 97, 3), // "des"
QT_MOC_LITERAL(12, 101, 15), // "ReceiveTemplate"
QT_MOC_LITERAL(13, 117, 4), // "Temp"
QT_MOC_LITERAL(14, 122, 19), // "on_Create_triggered"
QT_MOC_LITERAL(15, 142, 22), // "on_pushButton_released"
QT_MOC_LITERAL(16, 165, 19) // "on_Delete_triggered"

    },
    "CreateRule\0AddRuleComplete\0\0RuleTemplate\0"
    "temp\0isRevise\0makerule_clear\0AddRule\0"
    "Rule\0SolveDes\0name\0des\0ReceiveTemplate\0"
    "Temp\0on_Create_triggered\0"
    "on_pushButton_released\0on_Delete_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateRule[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,
       6,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   60,    2, 0x0a /* Public */,
       9,    2,   63,    2, 0x0a /* Public */,
      12,    1,   68,    2, 0x0a /* Public */,
      14,    0,   71,    2, 0x08 /* Private */,
      15,    0,   72,    2, 0x08 /* Private */,
      16,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,   11,
    QMetaType::Void, 0x80000000 | 3,   13,
    QMetaType::Void,
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
        case 0: _t->AddRuleComplete((*reinterpret_cast< RuleTemplate(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->makerule_clear(); break;
        case 2: _t->AddRule((*reinterpret_cast< Rule(*)>(_a[1]))); break;
        case 3: _t->SolveDes((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->ReceiveTemplate((*reinterpret_cast< RuleTemplate(*)>(_a[1]))); break;
        case 5: _t->on_Create_triggered(); break;
        case 6: _t->on_pushButton_released(); break;
        case 7: _t->on_Delete_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CreateRule::*)(RuleTemplate , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CreateRule::AddRuleComplete)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CreateRule::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CreateRule::makerule_clear)) {
                *result = 1;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void CreateRule::AddRuleComplete(RuleTemplate _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CreateRule::makerule_clear()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
