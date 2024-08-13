/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata0[287];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "EditTemplate"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "RuleTemplate"
QT_MOC_LITERAL(4, 38, 8), // "Template"
QT_MOC_LITERAL(5, 47, 19), // "on_Create_triggered"
QT_MOC_LITERAL(6, 67, 19), // "AddTemplateFinished"
QT_MOC_LITERAL(7, 87, 4), // "temp"
QT_MOC_LITERAL(8, 92, 8), // "isRevise"
QT_MOC_LITERAL(9, 101, 19), // "on_action_triggered"
QT_MOC_LITERAL(10, 121, 25), // "on_action_Excel_triggered"
QT_MOC_LITERAL(11, 147, 19), // "on_Export_triggered"
QT_MOC_LITERAL(12, 167, 19), // "on_Import_triggered"
QT_MOC_LITERAL(13, 187, 19), // "on_Delete_triggered"
QT_MOC_LITERAL(14, 207, 17), // "on_Edit_triggered"
QT_MOC_LITERAL(15, 225, 19), // "on_Rename_triggered"
QT_MOC_LITERAL(16, 245, 17), // "on_Copy_triggered"
QT_MOC_LITERAL(17, 263, 14), // "ReNameComplete"
QT_MOC_LITERAL(18, 278, 4), // "Name"
QT_MOC_LITERAL(19, 283, 3) // "Des"

    },
    "MainWindow\0EditTemplate\0\0RuleTemplate\0"
    "Template\0on_Create_triggered\0"
    "AddTemplateFinished\0temp\0isRevise\0"
    "on_action_triggered\0on_action_Excel_triggered\0"
    "on_Export_triggered\0on_Import_triggered\0"
    "on_Delete_triggered\0on_Edit_triggered\0"
    "on_Rename_triggered\0on_Copy_triggered\0"
    "ReNameComplete\0Name\0Des"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   77,    2, 0x08 /* Private */,
       6,    2,   78,    2, 0x08 /* Private */,
       9,    0,   83,    2, 0x08 /* Private */,
      10,    0,   84,    2, 0x08 /* Private */,
      11,    0,   85,    2, 0x08 /* Private */,
      12,    0,   86,    2, 0x08 /* Private */,
      13,    0,   87,    2, 0x08 /* Private */,
      14,    0,   88,    2, 0x08 /* Private */,
      15,    0,   89,    2, 0x08 /* Private */,
      16,    0,   90,    2, 0x08 /* Private */,
      17,    2,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   18,   19,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->EditTemplate((*reinterpret_cast< RuleTemplate(*)>(_a[1]))); break;
        case 1: _t->on_Create_triggered(); break;
        case 2: _t->AddTemplateFinished((*reinterpret_cast< RuleTemplate(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->on_action_triggered(); break;
        case 4: _t->on_action_Excel_triggered(); break;
        case 5: _t->on_Export_triggered(); break;
        case 6: _t->on_Import_triggered(); break;
        case 7: _t->on_Delete_triggered(); break;
        case 8: _t->on_Edit_triggered(); break;
        case 9: _t->on_Rename_triggered(); break;
        case 10: _t->on_Copy_triggered(); break;
        case 11: _t->ReNameComplete((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(RuleTemplate );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::EditTemplate)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::EditTemplate(RuleTemplate _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
