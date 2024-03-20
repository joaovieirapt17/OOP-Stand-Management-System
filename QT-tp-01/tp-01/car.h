#ifndef CAR_H
#define CAR_H

#include <QObject>
#include <QVector>

#include "vehicle.h"

class Car : public Vehicle {
    Q_OBJECT

private:
    int numPorts;

public:
    Car(int licensePlateYear, const QString &brand, int numPorts, FuelType primaryFuelType, FuelType secondaryFuelType, MotorType motorType, float power, float capacity, float power2, float capacity2, float price, QObject *parent = nullptr);
    ~Car();

    int getNumPorts() const;
    void setNumPorts(int newNumPorts);
    QString toString() const override;
    float getTotalPower() const;
    virtual QString getVehicleType() const;
    QVector<float> getIndividualPowers() const;
    QVector<float> getIndividualCapacities() const;
};

class Coupe : public Car {
    Q_OBJECT

private:
    static const int NUMBER_OF_PORTS = 2;

public:
    Coupe(int licensePlateYear, const QString &brand, FuelType primaryFuelType, FuelType secondaryFuelType, MotorType motorType, float power, float capacity, float power2, float capacity2, float price, QObject *parent = nullptr);

    QString toString() const override;
    QString getVehicleType() const override;
};

class Sedan : public Car {
    Q_OBJECT

private:
    static const int NUMBER_OF_PORTS = 4;


public:
    Sedan(int licensePlateYear, const QString &brand, FuelType primaryFuelType, FuelType secondaryFuelType, MotorType motorType, float power, float capacity, float power2, float capacity2, float price, QObject *parent = nullptr);

    QString toString() const override;
    QString getVehicleType() const override;
};

class Motorcycle : public Vehicle {
    Q_OBJECT

private:
    bool hasFairing;

public:
    Motorcycle(bool hasFairing, int licensePlateYear, const QString &brand, FuelType fuelType, MotorType motor, float power, float capacity, float price, QObject *parent = nullptr);
    ~Motorcycle();

    bool getHasFairing() const;
    float getTotalPower() const;
    void setHasFairing(bool newHasFairing);
    QString toString() const override;
};

#endif // CAR_H
