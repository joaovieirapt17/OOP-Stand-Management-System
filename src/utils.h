#ifndef UTILS_H
#define UTILS_H

#include "vehicle.h"
#include "car.h"
#include "user.h"

#include <fstream>

enum class Role;

/**
 * @brief Convert FuelType enum to a string.
 * @param fuelType The FuelType enum to convert.
 * @return A string representation of the FuelType.
 */
std::string fuelTypeToString(FuelType fuelType);

/**
 * @brief Convert a string to FuelType enum.
 * @param fuelTypeString The string to convert.
 * @return The corresponding FuelType enum.
 */
FuelType stringToFuelType(const std::string &fuelTypeString);

/**
 * @brief Convert MotorType enum to a string.
 * @param motorType The MotorType enum to convert.
 * @return A string representation of the MotorType.
 */
std::string motorTypeToString(MotorType motorType);

/**
 * @brief Convert a string to MotorType enum.
 * @param motorTypeString The string to convert.
 * @return The corresponding MotorType enum.
 */
MotorType stringToMotorType(const std::string& motorTypeString);

/**
 * @brief Write vehicle data to a file.
 * @param file The output file stream.
 * @param vehicleList The list of vehicles to write to the file.
 */
void writeVehicleDataToFile(std::ofstream& file, const VehicleList* vehicleList);

/**
 * @brief Convert Role enum to a string.
 * @param role The Role enum to convert.
 * @return A string representation of the Role.
 */
std::string roleToString(Role role);

/**
 * @brief Convert a string to Role enum.
 * @param roleString The string to convert.
 * @return The corresponding Role enum.
 */
Role stringToRole(const std::string& roleString);

#endif //UTILS_H
