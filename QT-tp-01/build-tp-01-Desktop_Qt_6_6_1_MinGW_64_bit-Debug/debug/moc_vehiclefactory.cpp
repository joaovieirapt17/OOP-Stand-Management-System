/****************************************************************************
** Meta object code from reading C++ file 'vehiclefactory.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../tp-01/vehiclefactory.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'vehiclefactory.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSVehicleFactoryENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSVehicleFactoryENDCLASS = QtMocHelpers::stringData(
    "VehicleFactory",
    "createVehicle",
    "Car*",
    "",
    "type",
    "licensePlateYear",
    "brand",
    "FuelType",
    "fuelType",
    "secondaryFuelType",
    "MotorType",
    "motorType",
    "power",
    "capacity",
    "power2",
    "capacity2",
    "price",
    "Motorcycle*",
    "hasFairing"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSVehicleFactoryENDCLASS_t {
    uint offsetsAndSizes[38];
    char stringdata0[15];
    char stringdata1[14];
    char stringdata2[5];
    char stringdata3[1];
    char stringdata4[5];
    char stringdata5[17];
    char stringdata6[6];
    char stringdata7[9];
    char stringdata8[9];
    char stringdata9[18];
    char stringdata10[10];
    char stringdata11[10];
    char stringdata12[6];
    char stringdata13[9];
    char stringdata14[7];
    char stringdata15[10];
    char stringdata16[6];
    char stringdata17[12];
    char stringdata18[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSVehicleFactoryENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSVehicleFactoryENDCLASS_t qt_meta_stringdata_CLASSVehicleFactoryENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "VehicleFactory"
        QT_MOC_LITERAL(15, 13),  // "createVehicle"
        QT_MOC_LITERAL(29, 4),  // "Car*"
        QT_MOC_LITERAL(34, 0),  // ""
        QT_MOC_LITERAL(35, 4),  // "type"
        QT_MOC_LITERAL(40, 16),  // "licensePlateYear"
        QT_MOC_LITERAL(57, 5),  // "brand"
        QT_MOC_LITERAL(63, 8),  // "FuelType"
        QT_MOC_LITERAL(72, 8),  // "fuelType"
        QT_MOC_LITERAL(81, 17),  // "secondaryFuelType"
        QT_MOC_LITERAL(99, 9),  // "MotorType"
        QT_MOC_LITERAL(109, 9),  // "motorType"
        QT_MOC_LITERAL(119, 5),  // "power"
        QT_MOC_LITERAL(125, 8),  // "capacity"
        QT_MOC_LITERAL(134, 6),  // "power2"
        QT_MOC_LITERAL(141, 9),  // "capacity2"
        QT_MOC_LITERAL(151, 5),  // "price"
        QT_MOC_LITERAL(157, 11),  // "Motorcycle*"
        QT_MOC_LITERAL(169, 10)   // "hasFairing"
    },
    "VehicleFactory",
    "createVehicle",
    "Car*",
    "",
    "type",
    "licensePlateYear",
    "brand",
    "FuelType",
    "fuelType",
    "secondaryFuelType",
    "MotorType",
    "motorType",
    "power",
    "capacity",
    "power2",
    "capacity2",
    "price",
    "Motorcycle*",
    "hasFairing"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSVehicleFactoryENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
       1,   11,   26,    3, 0x02,    1 /* Public */,
       1,    9,   49,    3, 0x02,   13 /* Public */,

 // methods: parameters
    0x80000000 | 2, QMetaType::QString, QMetaType::Int, QMetaType::QString, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 10, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float, QMetaType::Float,    4,    5,    6,    8,    9,   11,   12,   13,   14,   15,   16,
    0x80000000 | 17, QMetaType::QString, QMetaType::Bool, QMetaType::Int, QMetaType::QString, 0x80000000 | 7, 0x80000000 | 10, QMetaType::Float, QMetaType::Float, QMetaType::Float,    4,   18,    5,    6,    8,   11,   12,   13,   16,

       0        // eod
};

Q_CONSTINIT const QMetaObject VehicleFactory::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSVehicleFactoryENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSVehicleFactoryENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSVehicleFactoryENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<VehicleFactory, std::true_type>,
        // method 'createVehicle'
        QtPrivate::TypeAndForceComplete<Car *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<FuelType, std::false_type>,
        QtPrivate::TypeAndForceComplete<FuelType, std::false_type>,
        QtPrivate::TypeAndForceComplete<MotorType, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        // method 'createVehicle'
        QtPrivate::TypeAndForceComplete<Motorcycle *, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<FuelType, std::false_type>,
        QtPrivate::TypeAndForceComplete<MotorType, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>,
        QtPrivate::TypeAndForceComplete<float, std::false_type>
    >,
    nullptr
} };

void VehicleFactory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<VehicleFactory *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { Car* _r = _t->createVehicle((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<FuelType>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<FuelType>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<MotorType>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[9])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[10])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[11])));
            if (_a[0]) *reinterpret_cast< Car**>(_a[0]) = std::move(_r); }  break;
        case 1: { Motorcycle* _r = _t->createVehicle((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<FuelType>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<MotorType>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[7])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[8])),(*reinterpret_cast< std::add_pointer_t<float>>(_a[9])));
            if (_a[0]) *reinterpret_cast< Motorcycle**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *VehicleFactory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VehicleFactory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSVehicleFactoryENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int VehicleFactory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
