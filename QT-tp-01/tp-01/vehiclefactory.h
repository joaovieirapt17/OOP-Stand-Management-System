#ifndef VEHICLEFACTORY_H
#define VEHICLEFACTORY_H

#include "car.h"

class VehicleFactory : public QObject {
    Q_OBJECT

public:
    Q_INVOKABLE static Car *createVehicle(const QString &type, int licensePlateYear, const QString &brand, FuelType fuelType, FuelType secondaryFuelType, MotorType motorType, float power, float capacity, float power2, float capacity2, float price);
    Q_INVOKABLE static Motorcycle *createVehicle(const QString &type, bool hasFairing, int licensePlateYear, const QString &brand, FuelType fuelType, MotorType motorType, float power, float capacity, float price);
};

#endif // VEHICLEFACTORY_H
