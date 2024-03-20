#include <iostream>
#include <fstream>
#include <QDebug>

#include <QFile>
#include <QTextStream>

#include "stand.h"
#include "car.h"
#include "utils.h"
#include "vehiclefactory.h"

// Constructor
Stand::Stand() = default;

// Constructor
Stand::Stand(const QString& cityName, int number) {
    this->cityName = cityName;

    if (number >= 1 && number <= 99) {
        this->number = number;
    } else {
        std::cout << "Error! The number must be between 1 and 99." << std::endl;
    }

    // Concatenate city name and stand number to create a unique code
    if (number < 10) {
        code = cityName + "0" + QString::number(number);
    } else {
        code = cityName + QString::number(number);
    }
}

QString Stand::getCityName() const {
    return cityName;
}

int Stand::getNumber() const {
    return number;
}

// toString Method
QString Stand::toString() const {
    return code;
}

/* ----------------------------------------- VehicleStand Methods -----------------------------------------------*/

// Constructor
VehicleStand::VehicleStand() = default;

// Add vehicle to a stand using <map>
int VehicleStand::addVehicleToStand(Vehicle* vehicle, Stand* stand) {
    // Find the stand in the map
    Stand* foundStand = findStandByCode(stand->toString());

    // If the stand is found, add the vehicle to the list of vehicles associated with the stand
    if (foundStand) {
        standVehicleMap[foundStand]->addVehicle(vehicle);
        return 0;  // Success
    } else {
        std::cout << "Stand not found. \n";
        return -1;  // fail
    }
}

/*
void VehicleStand::moveVehicle(Vehicle* vehicle, const QString& destinationStandCode) {
    // find the current stand
    Stand* currentStand = findStandByVehicleID(vehicle->getVehicleID());

    // check if the source stand exists in the map
    if (currentStand == nullptr) {
        std::cout << "Source stand not found." << std::endl;
        return;
    }

    Stand* destinationStand = findStandByCode(destinationStandCode);

    // check if the destination stand exists in the map
    if (destinationStand == nullptr) {
        std::cout << "Destination stand not found." << std::endl;
        return;
    }

    // get the VehicleList associated with the current stand
    VehicleList* currentStandVehicleList = standVehicleMap[currentStand];

    // get the VehicleList associated with the destination stand
    VehicleList* destinationStandVehicleList = standVehicleMap[destinationStand];

    // remove the vehicle from the source stand vehicle list
    currentStandVehicleList->removeVehicleByID(vehicle->getVehicleID());

    // add the vehicle to the destination stand vehicle list
    destinationStandVehicleList->addVehicle(vehicle);

    // Saves the updated stand data to the text file
    saveStandsDataTxt();
}
*/

// Display all the available stands
void VehicleStand::displayStands() const {
    for (auto it = standVehicleMap.begin(); it != standVehicleMap.end(); ++it) {
        Stand* stand = it.key();

        std::cout << "  | Stand: " << stand->toString().toStdString() << std::endl;
    }
}

// Display all the stands and associated vehicles
void VehicleStand::displayMapStandsVehicles() const {
    for (auto it = standVehicleMap.begin(); it != standVehicleMap.end(); ++it) {
        Stand* stand = it.key();

        std::cout << "Stand: " << stand->toString().toStdString() << std::endl;
        std::cout << "Vehicles:" << std::endl;

        // Iterate over the vehicles associated with the stand
        for (auto& vehicle : it.value()->getVehicleList()) {
            std::cout << "  " << vehicle->toString().toStdString() << std::endl;
        }

        std::cout << std::endl;
    }
}

// Find a stand by code
Stand* VehicleStand::findStandByCode(const QString& standCode) const {
    for (auto it = standVehicleMap.begin(); it != standVehicleMap.end(); ++it) {
        Stand* stand = it.key();
        if (stand->toString() == standCode) {
            return stand; // Found a stand with the same code
        }
    }

    return nullptr; // Stand not found
}

int VehicleStand::addStand(const QString& cityName, int number) {
    // Create a new stand with the given city name and number
    auto* newStand = new Stand(cityName, number);

    // Check if the stand with the same code already exists
    Stand* result = findStandByCode(newStand->toString());

    if (result != nullptr) {
        delete newStand; // Delete the newly created stand to avoid memory leak
        return -1; // stand with the same city name already exists
    }

    // add the new stand to map
    standVehicleMap[newStand] = new VehicleList();
    return 0; // Success
}

// Remove a stand by code
int VehicleStand::removeStandByCode(const QString& standCode) {
    for (auto it = standVehicleMap.begin(); it != standVehicleMap.end(); ++it) {
        Stand* stand = it.key();
        if (stand->toString() == standCode) {
            delete stand; // Delete stand to avoid memory leak
            standVehicleMap.erase(it);
            return 0; // Stand removed
        }
    }

    return -1; // Stand not found
}


// Get the list of vehicles associated with a stand
VehicleList* VehicleStand::getVehicleListByStand(Stand* stand) const {
    auto standItr = standVehicleMap.find(stand);

    if (standItr != standVehicleMap.end()) {
        return standItr.value();
    } else {
        return nullptr;
    }
}


// Save stands data to a text file
int VehicleStand::saveStandsDataTxt() {
    QFile file("stands_data.txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return -3; // File not opened
    }

    QTextStream out(&file);

    // Iterate through the map and write each stand data to the 'txt' file
    for (auto it = standVehicleMap.begin(); it != standVehicleMap.end(); ++it) {
        Stand* stand = it.key();

        // Write the stand data to the txt file
        out << "--------------------- STAND ---------------------\n";
        out << "City Name: " << stand->getCityName() << "\n";
        out << "Number: " << stand->getNumber() << "\n";

        // Write the vehicles in the associated stand
        //writeVehicleDataToFile(file, it.value());
        out << "\n";
    }

    return 0; // Success
}


int VehicleStand::loadStandsDataTxt() {
    std::ifstream file("stands_data.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening the text file." << std::endl;
        return -3;
    }

    Stand* currentStand = nullptr;
    QString vehicleType;

    while (true) {
        std::string line;
        getline(file, line);

        if (file.eof()) {
            break; // End of file
        }

        // Check if the line is the beginning of a new stand
        if (line == "--------------------- STAND ---------------------") {
            // Read the city name
            getline(file, line);
            QString cityName = QString::fromStdString(line.substr(line.find(':') + 2));

            // Read the stand number
            getline(file, line);
            int standNumber = stoi(line.substr(line.find(':') + 2));

            // Create a new stand and add it to the map
            currentStand = new Stand(cityName, standNumber);
            standVehicleMap[currentStand] = new VehicleList();
        }

        // Read the vehicles in the stand
        if (line == "----- VEHICLE -----") {
            // Read VehicleID
            getline(file, line);
            int vehicleID = stoi(line.substr(line.find(':') + 2));

            // Read license plate year
            getline(file, line);
            int licensePlateYear = stoi(line.substr(line.find(':') + 2));

            // Read Brand
            getline(file, line);
            QString brand = QString::fromStdString(line.substr(line.find(':') + 2));

            // Read price
            getline(file, line);
            float price = stof(line.substr(line.find(':') + 2));

            // Read Motor type
            getline(file, line);
            QString motorTypeString = QString::fromStdString(line.substr(line.find(':') + 2));
            MotorType motorType = stringToMotorType(motorTypeString);

            // Read Primary Fuel type
            getline(file, line);
            QString fuelTypeString = QString::fromStdString(line.substr(line.find(':') + 2));
            FuelType fuelType = stringToFuelType(fuelTypeString);

            // Read information if it's hybrid vehicles
            float motorPower1 = 0.0;
            float capacity1 = 0.0;
            float motorPower2 = 0.0;
            float capacity2 = 0.0;
            FuelType secondaryFuelType = FuelType::NONE;

            // Read information if it's hybrid vehicles
            if (motorType == MotorType::HYBRID) {
                // Read Secondary Fuel Type
                getline(file, line);
                QString secondaryFuelTypeString = QString::fromStdString(line.substr(line.find(':') + 2));
                secondaryFuelType = stringToFuelType(secondaryFuelTypeString);

                // Read Vehicle type
                getline(file, line);
                vehicleType = QString::fromStdString(line.substr(line.find(':') + 2));

                // Read Motor Power 1
                getline(file, line);
                motorPower1 = stof(line.substr(line.find(':') + 2));

                // Read Capacity 2
                getline(file, line);
                capacity1 = stof(line.substr(line.find(':') + 2));

                // Read Motor Power 1
                getline(file, line);
                motorPower2 = stof(line.substr(line.find(':') + 2));

                // Read Capacity 2
                getline(file, line);
                capacity2 = stof(line.substr(line.find(':') + 2));
            } else {
                // Read Vehicle type
                getline(file, line);
                vehicleType = QString::fromStdString(line.substr(line.find(':') + 2));

                // Read Motor Power
                getline(file, line);
                motorPower1 = stof(line.substr(line.find(':') + 2));

                // Read Capacity
                getline(file, line);
                capacity1 = stof(line.substr(line.find(':') + 2));
            }

            // Add the vehicle to the list
            Car* car = nullptr;
            Motorcycle* motorcycle = nullptr;
            bool hasFairing = false;

            if (vehicleType == "car" || vehicleType == "coupe" || vehicleType == "sedan") {
                car = VehicleFactory::createVehicle(vehicleType, licensePlateYear, brand, fuelType, secondaryFuelType, motorType, motorPower1, capacity1, motorPower2, capacity2, price);
                addVehicleToStand(car, currentStand);
            } else if (vehicleType == "motorcycle") {
                getline(file, line);
                hasFairing = (line.find("true") != std::string::npos);

                motorcycle = VehicleFactory::createVehicle(vehicleType, hasFairing, licensePlateYear, brand, fuelType, motorType, motorPower1, capacity1, price);
                addVehicleToStand(motorcycle, currentStand);
            } else {
                hasFairing = false;
            }

            // Set unique vehicleID for each vehicle created
            if (car != nullptr) {
                car->setVehicleID(vehicleID);
            } else if (motorcycle != nullptr) {
                motorcycle->setVehicleID(vehicleID);
            }
        }
    }

    file.close();

    return 0; // Success
}

/*
// Find a stand by vehicle ID
Stand* VehicleStand::findStandByVehicleID(int vehicleID) const {
    // Iterate through all stands
    for (const auto& it : standVehicleMap) {
        Stand* stand = it.key();
        VehicleList* vehicleList = it.value();

        if (vehicleList->findVehicleByID(vehicleID) != nullptr) {
            return stand;
        }
    }

    return nullptr;  // Vehicle not found
}



// Find a vehicle by ID
Vehicle* VehicleStand::findVehicleByID(int vehicleID) const {
    // Iterate through all stands
    for (const auto& it : standVehicleMap) {
        VehicleList* vehicleList = it.value();

        // Iterate through the vehicle list to find the vehicle ID
        for (auto itr : vehicleList->getVehicleList()) {
            if (itr->getVehicleID() == vehicleID) {
                return itr; // Return the pointer to the founded vehicle
            }
        }
    }
    return nullptr; // Vehicle not found
}



int VehicleStand::removeVehicleByID(int vehicleID) {
    // Iterate through all stands
    for (auto& standKeyValue : standVehicleMap) {
        VehicleList* vehicleList = standKeyValue.second;

        // locate the vehicle
        Vehicle* foundVehicle = vehicleList->findVehicleByID(vehicleID);

        if (foundVehicle != nullptr) {
            // vehicle found, remove it from the list
            vehicleList->removeVehicleByID(vehicleID);

            qDebug() << "Vehicle removed from stand ";

            // Save the updated stand data to the text file
            saveStandsDataTxt();
            qDebug() << "Stand data updated.";

            return 0; // Success
        }
    }

    qDebug() << "Vehicle not found in any stand.";
    return -1; // Vehicle not found
}

const std::map<Stand *, VehicleList *> &VehicleStand::getStandVehicleMap() const {
    return standVehicleMap;
}
*/
