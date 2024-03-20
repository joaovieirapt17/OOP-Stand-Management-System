#ifndef UTILS_H
#define UTILS_H

#include <QFile>
#include <QTextStream>

#include "vehicle.h"
#include "car.h"
#include "user.h"

enum class Role;

QString fuelTypeToString(FuelType fuelType);
FuelType stringToFuelType(const QString &fuelTypeString);
QString motorTypeToString(MotorType motorType);
MotorType stringToMotorType(const QString& motorTypeString);
void writeVehicleDataToFile(QFile& file, const VehicleList* vehicleList);
QString roleToString(Role role);
Role stringToRole(const QString& roleString);

#endif // UTILS_H
