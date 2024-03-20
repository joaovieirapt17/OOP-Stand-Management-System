#ifndef VEHICLEFACTORY_H
#define VEHICLEFACTORY_H

#include "car.h"

class VehicleFactory {
public:
    static Car *createVehicle(const std::string &type, int licensePlateYear, const std::string &brand, FuelType fuelType, FuelType secondaryFuelType, MotorType motorType, float power, float capacity, float power2, float capacity2, float price);
    static Motorcycle *createVehicle(const std::string &type, bool hasFairing, int licensePlateYear, const std::string &brand, FuelType fuelType,MotorType motorType, float power, float capacity, float price);
};

#endif //VEHICLEFACTORY_H
