#ifndef MOTOR_H
#define MOTOR_H

/**
 * @brief Enum types of fuel types.
 */
enum class FuelType {
    NONE,
    DIESEL,      /**< Diesel fuel */
    ELECTRICITY, /**< Electric power */
    GASOLINE,    /**< Gasoline fuel */
    LPG,         /**< Gas */
};

/**
 * @brief Enum types of motors.
 */
enum class MotorType {
    ELECTRIC,   /**< Electric motor */
    COMBUSTION, /**< Combustion engine */
    HYBRID      /**< Hybrid motor */
};

class Motor {
private:
    float power; /**< Power of the motor in Cv */

public:
    /**
    * @brief Constructor for the Motor class.
    * @param power The power of the motor in Cv.
    */
    explicit Motor(float power);

    /**
     * @brief Virtual destructor for the Motor class.
     */
    virtual ~Motor();

    /**
     * @brief Pure virtual function to get the power of the motor.
     * @return The power of the motor.
     */
    virtual float Power() const = 0;

    /**
     * @brief Virtual function to get the power of the motor.
     * @return The power of the motor.
     */
    virtual float getPower() const;

    /**
     * @brief Pure virtual function to get the capacity of the motor.
     * @return The capacity of the motor.
     */
    virtual float getCapacity() const = 0;

    /**
     * @brief Display information about the motor.
     */
    virtual void displayInfo() const;
};

/* ----------------------- ICE CLASS -------------------------*/
/**
 * @class ICE
 * @brief Represents an Combustion Engine (ICE) motor.
 */
class ICE: public Motor {
private:
    FuelType fuelType; /**< Type of fuel (DIESEL, GASOLINE, LPG) */
    float capacity;    /**< Capacity of the tank in liters */

public:
    /**
     * @brief Constructor for the ICE class.
     * @param power The power of the motor in Cv.
     * @param capacity The capacity of the tank in liters.
     * @param fuelType The type of fuel (DIESEL, GASOLINE, LPG).
     */
    ICE(float power, float capacity, FuelType fuelType);

    /**
    * @brief Destructor for the ICE class.
    */
    ~ICE() override;

    /**
    * @brief Function to get the power of the ICE motor.
    * @return The power of the ICE motor.
    */
    float Power() const override;

    /**
     * @brief Function to get the capacity of the ICE motor.
     * @return The capacity of the tank in liters.
     */
    float getCapacity() const override;

    /**
     * @brief Function to display information about the ICE motor.
     */
    void displayInfo() const override;

};

/* ----------------------- BEV CLASS -------------------------*/
/**
 * @class BEV
 * @brief Represents an Electric motor (BEV) motor.
 */
class BEV : public Motor {
private:
    float capacity; /**< Capacity of the battery in kWh */

public:
    /**
     * @brief Constructor for the BEV class.
     * @param power The power of the motor in Cv.
     * @param capacity The capacity of the battery in kWh.
     */
    BEV(float power, float capacity);

    /**
     * @brief Destructor for the BEV class.
     */
    ~BEV() override;

    /**
     * @brief Overridden function to get the power of the BEV motor.
     * @return The power of the BEV motor.
     */
    float Power() const override;

    /**
     * @brief Overridden function to get the capacity of the BEV motor.
     * @return The capacity of the battery in kWh.
     */
    float getCapacity() const override;

    /**
     * @brief Overridden function to display information about the BEV motor.
     */
    void displayInfo() const override;
};

#endif //MOTOR_H
