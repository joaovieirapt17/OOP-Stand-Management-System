#include <iostream>

#include "motor.h"

// ------------------------- MOTOR CLASS -------------------------
Motor::Motor(float power) {
    this->power = power;
}

Motor::~Motor() = default;

float Motor::getPower() const {
    return power;
}

void Motor::displayInfo() const {
    std::cout << "Power: " << getPower() << " Cv";
}

/* ------------------------- BEV CLASS ------------------------- */
BEV::BEV(float power, float capacity) : Motor(power) {
    this->capacity = capacity;
}

BEV::~BEV() = default;

float BEV::Power() const {
    return getPower() * 0.7355f; // CV to KW
}

float BEV::getCapacity() const {
    return capacity;
}

void BEV::displayInfo() const {
    Motor::displayInfo();
    std::cout << ", Battery Capacity: " << capacity << " kWh" << std::endl;
}

/* ------------------------- ICE CLASS ------------------------- */
ICE::ICE(float power, float capacity, FuelType fuelType) : Motor(power), fuelType(fuelType) {
    this->capacity = capacity;
}

ICE::~ICE() = default;

float ICE::Power() const {
    return getPower();
}

float ICE::getCapacity() const {
    return capacity;
}

void ICE::displayInfo() const {
    Motor::displayInfo();
    std::cout << ", Tank Capacity: " << capacity << " liters" << std::endl;
}
