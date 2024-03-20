/****************************************************************************
** Meta object code from reading C++ file 'vehiclelist.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tp-01/vehiclelist.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vehiclelist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
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
struct qt_meta_stringdata_CLASSVehicleListENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSVehicleListENDCLASS = QtMocHelpers::stringData(
    "VehicleList",
    "findVehicleByID",
    "Vehicle*",
    "",
    "vehicleID",
    "addVehicle",
    "vehicle",
    "removeVehicleByID",
    "printVehicleList"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSVehicleListENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[12];
    char stringdata1[16];
    char stringdata2[9];
    char stringdata3[1];
    char stringdata4[10];
    char stringdata5[11];
    char stringdata6[8];
    char stringdata7[18];
    char stringdata8[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSVehicleListENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSVehicleListENDCLASS_t qt_meta_stringdata_CLASSVehicleListENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "VehicleList"
        QT_MOC_LITERAL(12, 15),  // "findVehicleByID"
        QT_MOC_LITERAL(28, 8),  // "Vehicle*"
        QT_MOC_LITERAL(37, 0),  // ""
        QT_MOC_LITERAL(38, 9),  // "vehicleID"
        QT_MOC_LITERAL(48, 10),  // "addVehicle"
        QT_MOC_LITERAL(59, 7),  // "vehicle"
        QT_MOC_LITERAL(67, 17),  // "removeVehicleByID"
        QT_MOC_LITERAL(85, 16)   // "printVehicleList"
    },
    "VehicleList",
    "findVehicleByID",
    "Vehicle*",
    "",
    "vehicleID",
    "addVehicle",
    "vehicle",
    "removeVehicleByID",
    "printVehicleList"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSVehicleListENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   38,    3, 0x02,    1 /* Public */,
       5,    1,   41,    3, 0x02,    3 /* Public */,
       7,    1,   44,    3, 0x02,    5 /* Public */,
       8,    0,   47,    3, 0x102,    7 /* Public | MethodIsConst  */,

 // methods: parameters
    0x80000000 | 2, QMetaType::Int,    4,
    QMetaType::Int, 0x80000000 | 2,    6,
    QMetaType::Int, QMetaType::Int,    4,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject VehicleList::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSVehicleListENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSVehicleListENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSVehicleListENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<VehicleList, std::true_type>,
        // method 'findVehicleByID'
        QtPrivate::TypeAndForceComplete<Vehicle *, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'addVehicle'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<Vehicle *, std::false_type>,
        // method 'removeVehicleByID'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'printVehicleList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void VehicleList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VehicleList *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { Vehicle* _r = _t->findVehicleByID((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< Vehicle**>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->addVehicle((*reinterpret_cast< std::add_pointer_t<Vehicle*>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->removeVehicleByID((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->printVehicleList(); break;
        default: ;
        }
    }
}

const QMetaObject *VehicleList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VehicleList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSVehicleListENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VehicleList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
