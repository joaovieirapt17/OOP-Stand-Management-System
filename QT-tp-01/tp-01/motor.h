#ifndef MOTOR_H
#define MOTOR_H

#include <QString>

// Enum type for cars FuelType
enum class FuelType {
    NONE,
    DIESEL,
    ELECTRICITY,
    GASOLINE,
    LPG,
};

enum class MotorType {
    ELECTRIC,
    COMBUSTION,
    HYBRID
};

class Motor {
private:
    float power; // Power of the motor in Cv

public:
    explicit Motor(float power);
    virtual ~Motor();

    virtual float Power() const = 0;

    // Virtual func to get the power
    virtual float getPower() const;

    // Virtual func to get the capacity
    virtual float getCapacity() const = 0;

    // Display information about the motor
    virtual void displayInfo() const;
};

/* ----------------------- ICE CLASS -------------------------*/
class ICE: public Motor {
private:
    FuelType fuelType; // Type of fuel (DIESEL, GASOLINE, LPG)
    float capacity; // Capacity of the tank in liters

public:
    ICE(float power, float capacity, FuelType fuelType);

    ~ICE();

    float Power() const override;

    float getCapacity() const override;

    // Method to display information about ICE
    void displayInfo() const override;

};

/* ----------------------- BEV CLASS -------------------------*/
class BEV : public Motor {
private:
    float capacity; // Capacity of the battery in kWh

public:
    BEV(float power, float capacity);

    ~BEV();

    float Power() const override;

    float getCapacity() const override;

    // Method to display information about BEV
    void displayInfo() const override;

};

#endif //MOTOR_H
