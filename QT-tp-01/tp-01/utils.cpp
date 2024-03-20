#include <QTextStream>
#include <QDebug>

#include "utils.h"
#include "vehicle.h"
#include "car.h"


QString fuelTypeToString(FuelType fuelType) {
    switch (fuelType) {
    case FuelType::DIESEL:
        return "diesel";
    case FuelType::ELECTRICITY:
        return "electric";
    case FuelType::GASOLINE:
        return "gasoline";
    case FuelType::LPG:
        return "lpg";
    case FuelType::NONE:
        return "none";
    default:
        return "unknown";
    }
}

FuelType stringToFuelType(const QString &fuelTypeString) {
    if (fuelTypeString == "diesel") {
        return FuelType::DIESEL;
    } else if (fuelTypeString == "electric") {
        return FuelType::ELECTRICITY;
    } else if (fuelTypeString == "gasoline") {
        return FuelType::GASOLINE;
    } else if (fuelTypeString == "lpg") {
        return FuelType::LPG;
    } else if (fuelTypeString == "none") {
        return FuelType::NONE;
    } else {
        qDebug() << "unknown fuel type: " << fuelTypeString.toStdString() << ". Using default value (DIESEL).";
        return FuelType::DIESEL;
    }
}

QString motorTypeToString(MotorType motorType) {
    switch (motorType) {
    case MotorType::HYBRID:
        return "hybrid";
    case MotorType::ELECTRIC:
        return "electric";
    case MotorType::COMBUSTION:
        return "combustion";
    default:
        return "UNKNOWN";
    }
}

MotorType stringToMotorType(const QString& motorTypeString) {
    if (motorTypeString == "hybrid") {
        return MotorType::HYBRID;
    } else if (motorTypeString == "combustion") {
        return MotorType::COMBUSTION;
    }

    return MotorType::ELECTRIC;
}

void writeVehicleDataToFile(QTextStream& out, const VehicleList* vehicleList) {
    for (const auto& vehicle : vehicleList->getVehicleList()) {
        out << "----- VEHICLE -----\n";
        out << "Vehicle ID: " << vehicle->getVehicleID() << "\n";
        out << "License Plate Year: " << vehicle->getLicensePlateYear() << "\n";
        out << "Brand: " << vehicle->getBrand() << "\n";
        out << "Price: " << vehicle->getPrice() << "\n";
        out << "MotorType: " << motorTypeToString(vehicle->getMotorType()) << "\n";
        out << "FuelType: " << fuelTypeToString(vehicle->getFuelType()) << "\n";

        // Include Secondary FuelType only for hybrid vehicles
        if (vehicle->getMotorType() == MotorType::HYBRID) {
            out << "Secondary FuelType: " << fuelTypeToString(vehicle->getSecondaryFuelType()) << "\n";
        }

        int numPorts = 0;
        QString vehicleType;

        // Check if the vehicle is a Car (Coupe or Sedan)
        if (Car* car = dynamic_cast<Car*>(vehicle)) {
            numPorts = car->getNumPorts();
            if (numPorts == 2) {
                vehicleType = "coupe";
            } else {
                vehicleType = "sedan";
            }

            out << "Vehicle Type: " << vehicleType << "\n";

            // Display the power and capacity for each motor in the Car
            for (const auto& motor : car->getMotors()) {
                // Check if the motor is an instance of ICE (combustion motor)
                if (auto* iceMotor = dynamic_cast<ICE*>(motor)) {
                    out << "Motor 1: " << iceMotor->Power() << " Cv\n";
                }

                // Check if the motor is an instance of BEV (electric motor)
                if (auto* bevMotor = dynamic_cast<BEV*>(motor)) {
                    out << "Electric Motor: " << bevMotor->Power() << " kW\n";
                    out << "Capacity 2: " << bevMotor->getCapacity() << " kWh\n";
                } else {
                    // if it isn't electric is "liters"
                    out << "Capacity 1: " << motor->getCapacity() << " liters\n";
                }
            }
        }// Check if the vehicle is a Motorcycle
        else if (auto* motorcycle = dynamic_cast<Motorcycle*>(vehicle)) {
            vehicleType = "motorcycle";
            out << "Vehicle Type: " << vehicleType << "\n";

            // Display power and capacity for the single motor in the Motorcycle
            for (const auto& motor : motorcycle->getMotors()) {
                out << "Motor Power: " << motorcycle->getTotalPower() << " Cv\n";
                out << "Capacity: " << motor->getCapacity() << " liters\n";
            }

            out << "Has Fairing: ";
            if (motorcycle->getHasFairing()) {
                out << "true";
            } else {
                out << "false";
            }
            out << "\n";
        }
    }
}


// Convert Role to string
QString roleToString(Role role) {
    switch (role) {
    case Role::client: return "client";
    case Role::manager: return "manager";
    case Role::admin: return "admin";
    }
    return "unknown";
}

Role stringToRole(const QString& roleString) {
    QString lowercaseRole = roleString.toLower();  // Convert to lowercase

    if (lowercaseRole == "client") {
        return Role::client;
    } else if (lowercaseRole == "manager") {
        return Role::manager;
    } else if (lowercaseRole == "admin") {
        return Role::admin;
    } else {
        qDebug() << "Unknown role: " << roleString.toStdString() << ". Using default role (client).";
        return Role::client;
    }
}
