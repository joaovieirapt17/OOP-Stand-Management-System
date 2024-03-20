#ifndef STAND_H
#define STAND_H

#include <map>
#include <list>
#include <vector>

#include "vehicle.h"

// Stand CLASS
/**
 * @class Stand
 * @brief Represents a stand with a unique code based on city and number.
 */
class Stand {
private:
    std::string cityName; /**< City where the stand is located */
    int number{};  /**< An integer between 1 and 99 */
    std::string code; /**< Unique code based on city and number */

public:
    // Constructor
    Stand();

    /**
     * @brief Constructor with arguments.
     * @param cityName  City where the stand is located.
     * @param number Stand number (an integer between 1 and 99).
     */
    Stand(const std::string& cityName, int number);

    /**
     * @brief Get the city name of the stand.
     * @return City name.
     */
    std::string getCityName() const;

    /**
     * @brief Get the stand number.
     * @return Stand number.
     */
    int getNumber() const;

    /**
     * @brief Get a string representation of the stand.
     * @return Code concatenated from the city name and the stand number.
     */
    [[nodiscard]] std::string toString() const;
};

/* ----------------------- GestStand CLASS -------------------------*/

// GestStand ABSTRACT CLASS
/**
 * @class GestStand
 * @brief Abstract stand management class with the implementation of the methods from VehicleStand class.
 */
class GestStand {
public:
    /**
     * @brief Add a vehicle to a stand.
     * @param vehicle The vehicle to add.
     * @param stand The stand to add the vehicle to.
     * @return 0 if the operation was successful, -1 otherwise.
     */
    virtual int addVehicleToStand(Vehicle* vehicle, Stand* stand) = 0;

    /**
     * @brief Display all stands and their associated vehicles.
     */
    virtual void displayMapStandsVehicles() const = 0;

    /**
     * @brief Add a stand to the map.
     * @param cityName The city where the stand is located.
     * @param number The stand number.
     * @return 0 if the operation was successful, -1 otherwise.
     */
    virtual int addStand(const std::string& cityName, int number) = 0;

    /**
     * @brief Find a stand by its code.
     * @param standCode The code of the stand to find.
     * @return A pointer to the found stand, or nullptr if not found.
     */
    virtual Stand* findStandByCode(const std::string& standCode) const = 0;

    /**
     * @brief Remove a stand by its code.
     * @param standCode The code of the stand to remove.
     * @return 0 if the operation was successful, -1 otherwise.
     */
    virtual int removeStandByCode(const std::string& standCode) = 0;

    /**
     * @brief Save stands data to a text file.
     * @return 0 if the operation was successful, -1 otherwise.
     */
    virtual int saveStandsDataTxt() = 0;

    /**
     * @brief Get the list of vehicles associated with a stand.
     * @param stand The stand for which to retrieve the vehicle list.
     * @return A pointer to the vehicle list associated with the stand.
     */
    virtual VehicleList* getVehicleListByStand(Stand* stand) const = 0;

    /**
     * @brief Display all available stands.
     */
    virtual void displayStands() const = 0;

    /**
     * @brief Move a vehicle from one stand to another.
     * @param vehicle The vehicle to move.
     * @param destinationStandCode The code of the destination stand.
     */
    virtual void moveVehicle(Vehicle* vehicle, const std::string& destinationStandCode) = 0;

    /**
     * @brief Find a stand by vehicle ID.
     * @param vehicleID The ID of the vehicle to find.
     * @return A pointer to the found stand, or nullptr if not found.
     */
    virtual Stand *findStandByVehicleID(int vehicleID) const = 0;

    /**
     * @brief Find a vehicle by its ID.
     * @param vehicleID The ID of the vehicle to find.
     * @return A pointer to the found vehicle, or nullptr if not found.
     */
    virtual Vehicle* findVehicleByID(int vehicleID) const = 0;

    /**
     * @brief Remove a vehicle by its ID.
     * @param vehicleID The ID of the vehicle to remove.
     * @return 0 if the operation was successful, -1 otherwise.
     */
    virtual int removeVehicleByID(int vehicleID) = 0;

    /**
     * @brief Get the map of stands and associated vehicle lists.
     * @return A reference to the map of stands and vehicle lists.
     */
    virtual const std::map<Stand *, VehicleList *> &getStandVehicleMap() const = 0;

    /**
     * @brief Load stands and associated vehicles from a CSV file.
     * @param filename The name of the CSV file.
     * @return 0 if the operation was successful, -1 otherwise.
     */
    virtual void loadCsvData(const std::string &filename) = 0;

    /**
     * @brief Split a string into a vector of strings using a delimiter.
     * @param str The string to split.
     * @param delimiter The character used as a delimiter.
     * @return A vector of strings resulting from the split operation.
     */
    virtual std::vector<std::string> split(std::string &str, char delimiter) = 0;

    /**
     * @brief Load stands and associated vehicles from a text file.
     */
    virtual int loadStandsDataTxt() = 0;

    // Virtual destructor for proper cleanup
    /**
     * @brief Virtual destructor for proper cleanup.
     */
    virtual ~GestStand() = default;
};

/* ----------------------- VehicleStand CLASS -------------------------*/

// VehicleStand CLASS
class VehicleStand : public GestStand {
private:
    std::map<Stand*, VehicleList*> standVehicleMap;  /**< map of the Vehicles and Stands */

public:
    // Constructor
    VehicleStand();

    int addVehicleToStand(Vehicle* vehicle, Stand* stand) override;
    void moveVehicle(Vehicle* vehicle, const std::string& destinationStandCode) override;
    void displayStands() const override;
    void displayMapStandsVehicles() const override;
    int addStand(const std::string& cityName, int number) override;
    Stand* findStandByCode(const std::string& standCode) const override;
    int removeStandByCode(const std::string& standCode) override;
    int saveStandsDataTxt() override;
    VehicleList* getVehicleListByStand(Stand* stand) const override;
    Stand *findStandByVehicleID(int vehicleID) const override;
    Vehicle* findVehicleByID(int vehicleID) const override;
    int removeVehicleByID(int vehicleID) override;
    const std::map<Stand *, VehicleList *> &getStandVehicleMap() const override;
    void loadCsvData(const std::string &filename) override;
    int loadStandsDataTxt() override;
    std::vector<std::string> split(std::string &str, char delimiter) override;
};

#endif //STAND_H
