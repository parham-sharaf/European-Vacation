/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[32];
    char stringdata0[268];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 11), // "itemChanged"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(41, 11), // "updateSpent"
QT_MOC_LITERAL(53, 7), // "setPlan"
QT_MOC_LITERAL(61, 12), // "adminNewCity"
QT_MOC_LITERAL(74, 16), // "adminChangePrice"
QT_MOC_LITERAL(91, 12), // "adminAddFood"
QT_MOC_LITERAL(104, 12), // "adminDelFood"
QT_MOC_LITERAL(117, 24), // "on_actionLogin_triggered"
QT_MOC_LITERAL(142, 37), // "on_updatepurchases_pushButton..."
QT_MOC_LITERAL(180, 21), // "on_submitPlan_clicked"
QT_MOC_LITERAL(202, 20), // "on_clearPlan_clicked"
QT_MOC_LITERAL(223, 39), // "on_citiesFromLondon_LineEdit_..."
QT_MOC_LITERAL(263, 4) // "arg1"

    },
    "MainWindow\0itemChanged\0\0QTreeWidgetItem*\0"
    "updateSpent\0setPlan\0adminNewCity\0"
    "adminChangePrice\0adminAddFood\0"
    "adminDelFood\0on_actionLogin_triggered\0"
    "on_updatepurchases_pushButton_clicked\0"
    "on_submitPlan_clicked\0on_clearPlan_clicked\0"
    "on_citiesFromLondon_LineEdit_textEdited\0"
    "arg1"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   86,    2, 0x0a,    0 /* Public */,
       4,    0,   91,    2, 0x0a,    3 /* Public */,
       5,    2,   92,    2, 0x0a,    4 /* Public */,
       6,    0,   97,    2, 0x0a,    7 /* Public */,
       7,    0,   98,    2, 0x0a,    8 /* Public */,
       8,    0,   99,    2, 0x0a,    9 /* Public */,
       9,    0,  100,    2, 0x0a,   10 /* Public */,
      10,    0,  101,    2, 0x08,   11 /* Private */,
      11,    0,  102,    2, 0x08,   12 /* Private */,
      12,    0,  103,    2, 0x08,   13 /* Private */,
      13,    0,  104,    2, 0x08,   14 /* Private */,
      14,    1,  105,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->itemChanged((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->updateSpent(); break;
        case 2: _t->setPlan((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->adminNewCity(); break;
        case 4: _t->adminChangePrice(); break;
        case 5: _t->adminAddFood(); break;
        case 6: _t->adminDelFood(); break;
        case 7: _t->on_actionLogin_triggered(); break;
        case 8: _t->on_updatepurchases_pushButton_clicked(); break;
        case 9: _t->on_submitPlan_clicked(); break;
        case 10: _t->on_clearPlan_clicked(); break;
        case 11: _t->on_citiesFromLondon_LineEdit_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t

, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QTreeWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
