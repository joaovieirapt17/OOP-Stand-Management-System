#include <iostream>
#include <fstream>
#include <sstream>

#include "stand.h"
#include "car.h"
#include "utils.h"
#include "vehiclefactory.h"

using namespace std;

// Constructor
Stand::Stand() = default;

// Constructor
Stand::Stand(const string& cityName, int number ) {
    this->cityName = cityName;

    if (number >=1 && number <=99) {
        this->number = number;
    } else {
        cout << "Error! The number must be between 1 and 99." << endl;
    }

    // Concatenate city name and stand number to create a unique code
    if (number < 10){
        code = cityName + "0" + to_string(number);
    } else {
        code = cityName + to_string(number);
    }
}


string Stand::getCityName() const {
    return cityName;
}

int Stand::getNumber() const {
    return number;
}

// toString Method
string Stand::toString() const {
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
        cout << "Stand not found. \n";
        return -1;  // fail
    }
}

void VehicleStand::moveVehicle(Vehicle* vehicle, const string& destinationStandCode) {
    // find the current stand
    Stand* currentStand = findStandByVehicleID(vehicle->getVehicleID());

    // check if the source stand exists in the map
    if (currentStand == nullptr) {
        cout << "Source stand not found." << endl;
        return;
    }

    Stand* destinationStand = findStandByCode(destinationStandCode);

    // check if the destination stand exists in the map
    if (destinationStand == nullptr) {
        cout << "Destination stand not found." << endl;
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

// Display all the available stands
void VehicleStand::displayStands() const {
    for (const auto& standKeyValue : standVehicleMap) {
        cout << "  | Stand: " << standKeyValue.first->toString() << endl;
    }
}

// Display all the stands and associated vehicles
void VehicleStand::displayMapStandsVehicles() const {
    for (const auto& standKeyValue : standVehicleMap) {
        cout << "Stand: " << standKeyValue.first->toString() << endl;
        cout << "Vehicles:" << endl;

        // Iterate over the vehicles associated with the stand
        for (const auto& vehicle : standKeyValue.second->getVehicleList()) {
            cout << "  " << vehicle->toString() << endl;
        }

        cout << endl;
    }
}

Stand* VehicleStand::findStandByCode(const string& standCode) const {
    for (const auto& standKeyValue : standVehicleMap) {
        Stand* stand = standKeyValue.first;
        if (stand->toString() == standCode) {
            return stand; // Found a stand with the same code
        }
    }

    return nullptr; // Stand not found
}

int VehicleStand::addStand(const string& cityName, int number) {
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

int VehicleStand::removeStandByCode(const string& standCode) {
    for (auto itr = standVehicleMap.begin() ; itr != standVehicleMap.end() ; itr++) {
        Stand* stand = itr->first;
        if(stand->toString() == standCode) {
            delete stand; // Delete stand to avoid memory leak
            standVehicleMap.erase(itr);
            return 0; // Stand removed
        }
    }

    return -1; // Stand not found
}

VehicleList* VehicleStand::getVehicleListByStand(Stand* stand) const {
    auto standItr = standVehicleMap.find(stand);

    if (standItr != standVehicleMap.end()) {
        return standItr->second;
    } else {
        return nullptr;
    }
}

int VehicleStand::saveStandsDataTxt() {
    ofstream file("stands_data.txt");

    if (!file.is_open()) {
        return -3; // File not opened
    }

    // Iterate through the map and write each stand data to the 'txt' file
    for (const auto& standKeyValue : standVehicleMap) {
        Stand* stand = standKeyValue.first;

        // Write the stand data to the txt file
        file << "--------------------- STAND ---------------------\n";
        file << "City Name: " << stand->getCityName() << "\n";
        file << "Number: " << stand->getNumber() << "\n";

        // Write the vehicles in associated stand
        writeVehicleDataToFile(file, standKeyValue.second);
        file << "\n";
    }

    file.close();
    return 0; // Success
}

int VehicleStand::loadStandsDataTxt() {
    ifstream file("stands_data.txt");

    if (!file.is_open()) {
        cerr << "Error opening the text file." << endl;
        return -3;
    }

    Stand* currentStand = nullptr;
    string vehicleType;

    while (true) {
        string line;
        getline(file, line);

        if (file.eof()) {
            break; // End of file
        }

        // Check if the line is the beginning of a new stand
        if (line == "--------------------- STAND ---------------------") {
            // Read the city name
            getline(file, line);
            string cityName = line.substr(line.find(':') + 2);

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
            string brand = line.substr(line.find(':') + 2);

            // Read price
            getline(file, line);
            float price = stof(line.substr(line.find(':') + 2));

            // Read Motor type
            getline(file, line);
            string motorTypeString = line.substr(line.find(':') + 2);
            MotorType motorType = stringToMotorType(motorTypeString);

            // Read Primary Fuel type
            getline(file, line);
            string fuelTypeString = line.substr(line.find(':') + 2);
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
                string secondaryFuelTypeString = line.substr(line.find(':') + 2);
                secondaryFuelType = stringToFuelType(secondaryFuelTypeString);

                // Read Vehicle type
                getline(file, line);
                vehicleType = line.substr(line.find(':') + 2);

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
                vehicleType = line.substr(line.find(':') + 2);

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
                hasFairing = (line.find("true") != string::npos);

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

Stand* VehicleStand::findStandByVehicleID(int vehicleID) const {
    // Iterate through all stands
    for (const auto& stand : standVehicleMap) {
        VehicleList* vehicleList = stand.second;
        if (vehicleList->findVehicleByID(vehicleID) != nullptr) {
            return stand.first;
        }
    }

    return nullptr;  // Vehicle not found
}

Vehicle* VehicleStand::findVehicleByID(int vehicleID) const {
    // Iterate through all stands
    for (const auto& stand : standVehicleMap) {
        VehicleList* vehicleList = stand.second;

        // Iterates through the vehicle list to find the vehicle ID
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

            cout << "Vehicle removed from stand " << endl;

            // Save the updated stand data to the text file
            saveStandsDataTxt();
            cout << "Stand data updated." << endl;

            return 0; // Success
        }
    }

    cout << "Vehicle not found in any stand." << endl;
    return -1; // Vehicle not found
}

const map<Stand*, VehicleList*>& VehicleStand::getStandVehicleMap() const {
    return standVehicleMap;
}


void VehicleStand::loadCsvData(const std::string& filename) {
    ifstream file("stands.csv");

    if (!file.is_open()) {
        cerr << "Error opening the CSV file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        vector<string> content = split(line, ',');
        if (content.size() < 13) {
            cerr << "Invalid data format in CSV file." << endl;
            continue;
        }

        try {
            string brand = content[0];
            int year = stoi(content[1]);
            string type = content[2];

            FuelType primaryFuelType = stringToFuelType(content[3]);
            FuelType secondaryFuelType = stringToFuelType(content[4]);
            MotorType motorType = stringToMotorType(content[5]);
            bool hasFairing = content[6] == "true";
            float motorPower = stof(content[7]);
            float motorPower2 = stof(content[8]);
            float motorCapacity = stof(content[9]);
            float motorCapacity2 = stof(content[10]);
            float price = stof(content[11]);
            string standCode = content[12];

            // Separate city name and stand number from stand code
            string cityName = standCode.substr(0, standCode.size() - 2);
            int standNumber = std::stoi(standCode.substr(standCode.length() - 2), nullptr, 10);

            // Add stand to the map
            addStand(cityName, standNumber);

            // create vehicle
            if (type == "coupe") {
                if (motorType == MotorType::HYBRID) {
                    Car* car = VehicleFactory::createVehicle(type,year, brand, primaryFuelType, secondaryFuelType, motorType, motorPower, motorCapacity, motorPower2, motorCapacity2, price);
                    addVehicleToStand(car, findStandByCode(standCode));
                }
                else {
                    Car* car = VehicleFactory::createVehicle(type,year, brand, primaryFuelType, secondaryFuelType=FuelType::NONE, motorType, motorPower, motorCapacity, motorPower2=0, motorCapacity2=0, price);
                    addVehicleToStand(car, findStandByCode(standCode));
                }
            }
            else if (type == "sedan") {
                if (motorType == MotorType::HYBRID) {
                    Car* car = VehicleFactory::createVehicle(type, year, brand, primaryFuelType, secondaryFuelType, motorType, motorPower, motorCapacity, motorPower2, motorCapacity2, price);
                    addVehicleToStand(car, findStandByCode(standCode));
                }
                else {
                    Car* car = VehicleFactory::createVehicle(type, year, brand, primaryFuelType, FuelType::NONE, motorType, motorPower, motorCapacity, 0, 0, price);
                    addVehicleToStand(car, findStandByCode(standCode));
                }
            }

            if (type == "motorcycle") {
                Motorcycle* motorcycle = VehicleFactory::createVehicle(type, hasFairing, year, brand, primaryFuelType, motorType, motorPower, motorCapacity, price);
                if (motorcycle != nullptr) {
                    addVehicleToStand(motorcycle, findStandByCode(standCode));

                }
                else {
                    cerr << "Error! Invalid vehicle type." << endl;
                }
            }

        }

        catch (const std::invalid_argument& e) {
            cerr << "Invalid number format in CSV file: " << e.what() << endl;
            continue;
        }
        catch (const std::out_of_range& e) {
            cerr << "Number out of range in CSV file: " << e.what() << endl;
            continue;
        }
    }

    file.close();

}

vector<string> VehicleStand::split(string& str, char delimiter) {
    vector<string> content;
    stringstream ss(str);
    string token;

    while (getline(ss, token, delimiter)) {
        content.push_back(token);
    }

    return content;
}


