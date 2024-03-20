#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <vector>

#include "motor.h"
#include "vehiclelist.h"

// VEHICLE CLASS
class Vehicle {
private:
    static int nVehicles; /**< Number of Vehicles */
    int vehicleID; /**< Vehicle ID */
    int licensePlateYear{}; /**< Plate Year */
    std::string brand; /**< Vehicle Brand */
    FuelType primaryFuelType; /**< Type of fuel used by a single motor vehicle */
    FuelType secondaryFuelType; /**< Secondary fuel type for hybrid vehicles */
    MotorType motorType; /**< Type of motor used by the vehicle */
    float price; /**< Price to buy the vehicle */

protected:
    std::vector<Motor*> motors; /**< vector of motors associated with the vehicle */

public:
    // Constructor
    Vehicle();

    // Constructor with parameters
    Vehicle(int licensePlateYear, const std::string& brand, float price);

    // Destructor
    ~Vehicle();

    /**
     * @brief toString method describing the vehicle.
     * @return A string with information about the vehicle.
     */
    virtual std::string toString() const;

    /**
     * @brief Adds a motor to the vehicle.
     * @param motor A pointer to the motor to be added.
     */
    void addMotor(Motor* motor);

    // ------ GETTERS ------

    /**
     * @brief Gets the total number of vehicles.
     * @return The total number of vehicles.
     */
    static int getNVehicles();

    /**
    * @brief Gets the ID of the vehicle.
    * @return The ID of the vehicle.
    */
    int getVehicleID() const;

    /**
    * @brief Gets the year in which the vehicle was registered.
    * @return The registration year of the vehicle.
    */
    int getLicensePlateYear() const;

    /**
     * @brief Gets the brand of the vehicle.
     * @return The brand of the vehicle.
     */
    std::string getBrand() const;

    /**
     * @brief Gets the price of the vehicle.
     * @return The price of the vehicle.
     */
    float getPrice() const;

    /**
     * @brief Gets the primary fuel type of the vehicle.
     * @return The primary fuel type of the vehicle.
     */
    FuelType getFuelType() const;

    /**
     * @brief Gets the motor type of the vehicle.
     * @return The motor type of the vehicle.
     */
    MotorType getMotorType() const;

    /**
     * @brief Gets the vector of motors associated with the vehicle.
     * @return A const reference to the vector of motors.
     */
    const std::vector<Motor*>& getMotors() const;

    // ------ SETTERS ------

    /**
     * @brief Sets the registration year for the vehicle.
     * @param year The registration year for the vehicle.
     */
    void setLicensePlateYear(int year);

    /**
     * @brief Sets the brand of the vehicle.
     * @param brand The brand of the vehicle.
     */
    void setBrand(const std::string& brand);

    /**
     * @brief Sets the primary fuel type of the vehicle.
     * @param newFuelType The primary fuel type of the vehicle.
     */
    void setFuelType(FuelType newFuelType);

    /**
     * @brief Sets the secondary fuel type of the hybrid vehicle.
     * @param newSecondaryFuelType The secondary fuel type of the hybrid vehicle.
     */
    void setSecondaryFuelType(FuelType newSecondaryFuelType);

    /**
     * @brief Sets the motor type of the vehicle.
     * @param newMotorType The motor type of the vehicle.
     */
    void setMotorType(MotorType newMotorType);

    /**
     * @brief Sets the price of the vehicle.
     * @param newPrice The price of the vehicle.
     */
    void setPrice(float newPrice);

    /**
     * @brief Sets the unique identifier of the vehicle.
     * @param newID The new unique identifier for the vehicle.
     */
    void setVehicleID(int newID);

    /**
     * @brief Gets the secondary fuel type of the hybrid vehicle.
     * @return The secondary fuel type of the hybrid vehicle.
     */
    FuelType getSecondaryFuelType() const;
};

#endif //VEHICLE_H