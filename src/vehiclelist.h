#ifndef VEHICLELIST_H
#define VEHICLELIST_H

#include <list>

class Vehicle;

/**
 * @class VehicleList
 * @brief Represents a list of vehicles.
 */
class VehicleList {
private:
    std::list<Vehicle*> vehicleList; /**< List of vehicles */

public:

    /**
     * @brief Find a vehicle by its ID.
     * @param vehicleID The ID of the vehicle to find.
     * @return A pointer to the found vehicle, or nullptr if not found.
     */
    virtual Vehicle* findVehicleByID(int vehicleID);

    /**
     * @brief Add a vehicle to the list.
     * @param vehicle The vehicle to add.
     * @return 0 if the vehicle was added successfully
     * @return -1 if the vehicle with the same ID already exists.
     */
    int addVehicle(Vehicle* vehicle);

    /**
     * @brief Remove a vehicle from the list by its ID.
     * @param vehicleID The ID of the vehicle to remove.
     * @return 0 if the vehicle was removed successfully
     * @return -1 if the vehicle was not found.
     */
    virtual int removeVehicleByID(int vehicleID);

    /**
     * @brief Print the list of vehicles to the console.
     */
    void printVehicleList() const;

    /**
     * @brief Get the list of vehicles.
     * @return A reference to the list of vehicles.
     */
    const std::list<Vehicle*>& getVehicleList() const;
};

#endif //VEHICLELIST_H
