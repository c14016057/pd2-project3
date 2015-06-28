/****************************************************************************
** Meta object code from reading C++ file 'gamewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../crush/gamewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gamewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_gamewindow_t {
    QByteArrayData data[12];
    char stringdata[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gamewindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gamewindow_t qt_meta_stringdata_gamewindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "gamewindow"
QT_MOC_LITERAL(1, 11, 4), // "quit"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 4), // "star"
QT_MOC_LITERAL(4, 22, 5), // "score"
QT_MOC_LITERAL(5, 28, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 50, 8), // "exchange"
QT_MOC_LITERAL(7, 59, 3), // "row"
QT_MOC_LITERAL(8, 63, 3), // "col"
QT_MOC_LITERAL(9, 67, 14), // "remove_by_type"
QT_MOC_LITERAL(10, 82, 4), // "type"
QT_MOC_LITERAL(11, 87, 9) // "colsegame"

    },
    "gamewindow\0quit\0\0star\0score\0"
    "on_pushButton_clicked\0exchange\0row\0"
    "col\0remove_by_type\0type\0colsegame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gamewindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   44,    2, 0x08 /* Private */,
       6,    2,   45,    2, 0x08 /* Private */,
       9,    3,   50,    2, 0x08 /* Private */,
      11,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    7,    8,   10,
    QMetaType::Void,

       0        // eod
};

void gamewindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        gamewindow *_t = static_cast<gamewindow *>(_o);
        switch (_id) {
        case 0: _t->quit((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->exchange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->remove_by_type((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->colsegame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (gamewindow::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&gamewindow::quit)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject gamewindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_gamewindow.data,
      qt_meta_data_gamewindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *gamewindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gamewindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_gamewindow.stringdata))
        return static_cast<void*>(const_cast< gamewindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int gamewindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void gamewindow::quit(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
