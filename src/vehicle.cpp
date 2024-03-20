#include <iostream>

#include "vehicle.h"
#include "utils.h"

using namespace std;

// Initialize the number of vehicles
int Vehicle::nVehicles = 1;

// Get the number os vehicles
int Vehicle::getNVehicles() {
    return nVehicles;
}

// Constructor
Vehicle::Vehicle() = default;

// Constructor with parameters
Vehicle::Vehicle(int licensePlateYear, const string& brand, float price) {

    if (brand.empty()) {
        cout << "Error! Brand must be filled in." << endl;
    }

    if (licensePlateYear < 0) {
        cout << "Invalid license plate year." << endl;
    }

    this->licensePlateYear = licensePlateYear;
    this->brand = brand;
    this->vehicleID = nVehicles++;
    this->price = price;
}

// Destructor
Vehicle::~Vehicle() = default;

string Vehicle::toString() const {
    string result = " " + to_string(getVehicleID()) + " " + to_string(getLicensePlateYear()) + " " + getBrand() + " " + fuelTypeToString(getFuelType());
    return result;
}

void Vehicle::addMotor(Motor* motor) {
    motors.push_back(motor);
}

// ------ GETTERS ------

int Vehicle::getVehicleID() const {
    return vehicleID;
}

int Vehicle::getLicensePlateYear() const {
    return licensePlateYear;
}

string Vehicle::getBrand() const {
    return brand;
}

float Vehicle::getPrice() const {
    return price;
}

FuelType Vehicle::getFuelType() const {
    return primaryFuelType;
}

FuelType Vehicle::getSecondaryFuelType() const {
    return secondaryFuelType;
}

MotorType Vehicle::getMotorType() const {
    return motorType;
}

const vector<Motor*>& Vehicle::getMotors() const {
    return motors;
}


// ------ SETTERS ------

void Vehicle::setLicensePlateYear(int year) {
    if (year < 0) {
        cout << "Invalid license plate year." << endl;
        return;
    }

    licensePlateYear = year;
}

void Vehicle::setBrand(const string& newBrand) {
    if (newBrand.empty()) {
        cout << "Error! Brand must be filled in." << endl;
        return;
    }

    brand = newBrand;
}

// Set the fuel type of the vehicle
void Vehicle::setFuelType(FuelType newFuelType) {
    primaryFuelType = newFuelType;
}

void Vehicle::setSecondaryFuelType(FuelType newSecondaryFuelType) {
    secondaryFuelType = newSecondaryFuelType;
}

// Set the motor type of the vehicle
void Vehicle::setMotorType(MotorType newMotorType) {
    motorType = newMotorType;
}

void Vehicle::setPrice(float newPrice) {
    price = newPrice;
}

void Vehicle::setVehicleID(int newID) {
    vehicleID = newID;
}