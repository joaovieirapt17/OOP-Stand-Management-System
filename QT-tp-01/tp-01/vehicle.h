#ifndef VEHICLE_H
#define VEHICLE_H

#include <QObject>
#include <QString>
#include <vector>

#include "motor.h"
#include "vehiclelist.h"


class Vehicle : public QObject {
    Q_OBJECT

private:
    static int nVehicles;
    int vehicleID;
    int licensePlateYear;
    QString brand;
    FuelType primaryFuelType;
    FuelType secondaryFuelType;
    MotorType motorType;
    float price;

protected:
    std::vector<Motor *> motors;

public:
    // Constructor
    Vehicle(int licensePlateYear, const QString& brand, float price, QObject *parent = nullptr);

    // Destructor
    ~Vehicle();

    // toString method for Car (Abstract Class)
    virtual QString toString() const;

    void addMotor(Motor* motor);

    // ------ GETTERS ------
    static int getNVehicles();
    int getVehicleID() const;
    int getLicensePlateYear() const;
    QString getBrand() const;
    float getPrice() const;
    FuelType getFuelType() const;
    MotorType getMotorType() const;
    const std::vector<Motor *> &getMotors() const;

    // ------ SETTERS ------
    void setLicensePlateYear(int year);
    void setBrand(const QString& brand);
    void setFuelType(FuelType newFuelType);
    void setSecondaryFuelType(FuelType newSecondaryFuelType);
    void setMotorType(MotorType newMotorType);
    void setPrice(float newPrice);
    void setVehicleID(int newID);

    FuelType getSecondaryFuelType() const;

signals:
    void errorOccurred(const QString &errorMessage);
};

#endif // VEHICLE_H
