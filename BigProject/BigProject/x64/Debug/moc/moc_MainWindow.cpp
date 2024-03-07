/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../MainWindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "onAddSongPressed",
    "",
    "onRemoveSongPressed",
    "onSortTitlePressed",
    "onSortArtistPressed",
    "onViewLyricsPressed",
    "onCreatePlaylistPressed",
    "onAddFilePressed",
    "onWindowSignal",
    "onAddPlaylistPressed",
    "onRemovePlaylistPressed",
    "onPlaySongPressed"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[11];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[19];
    char stringdata5[20];
    char stringdata6[20];
    char stringdata7[24];
    char stringdata8[17];
    char stringdata9[15];
    char stringdata10[21];
    char stringdata11[24];
    char stringdata12[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 16),  // "onAddSongPressed"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 19),  // "onRemoveSongPressed"
        QT_MOC_LITERAL(49, 18),  // "onSortTitlePressed"
        QT_MOC_LITERAL(68, 19),  // "onSortArtistPressed"
        QT_MOC_LITERAL(88, 19),  // "onViewLyricsPressed"
        QT_MOC_LITERAL(108, 23),  // "onCreatePlaylistPressed"
        QT_MOC_LITERAL(132, 16),  // "onAddFilePressed"
        QT_MOC_LITERAL(149, 14),  // "onWindowSignal"
        QT_MOC_LITERAL(164, 20),  // "onAddPlaylistPressed"
        QT_MOC_LITERAL(185, 23),  // "onRemovePlaylistPressed"
        QT_MOC_LITERAL(209, 17)   // "onPlaySongPressed"
    },
    "MainWindow",
    "onAddSongPressed",
    "",
    "onRemoveSongPressed",
    "onSortTitlePressed",
    "onSortArtistPressed",
    "onViewLyricsPressed",
    "onCreatePlaylistPressed",
    "onAddFilePressed",
    "onWindowSignal",
    "onAddPlaylistPressed",
    "onRemovePlaylistPressed",
    "onPlaySongPressed"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x0a,    1 /* Public */,
       3,    0,   81,    2, 0x0a,    2 /* Public */,
       4,    0,   82,    2, 0x0a,    3 /* Public */,
       5,    0,   83,    2, 0x0a,    4 /* Public */,
       6,    0,   84,    2, 0x0a,    5 /* Public */,
       7,    0,   85,    2, 0x0a,    6 /* Public */,
       8,    0,   86,    2, 0x0a,    7 /* Public */,
       9,    0,   87,    2, 0x0a,    8 /* Public */,
      10,    0,   88,    2, 0x0a,    9 /* Public */,
      11,    0,   89,    2, 0x0a,   10 /* Public */,
      12,    0,   90,    2, 0x0a,   11 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'onAddSongPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRemoveSongPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSortTitlePressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSortArtistPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onViewLyricsPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCreatePlaylistPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddFilePressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onWindowSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onAddPlaylistPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRemovePlaylistPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onPlaySongPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onAddSongPressed(); break;
        case 1: _t->onRemoveSongPressed(); break;
        case 2: _t->onSortTitlePressed(); break;
        case 3: _t->onSortArtistPressed(); break;
        case 4: _t->onViewLyricsPressed(); break;
        case 5: _t->onCreatePlaylistPressed(); break;
        case 6: _t->onAddFilePressed(); break;
        case 7: _t->onWindowSignal(); break;
        case 8: _t->onAddPlaylistPressed(); break;
        case 9: _t->onRemovePlaylistPressed(); break;
        case 10: _t->onPlaySongPressed(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
