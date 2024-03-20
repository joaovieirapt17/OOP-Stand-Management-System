#include <iostream>
#include "vehiclelist.h"
#include "vehicle.h"

using namespace std;

/* ------------------------------------------- VehicleList Methods -----------------------------------------------*/

Vehicle* VehicleList::findVehicleByID(int vehicleID) {
    // Iterates through the vehicle list to find the vehicle ID
    for (auto &itr : vehicleList) {
        if (itr->getVehicleID() == vehicleID) {
            return itr; // Return the pointer to the founded vehicle
        }
    }

    return nullptr; // Vehicle not found
}

int VehicleList::addVehicle(Vehicle *vehicle) {
    // Check if the vehicle with the same ID already exists
    Vehicle *result = findVehicleByID(vehicle->getVehicleID());

    if (result != nullptr) {
        return -1; // Vehicle with the same ID already exists
    }

    // Add the new vehicle to the list
    vehicleList.push_back(vehicle);

    return 0; // Vehicle added successfully
}

int VehicleList::removeVehicleByID(int vehicleID) {
    for (auto itr = vehicleList.begin(); itr != vehicleList.end(); itr++) {
        if ((*itr)->getVehicleID() == vehicleID) {
            vehicleList.erase(itr);
            return 0; // Vehicle removed
        }
    }

    return -1; // Vehicle not found
}

void VehicleList::printVehicleList() const {
    // Check for an empty list
    if (vehicleList.empty()) {
        cout << "Vehicle List is empty " << endl;
        return;
    }

    // Iterates the list
    for (const auto &vehicle : vehicleList) {
        // Convert QString to std::string before outputting
        cout << vehicle->toString().toStdString() << endl;
    }
}

const QList<Vehicle*>& VehicleList::getVehicleList() const {
    return vehicleList;
}
