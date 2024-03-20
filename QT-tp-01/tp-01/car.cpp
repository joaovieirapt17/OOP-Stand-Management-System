#include "car.h"
#include "utils.h"

Car::Car(int licensePlateYear, const QString &brand, int numPorts, FuelType primaryFuelType, FuelType secondaryFuelType, MotorType motorType, float power, float capacity, float power2, float capacity2, float price, QObject *parent)
    : Vehicle(licensePlateYear, brand, price), numPorts(numPorts) {

    setFuelType(primaryFuelType);
    setMotorType(motorType);
    setSecondaryFuelType(secondaryFuelType);

    // Hybrid vehicles add 2 motors
    if (motorType == MotorType::HYBRID) {
        addMotor(new ICE(power, capacity, primaryFuelType)); // Combustion motor
        addMotor(new BEV(power2, capacity2));               // Electric Motor
    } else {
        if (motorType == MotorType::ELECTRIC) {
            addMotor(new BEV(power, capacity)); // Electric motor
        } else {
            addMotor(new ICE(power, capacity, primaryFuelType)); // Combustion motor
        }
    }
}

Car::~Car() {
    for (Motor *motor : motors) {
        delete motor;
    }
    motors.clear();
}

int Car::getNumPorts() const {
    return numPorts;
}

float Car::getTotalPower() const {
    float totalPower = 0.0;

    for (const Motor *motor : motors) {
        totalPower += motor->getPower();
    }

    return totalPower;
}

QVector<float> Car::getIndividualPowers() const {
    QVector<float> individualPowers;

    for (const Motor *motor : motors) {
        individualPowers.append(motor->getPower());
    }

    return individualPowers;
}

QVector<float> Car::getIndividualCapacities() const {
    QVector<float> individualCapacities;

    for (const Motor *motor : motors) {
        individualCapacities.append(motor->getCapacity());
    }

    return individualCapacities;
}

QString Car::getVehicleType() const {
    return "Car";
}

void Car::setNumPorts(int newNumPorts) {
    numPorts = newNumPorts;
}

QString Car::toString() const {
    QString carString = Vehicle::toString();

    // Append the vehicle type (Car) after fuel type
    carString += " " + getVehicleType();

    // Check if the vehicle is hybrid
    if (getMotorType() == MotorType::HYBRID) {
        carString += "\nSecondary Fuel Type: " + fuelTypeToString(getSecondaryFuelType());

        // Get individual powers and capacities of each motor
        QVector<float> individualPowers = getIndividualPowers();
        QVector<float> individualCapacities = getIndividualCapacities();

        carString += "\nMotor 1: " + QString::number(individualPowers[0]) + " Cv, Capacity 1: " + QString::number(individualCapacities[0]) + " liters";
        carString += "\nMotor 2: " + QString::number(individualPowers[1]) + " kW, Capacity 2: " + QString::number(individualCapacities[1]) + " kWh";
    }

    // Append total power information
    carString += "\nTotal Power: " + QString::number(getTotalPower()) + " Cv";

    return carString;
}


Coupe::Coupe(int licensePlateYear, const QString &brand, FuelType primaryFuelType, FuelType secondaryFuelType, MotorType motorType, float power, float capacity, float power2, float capacity2, float price, QObject *parent)
    : Car(licensePlateYear, brand, NUMBER_OF_PORTS, primaryFuelType, secondaryFuelType, motorType, power, capacity, power2, capacity2, price, parent) {}

QString Coupe::getVehicleType() const {
    return "Coupe";
}

QString Coupe::toString() const {
    QString coupeString = Car::toString();
    return coupeString;
}

Sedan::Sedan(int licensePlateYear, const QString &brand, FuelType primaryFuelType, FuelType secondaryFuelType, MotorType motorType, float power, float capacity, float power2, float capacity2, float price, QObject *parent)
    : Car(licensePlateYear, brand, NUMBER_OF_PORTS, primaryFuelType, secondaryFuelType, motorType, power, capacity, power2, capacity2, price, parent) {}

QString Sedan::getVehicleType() const {
    return "Sedan";
}

QString Sedan::toString() const {
    QString sedanString = Car::toString();
    return sedanString;
}

Motorcycle::Motorcycle(bool hasFairing, int licensePlateYear, const QString &brand, FuelType fuelType, MotorType motorType, float power, float capacity, float price, QObject *parent)
    : Vehicle(licensePlateYear, brand, price), hasFairing(hasFairing) {

    // Other types have only 1 motor (Combustion or Electric)
    if (motorType == MotorType::ELECTRIC) {
        addMotor(new BEV(power, capacity)); // Electric motor
    }
    if (motorType == MotorType::COMBUSTION) {
        addMotor(new ICE(power, capacity, fuelType)); // Combustion motor
    }
}

Motorcycle::~Motorcycle() {
    for (Motor *motor : motors) {
        delete motor;
    }
    motors.clear();
}

bool Motorcycle::getHasFairing() const {
    return hasFairing;
}

float Motorcycle::getTotalPower() const {
    float totalPower = 0.0;

    for (const Motor *motor : motors) {
        totalPower += motor->getPower();
    }

    return totalPower;
}

void Motorcycle::setHasFairing(bool newHasFairing) {
    hasFairing = newHasFairing;
}

QString Motorcycle::toString() const {
    QString motorCycleString = Vehicle::toString();

    // Append the Motorcycle
    motorCycleString += " Motorcycle";

    // If hasFairing == True include "with Fairing"
    if (hasFairing) {
        motorCycleString += " with Fairing";
    }
    motorCycleString += "\nTotal Power: " + QString::number(getTotalPower()) + " Cv";
    return motorCycleString;
}
