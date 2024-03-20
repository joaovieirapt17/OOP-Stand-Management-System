#include "vehiclefactory.h"

using namespace std;

/* --------------------------------- VehicleFactory ------------------------------------ */

Car* VehicleFactory::createVehicle(const string& type, int licensePlateYear, const string& brand, FuelType fuelType, FuelType secondaryFuelType, MotorType motorType, float power, float capacity, float power2, float capacity2, float price) {
    if (type == "coupe") {
        if (motorType == MotorType::HYBRID) {
            return new Coupe(licensePlateYear, brand, fuelType, secondaryFuelType, motorType, power, capacity, power2, capacity2, price);
        } else {
            return new Coupe(licensePlateYear, brand, fuelType, FuelType::NONE, motorType, power, capacity, 0, 0, price);
        }
    } else if (type == "sedan") {
        if (motorType == MotorType::HYBRID) {
            return new Sedan(licensePlateYear, brand, fuelType, secondaryFuelType, motorType, power, capacity, power2, capacity2, price);
        } else {
            return new Sedan(licensePlateYear, brand, fuelType, FuelType::NONE, motorType, power, capacity, 0, 0, price);
        }
    } else {
        return nullptr;
    }
}

Motorcycle* VehicleFactory::createVehicle(const string& type, bool hasFairing, int licensePlateYear, const string& brand, FuelType fuelType,MotorType motorType ,float power ,float capacity, float price) {
    if ((type == "motorcycle")&&(motorType != MotorType::HYBRID)) {
        return new Motorcycle(hasFairing, licensePlateYear, brand, fuelType,motorType, power, capacity, price);
    } else {
        return nullptr;
    }
}
