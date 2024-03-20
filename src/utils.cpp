#include <iostream>
#include "utils.h"

using namespace std;

string fuelTypeToString(FuelType fuelType) {
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

FuelType stringToFuelType(const string &fuelTypeString) {
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
        cerr << "unknown fuel type: " << fuelTypeString << ". Using default value (DIESEL)." << endl;
        return FuelType::DIESEL;
    }
}

string motorTypeToString(MotorType motorType) {
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

MotorType stringToMotorType(const string& motorTypeString) {
    if (motorTypeString == "hybrid") {
        return MotorType::HYBRID;
    } else if (motorTypeString == "combustion") {
        return MotorType::COMBUSTION;
    }

    return MotorType::ELECTRIC;
}


void writeVehicleDataToFile(ofstream& file, const VehicleList* vehicleList) {
    for (const auto& vehicle : vehicleList->getVehicleList()) {
        file << "----- VEHICLE -----\n";
        file << "Vehicle ID: " << vehicle->getVehicleID() << "\n";
        file << "License Plate Year: " << vehicle->getLicensePlateYear() << "\n";
        file << "Brand: " << vehicle->getBrand() << "\n";
        file << "Price: " << vehicle->getPrice() << "\n";
        file << "MotorType: " << motorTypeToString(vehicle->getMotorType()) << "\n";
        file << "FuelType: " << fuelTypeToString(vehicle->getFuelType()) << "\n";

        // Include Secondary FuelType only for hybrid vehicles
        if (vehicle->getMotorType() == MotorType::HYBRID) {
            file << "Secondary FuelType: " << fuelTypeToString(vehicle->getSecondaryFuelType()) << "\n";
        }

        int numPorts = 0;
        string vehicleType;

        // Check if the vehicle is a Car (Coupe or Sedan)
        if (Car* car = dynamic_cast<Car*>(vehicle)) {
            numPorts = car->getNumPorts();
            if (numPorts == 2) {
                vehicleType = "coupe";
            } else {
                vehicleType = "sedan";
            }

            file << "Vehicle Type: " << vehicleType << "\n";

            // Display the power and capacity for each motor in the Car
            for (const auto& motor : car->getMotors()) {
                // Check if the motor is an instance of ICE (combustion motor)
                if (auto* iceMotor = dynamic_cast<ICE*>(motor)) {
                file << "Motor 1: " << iceMotor->Power() << " Cv\n";
                }

                // Check if the motor is an instance of BEV (electric motor)
                if (auto* bevMotor = dynamic_cast<BEV*>(motor)) {
                    file << "Electric Motor: " << bevMotor->Power() << " kW\n";
                    file << "Capacity 2: " << bevMotor->getCapacity() << " kWh\n";
                } else {
                    // if it isn't electric is "liters"
                    file << "Capacity 1: " << motor->getCapacity() << " liters\n";
                }
            }
        }// Check if the vehicle is a Motorcycle
        else if (auto* motorcycle = dynamic_cast<Motorcycle*>(vehicle)) {
            vehicleType = "motorcycle";
            file << "Vehicle Type: " << vehicleType << "\n";

            // Display power and capacity for the single motor in the Motorcycle
            for (const auto& motor : motorcycle->getMotors()) {
            file << "Motor Power: " << motorcycle->getTotalPower() << " Cv\n";
            file << "Capacity: " << motor->getCapacity() << " liters\n";
            }

            file << "Has Fairing: ";
            if (motorcycle->getHasFairing()) {
                file << "true";
            } else {
                file << "false";
            }
            file << "\n";
        }
    }
}

// Convert Role to string
string roleToString(Role role) {
    switch (role) {
        case Role::client: return "client";
        case Role::manager: return "manager";
        case Role::admin: return "admin";
    }
    return "unknown";
}

// Convert string to Role
Role stringToRole(const string& roleString) {
    if (roleString == "client") {
        return Role::client;
    } else if (roleString == "manager") {
        return Role::manager;
    } else if (roleString == "admin") {
        return Role::admin;
    } else {
        cerr << "Unknown role: " << roleString << ". Using default role (client)." << endl;
        return Role::client;
    }
}


