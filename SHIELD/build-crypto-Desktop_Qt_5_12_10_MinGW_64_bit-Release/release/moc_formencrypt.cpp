/****************************************************************************
** Meta object code from reading C++ file 'formencrypt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../crypto/formencrypt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'formencrypt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FormEncrypt_t {
    QByteArrayData data[21];
    char stringdata0[224];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FormEncrypt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FormEncrypt_t qt_meta_stringdata_FormEncrypt = {
    {
QT_MOC_LITERAL(0, 0, 11), // "FormEncrypt"
QT_MOC_LITERAL(1, 12, 9), // "LetterSub"
QT_MOC_LITERAL(2, 22, 17), // "QMap<QChar,QChar>"
QT_MOC_LITERAL(3, 40, 0), // ""
QT_MOC_LITERAL(4, 41, 8), // "now_keys"
QT_MOC_LITERAL(5, 50, 5), // "start"
QT_MOC_LITERAL(6, 56, 3), // "end"
QT_MOC_LITERAL(7, 60, 15), // "SubLetterInText"
QT_MOC_LITERAL(8, 76, 4), // "text"
QT_MOC_LITERAL(9, 81, 7), // "setText"
QT_MOC_LITERAL(10, 89, 10), // "searchWord"
QT_MOC_LITERAL(11, 100, 15), // "checkWordOnTrue"
QT_MOC_LITERAL(12, 116, 8), // "LoadFile"
QT_MOC_LITERAL(13, 125, 4), // "WAIT"
QT_MOC_LITERAL(14, 130, 10), // "RecordList"
QT_MOC_LITERAL(15, 141, 12), // "resetViewKey"
QT_MOC_LITERAL(16, 154, 13), // "setDecryptKey"
QT_MOC_LITERAL(17, 168, 3), // "map"
QT_MOC_LITERAL(18, 172, 19), // "slotOnThreadPrognoz"
QT_MOC_LITERAL(19, 192, 9), // "RecordMap"
QT_MOC_LITERAL(20, 202, 21) // "on_pushButton_clicked"

    },
    "FormEncrypt\0LetterSub\0QMap<QChar,QChar>\0"
    "\0now_keys\0start\0end\0SubLetterInText\0"
    "text\0setText\0searchWord\0checkWordOnTrue\0"
    "LoadFile\0WAIT\0RecordList\0resetViewKey\0"
    "setDecryptKey\0map\0slotOnThreadPrognoz\0"
    "RecordMap\0on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FormEncrypt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   69,    3, 0x0a /* Public */,
       7,    2,   76,    3, 0x0a /* Public */,
       9,    1,   81,    3, 0x0a /* Public */,
      10,    0,   84,    3, 0x0a /* Public */,
      11,    1,   85,    3, 0x0a /* Public */,
      12,    0,   88,    3, 0x0a /* Public */,
      13,    1,   89,    3, 0x0a /* Public */,
      15,    0,   92,    3, 0x0a /* Public */,
      16,    1,   93,    3, 0x0a /* Public */,
      18,    1,   96,    3, 0x0a /* Public */,
      20,    0,   99,    3, 0x08 /* Private */,

 // slots: parameters
    0x80000000 | 2, 0x80000000 | 2, QMetaType::QString, QMetaType::QString,    4,    5,    6,
    QMetaType::QString, QMetaType::QString, 0x80000000 | 2,    8,    4,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Int, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 2,   17,
    QMetaType::Void, 0x80000000 | 19,    3,
    QMetaType::Void,

       0        // eod
};

void FormEncrypt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FormEncrypt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QMap<QChar,QChar> _r = _t->LetterSub((*reinterpret_cast< const QMap<QChar,QChar>(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QMap<QChar,QChar>*>(_a[0]) = std::move(_r); }  break;
        case 1: { QString _r = _t->SubLetterInText((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QMap<QChar,QChar>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->setText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->searchWord(); break;
        case 4: { int _r = _t->checkWordOnTrue((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->LoadFile(); break;
        case 6: _t->WAIT((*reinterpret_cast< RecordList(*)>(_a[1]))); break;
        case 7: _t->resetViewKey(); break;
        case 8: _t->setDecryptKey((*reinterpret_cast< const QMap<QChar,QChar>(*)>(_a[1]))); break;
        case 9: _t->slotOnThreadPrognoz((*reinterpret_cast< RecordMap(*)>(_a[1]))); break;
        case 10: _t->on_pushButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FormEncrypt::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_FormEncrypt.data,
    qt_meta_data_FormEncrypt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FormEncrypt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FormEncrypt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FormEncrypt.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int FormEncrypt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
