#include "vehiclefactory.h"

/* --------------------------------- VehicleFactory ------------------------------------ */

Car* VehicleFactory::createVehicle(const QString& type, int licensePlateYear, const QString& brand, FuelType fuelType, FuelType secondaryFuelType, MotorType motorType, float power, float capacity, float power2, float capacity2, float price) {
    if (type.toLower() == "coupe") {
        if (motorType == MotorType::HYBRID) {
            return new Coupe(licensePlateYear, brand, fuelType, secondaryFuelType, motorType, power, capacity, power2, capacity2, price);
        } else {
            return new Coupe(licensePlateYear, brand, fuelType, FuelType::NONE, motorType, power, capacity, 0, 0, price);
        }
    } else if (type.toLower() == "sedan") {
        if (motorType == MotorType::HYBRID) {
            return new Sedan(licensePlateYear, brand, fuelType, secondaryFuelType, motorType, power, capacity, power2, capacity2, price);
        } else {
            return new Sedan(licensePlateYear, brand, fuelType, FuelType::NONE, motorType, power, capacity, 0, 0, price);
        }
    } else {
        return nullptr;
    }
}

Motorcycle* VehicleFactory::createVehicle(const QString& type, bool hasFairing, int licensePlateYear, const QString& brand, FuelType fuelType, MotorType motorType, float power, float capacity, float price) {
    if ((type.toLower() == "motorcycle") && (motorType != MotorType::HYBRID)) {
        return new Motorcycle(hasFairing, licensePlateYear, brand, fuelType, motorType, power, capacity, price);
    } else {
        return nullptr;
    }
}
