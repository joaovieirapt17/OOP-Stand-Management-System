#ifndef CAR_H
#define CAR_H

#include <vector>
#include "vehicle.h"

/* ----------------------- Car CLASS -------------------------*/

// Car CLASS (INHERITANCE FROM Vehicle CLASS)
/**
 * @class Car
 * @brief Represents a car, inheriting from the Vehicle class.
 */
class Car : public Vehicle {
private:
    int numPorts; /**< Number of ports in the car */

public:
    // Constructor
    Car();

    /**
     * @brief Constructor with parameters.
     * @param licensePlateYear The year the car was registered.
     * @param brand The brand or make of the car.
     * @param numPorts The number of ports in the car.
     * @param primaryFuelType The primary fuel type of the car.
     * @param secondaryFuelType The secondary fuel type for hybrid cars.
     * @param motorType The type of motor used by the car.
     * @param power Power of the motor.
     * @param capacity Capacity of the motor.
     * @param power2 Power of the second motor for hybrid cars.
     * @param capacity2 Capacity of the second motor for hybrid cars.
     * @param price The price of the car.
     */
    Car(int licensePlateYear, const std::string& brand, int numPorts, FuelType primaryFuelType, FuelType secondaryFuelType, MotorType motorType, float power, float capacity, float power2, float capacity2, float price);

    // Destructor
    ~Car();

    // ------ GETTERS ------
    /**
     * @brief Gets the number of ports in the car.
     * @return The number of ports.
     */
    [[nodiscard]] int getNumPorts() const;

    // ------ SETTERS ------
    /**
     * @brief Sets the number of ports in the car.
     * @param newNumPorts The new number of ports.
     */
    void setNumPorts(int newNumPorts);

    /**
     * @brief Gets a string representation of the car.
     * @return A string describing the car.
     */
    [[nodiscard]] std::string toString() const override;

    /**
     * @brief Gets the total power of the car.
     * @return The total power.
     */
    float getTotalPower() const;

    /**
     * @brief Gets the type of the vehicle.
     * @return A string representing the vehicle type.
     */
    virtual std::string getVehicleType() const;

    /**
     * @brief Gets the individual powers of the car for hybrid cars.
     * @return A vector containing power 1 and power 2.
     */
    std::vector<float> getIndividualPowers() const;

    /**
     * @brief Gets the individual capacities of the car for hybrid cars.
     * @return A vector containing capacity 1 and capacity 2.
     */
    std::vector<float> getIndividualCapacities() const;
};

/* ----------------------- Coupe CLASS -------------------------*/

/**
 * @class Coupe
 * @brief Represents a coupe car, inheriting from the Car class.
 */
class Coupe : public Car {
private:
    static const int NUMBER_OF_PORTS = 2; /**< Number of ports for Coupe */

public:
    // Constructor
    Coupe();

    /**
     * @brief Constructor for hybrid cars.
     * @param licensePlateYear The year the car was registered.
     * @param brand The brand or make of the car.
     * @param primaryFuelType The primary fuel type of the car.
     * @param secondaryFuelType The secondary fuel type for hybrid cars.
     * @param motorType The type of motor used by the car.
     * @param power Power of the motor.
     * @param capacity Capacity of the motor.
     * @param power2 Power of the second motor for hybrid cars.
     * @param capacity2 Capacity of the second motor for hybrid cars.
     * @param price The price of the car.
     */
    Coupe(int licensePlateYear, const std::string& brand, FuelType primaryFuelType, FuelType secondaryFuelType, MotorType motorType, float power, float capacity, float power2, float capacity2, float price);

    // Destructor
    ~Coupe();

    /**
     * @brief Gets a string representation of the coupe.
     * @return A string describing the coupe.
     */
    [[nodiscard]] std::string toString() const override;

    /**
     * @brief Gets the type of the vehicle.
     * @return A string representing the vehicle type.
     */
    std::string getVehicleType() const override;
};

/* ----------------------- Sedan CLASS -------------------------*/

/**
 * @class Sedan
 * @brief Represents a sedan car, inheriting from the Car class.
 */
class Sedan : public Car {
private:
    static const int NUMBER_OF_PORTS = 4; /**< Number of ports for Sedan */

public:
    // Constructor
    Sedan();

    /**
     * @brief Constructor with parameters and fuel type added.
     * @param licensePlateYear The year the car was registered.
     * @param brand The brand or make of the car.
     * @param primaryFuelType The primary fuel type of the car.
     * @param secondaryFuelType The secondary fuel type for hybrid cars.
     * @param motorType The type of motor used by the car.
     * @param power Power of the motor.
     * @param capacity Capacity of the motor.
     * @param power2 Power of the second motor for hybrid cars.
     * @param capacity2 Capacity of the second motor for hybrid cars.
     * @param price The price of the car.
     */
    Sedan(int licensePlateYear, const std::string& brand, FuelType primaryFuelType, FuelType secondaryFuelType, MotorType motorType, float power, float capacity, float power2, float capacity2, float price);

    // Destructor
    ~Sedan();

    /**
     * @brief Gets a string representation of the sedan.
     * @return A string describing the sedan.
     */
    [[nodiscard]] std::string toString() const override;

    /**
     * @brief Gets the type of the vehicle.
     * @return A string representing the vehicle type.
     */
    std::string getVehicleType() const override;
};


/* ----------------------- Motorcycle -------------------------*/

/**
 * @class Motorcycle
 * @brief Represents a motorcycle, inheriting from the Vehicle class.
 */
class Motorcycle : public Vehicle {
private:
    bool hasFairing{}; /**< Indicates if the motorcycle has a fairing */

public:
    // Constructor
    Motorcycle();

    /**
     * @brief Constructor with parameters.
     * @param hasFairing Indicates if the motorcycle has a fairing.
     * @param licensePlateYear The year the motorcycle was registered.
     * @param brand The brand or make of the motorcycle.
     * @param fuelType The fuel type of the motorcycle.
     * @param motorType The type of motor used by the motorcycle.
     * @param power Power of the motor.
     * @param capacity Capacity of the motor.
     * @param price The price of the motorcycle.
     */
    Motorcycle(bool hasFairing, int licensePlateYear, const std::string& brand, FuelType fuelType, MotorType motorType, float power, float capacity, float price);

    // Destructor
    ~Motorcycle();

    // ------ GETTERS ------
    /**
     * @brief Gets whether the motorcycle has a fairing.
     * @return True if the motorcycle has a fairing, false otherwise.
     */
    [[nodiscard]] int getHasFairing() const;

    /**
     * @brief Gets the total power of the motorcycle.
     * @return The total power.
     */
    float getTotalPower() const;

    // ------ SETTERS ------
    /**
     * @brief Sets whether the motorcycle has a fairing.
     * @param newHasFairing The new value indicating if the motorcycle has a fairing.
     */
    void setHasFairing(bool newHasFairing);

    /**
     * @brief Gets a string representation of the motorcycle.
     * @return A string describing the motorcycle.
     */
    [[nodiscard]] std::string toString() const override;
};

#endif //CAR_H

