#include "car.h"
#include "utils.h"

using namespace std;

/* ------------------------------------------------- Car -------------------------------------------------------------*/

// Constructor
Car::Car() {}

// Constructor with parameters
Car::Car(int licensePlateYear, const string& brand, int numPorts, FuelType primaryFuelType, FuelType secondaryFuelType, MotorType motorType, float power, float capacity, float power2, float capacity2, float price)
        : Vehicle(licensePlateYear, brand, price) {

    this->numPorts = numPorts;
    setFuelType(primaryFuelType);
    setMotorType(motorType);
    setSecondaryFuelType(secondaryFuelType);

    // Hybrid vehicles add 2 motors
    if (motorType == MotorType::HYBRID) {
        addMotor(new ICE(power, capacity, primaryFuelType)); // Combustion motor
        addMotor(new BEV(power2, capacity2)); // Electric Motor
    } else {
        // Other types have only 1 motor (Combustion or Electric)
        if (motorType == MotorType::ELECTRIC) {
            addMotor(new BEV(power, capacity)); // Electric motor
        } else {
            addMotor(new ICE(power, capacity, primaryFuelType)); // Combustion motor
        }
    }
}

// Destructor
Car::~Car() {
    for (Motor* motor : motors) {
        delete motor;
    }
    motors.clear();
}


// ------ GETTERS ------
int Car::getNumPorts() const {
    return numPorts;
}

float Car::getTotalPower() const {
    float totalPower = 0.0;

    for (const Motor* motor : motors) {
        totalPower += motor->Power();
    }

    return totalPower;
}

vector<float> Car::getIndividualPowers() const {
    vector<float> individualPowers;
    individualPowers.reserve(motors.size()); // reserve memory for the vector (avoid unnecessary reallocation)

for (const Motor* motor : motors) {
        individualPowers.push_back(motor->getPower());
    }

    return individualPowers;
}

vector<float> Car::getIndividualCapacities() const {
    vector<float> individualCapacities;
    individualCapacities.reserve(motors.size()); // reserve memory for the vector (avoid unnecessary reallocation)

for (const Motor* motor : motors) {
        individualCapacities.push_back(motor->getCapacity());
    }

    return individualCapacities;
}

string Car::getVehicleType() const {
    return "Car";
}

// ------ SETTERS ------
void Car::setNumPorts(int newNumPorts) {
    numPorts = newNumPorts;
}

// toString method for Car
string Car::toString() const {
    string carString = Vehicle::toString();

    // Append the vehicle type (Car) after fuel type
    carString += " " + getVehicleType();

    // Check if the vehicle is hybrid
    if (getMotorType() == MotorType::HYBRID) {
        carString += "\nSecondary Fuel Type: " + fuelTypeToString(getSecondaryFuelType());

        // Get individual powers and capacities of each motor
        vector<float> individualPowers = getIndividualPowers();
        vector<float> individualCapacities = getIndividualCapacities();

        carString += "\nMotor 1: " + to_string(individualPowers[0]) + " Cv, Capacity 1: " + to_string(individualCapacities[0]) + " liters";
        carString += "\nMotor 2: " + to_string(individualPowers[1]) + " kW, Capacity 2: " + to_string(individualCapacities[1]) + " kWh";
    }

    // Append total power information
    carString += "\nTotal Power: " + to_string(getTotalPower()) + " Cv";

    return carString;
}

/* --------------------------- Coupe ----------------------------*/

// Constructor
Coupe::Coupe() = default;

// New Constructor with the parameter fuel type added
Coupe::Coupe(int licensePlateYear, const string& brand, FuelType primaryFuelType, FuelType secondaryFuelType, MotorType motorType, float power, float capacity, float power2, float capacity2, float price)
        : Car(licensePlateYear, brand, NUMBER_OF_PORTS, primaryFuelType, secondaryFuelType, motorType, power, capacity, power2, capacity2, price) {}

// Destructor
Coupe::~Coupe() = default;

string Coupe::getVehicleType() const {
    return "Coupe";
}

// toString method for Coupe
string Coupe::toString() const {
    string coupeString = Car::toString();

    return coupeString;
}


/* ----------------------- Sedan ----------------------------*/

// Constructor
Sedan::Sedan() {}

// Constructor with parameters
Sedan::Sedan(int licensePlateYear, const string& brand, FuelType primaryFuelType, FuelType secondaryFuelType, MotorType motorType, float power, float capacity, float power2, float capacity2, float price)
        : Car(licensePlateYear, brand, NUMBER_OF_PORTS, primaryFuelType, secondaryFuelType, motorType, power, capacity, power2, capacity2, price) {}

// Destructor
Sedan::~Sedan() = default;

string Sedan::getVehicleType() const {
    return "Sedan";
}

// toString method for Sedan
string Sedan::toString() const {
    string sedanString = Car::toString();

    return sedanString;
}


/* ----------- Motorcycle --------------*/

// Constructor
Motorcycle::Motorcycle() = default;

// Constructor with parameters
Motorcycle::Motorcycle(bool hasFairing, int licensePlateYear, const std::string& brand, FuelType fuelType,MotorType motorType, float power,float capacity, float price)
        : Vehicle(licensePlateYear, brand, price) {
    this->hasFairing = hasFairing;
    setFuelType(fuelType);
    setMotorType(motorType);
    // Other types have only 1 motor (Combustion or Electric)
    if (motorType == MotorType::ELECTRIC) {
        addMotor(new BEV(power, capacity)); // Electric motor
    }
    if(motorType == MotorType::COMBUSTION){
        addMotor(new ICE(power, capacity, fuelType)); // Combustion motor
    }
}

// Destructor
Motorcycle::~Motorcycle() {
    for (Motor* motor : motors) {
        delete motor;
    }
    motors.clear();
}


// ------ GETTERS ------
int Motorcycle::getHasFairing() const {
    return hasFairing;
}

float Motorcycle::getTotalPower() const {
    float totalPower = 0.0;

    for (const Motor* motor : motors) {
        totalPower += motor->Power();
    }

    return totalPower;
}

// ------ SETTERS ------
void Motorcycle::setHasFairing(bool newHasFairing) {
    this->hasFairing = newHasFairing;
}

// toString Method
string Motorcycle::toString() const {
    string motorCycleString = Vehicle::toString();

    // Append the Motorcycle
    motorCycleString += " Motorcycle";

    // If hasFairing == True include "with Fairing"
    if (hasFairing) {
        motorCycleString += " with Fairing";
    }
    motorCycleString += "\nTotal Power: " + to_string(getTotalPower()) + " Cv";
    return motorCycleString;
}