#include "vehicle.h"
#include "utils.h"

#include <QDebug>

using namespace std;

int Vehicle::nVehicles = 1;


Vehicle::Vehicle(int licensePlateYear, const QString &brand, float price, QObject *parent)
    : QObject(parent), licensePlateYear(licensePlateYear), brand(brand), price(price) {

    if (brand.isEmpty()) {
        qDebug() << "Error! Brand must be filled in.";
        return;
    }

    if (licensePlateYear < 0) {
        qDebug() << "Invalid license plate year.";
        return;
    }

    this->vehicleID = nVehicles++;
}

Vehicle::~Vehicle() {
}

QString Vehicle::toString() const {
    QString result = " " + QString::number(getVehicleID()) + " " + QString::number(getLicensePlateYear()) + " " + getBrand() + " " + fuelTypeToString(getFuelType());
    return result;
}

void Vehicle::addMotor(Motor *motor) {
    motors.push_back(motor);
}

// ------ GETTERS ------

int Vehicle::getVehicleID() const {
    return vehicleID;
}

int Vehicle::getLicensePlateYear() const {
    return licensePlateYear;
}

QString Vehicle::getBrand() const {
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

const std::vector<Motor *> &Vehicle::getMotors() const {
    return motors;
}

// ------ SETTERS ------

void Vehicle::setLicensePlateYear(int year) {
    if (year < 0) {
        qDebug() << "Invalid license plate year.";
        return;
    }

    licensePlateYear = year;
}

void Vehicle::setBrand(const QString &newBrand) {
    if (newBrand.isEmpty()) {
        qDebug() << "Error! Brand must be filled in.";
        return;
    }

    brand = newBrand;
}

void Vehicle::setFuelType(FuelType newFuelType) {
    primaryFuelType = newFuelType;
}

void Vehicle::setSecondaryFuelType(FuelType newSecondaryFuelType) {
    secondaryFuelType = newSecondaryFuelType;
}

void Vehicle::setMotorType(MotorType newMotorType) {
    motorType = newMotorType;
}

void Vehicle::setPrice(float newPrice) {
    price = newPrice;
}

void Vehicle::setVehicleID(int newID) {
    vehicleID = newID;
}
