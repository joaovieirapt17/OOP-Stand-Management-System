#ifndef MENU_H
#define MENU_H

#include "user.h"
#include "vehicle.h"
#include "car.h"
#include "stand.h"
#include "vehiclefactory.h"

/**
 * @file menu.h
 * @brief Defines functions related to user interfaces and menus.
 */


using namespace std;

/**
 * @brief Pauses the program and waits for any key press.
 */
void anyKey();

/* ------------ Initial Menu -------------- */
/**
 * @brief Displays the initial menu for user authentication.
 * @param userList Reference to the UserList containing user data.
 * @param auth Pointer to the authenticated User.
 * @return An integer representing the selected option.
 */
int initialMenu(UserList& userList, User** auth);

/* ------------ Login Menu -------------- */
/**
 * @brief Displays the login menu for user authentication.
 * @param userList Reference to the UserList containing user data.
 * @param auth Pointer to the authenticated User.
 * @return An integer representing the selected option.
 */
int loginMenu(UserList& userList, User** auth);

/* ------------ Admin Menu -------------- */
/**
 * @brief Displays the admin menu.
 * @param auth The authenticated admin User.
 * @param userList Reference to the UserList containing user data.
 * @param stands Reference to the GestStand object for stand management.
 * @return An integer representing the selected option.
 */
int adminMenu(const User& auth, UserList& userList, GestStand& stands);

/* 1 - Manage Managers Menu */
/**
 * @brief Displays the menu for managing managers.
 * @param auth The authenticated admin User.
 * @param users Reference to the UserList containing user data.
 */
void manageManagersMenu(const User& auth, UserList& users);

/**
 * @brief Creates a new manager and adds it to the UserList.
 * @param users Reference to the UserList containing user data.
 * @return An integer representing the result of the operation.
 */
int createManager(UserList& users);

/**
 * @brief Edits the data of an existing manager.
 * @param users Reference to the UserList containing user data.
 */
void editManagerData(UserList& users);

/**
 * @brief Lists the registered managers.
 * @param userList Reference to the UserList containing user data.
 */
void listRegisteredManagers(const UserList& userList);

/**
 * @brief Removes a manager from the UserList.
 * @param users Reference to the UserList containing user data.
 */
void removeManager(UserList& users);

/* ------------ Manager Menu -------------- */
/**
 * @brief Displays the menu for managing as a manager.
 * @param auth The authenticated manager User.
 * @param users Reference to the UserList containing user data.
 * @param stands Reference to the GestStand object for stand management.
 * @return An integer representing the selected option.
 */
int managerMenu(const User& auth, UserList& users, GestStand& stands);

/* 2 - Manage Clients Menu */
/**
 * @brief Displays the menu for managing clients.
 * @param auth The authenticated manager User.
 * @param users Reference to the UserList containing user data.
 */
void manageClientsMenu(const User& auth, UserList& users);
/**
 * @brief Creates a new client and adds it to the UserList.
 * @param users Reference to the UserList containing user data.
 * @return An integer representing the result of the operation.
 */
int createClient(UserList &users);

/**
 * @brief Edits the data of an existing client.
 * @param users Reference to the UserList containing user data.
 */
void editClientData(UserList& users);

/**
 * @brief Lists the registered clients.
 * @param userList Reference to the UserList containing user data.
 */
void listRegisteredClients(const UserList& userList);

/**
 * @brief Removes a client from the UserList.
 * @param users Reference to the UserList containing user data.
 */
void removeClient(UserList& users);

/* 3 - Manage Stands Menu */
/**
 * @brief Displays the menu for managing stands and vehicles.
 * @param auth The authenticated manager User.
 * @param stands Reference to the GestStand object for stand management.
 */
void manageStandsMenu(const User& auth, GestStand& stands);

/**
 * @brief Creates a new stand and adds it to the GestStand object.
 * @param stands Reference to the GestStand object for stand management.
 * @return An integer representing the result of the operation.
 */
int createStand(GestStand& stands);

/**
 * @brief Creates a new vehicle and adds it to the GestStand object.
 * @param vehicleStand Reference to the GestStand object for stand management.
 * @return An integer representing the result of the operation.
 */
int createVehicle(GestStand& vehicleStand);

/**
 * @brief Moves a vehicle to another stand within the GestStand object.
 * @param vehicleStand Reference to the GestStand object for stand management.
 * @return An integer representing the result of the operation.
 */
int moveVehicleToAnotherStand(GestStand& vehicleStand);

/**
 * @brief Removes a vehicle from a stand within the GestStand object.
 * @param vehicleStand Reference to the GestStand object for stand management.
 */
void removeVehicleFromStand(GestStand& vehicleStand);

/**
 * @brief Edits the data of an existing vehicle within the GestStand object.
 * @param vehicleStand Reference to the GestStand object for stand management.
 */
void editVehicleData(GestStand& vehicleStand);

/* -------------- Client Menu ------------------ */

/**
 * @brief Displays the menu for managing as a client.
 * @param auth The authenticated client User.
 * @param users Reference to the UserList containing user data.
 * @param stands Reference to the GestStand object for stand management.
 * @return An integer representing the selected option.
 */
int clientMenu(User auth, UserList& users, GestStand& stands);

/**
 * @brief Edits the data of the authenticated client.
 * @param users Reference to the UserList containing user data.
 * @param auth The authenticated client User.
 */
void editClientOwnData(UserList& users, User& auth);

/**
 * @brief Lists the vehicles available in a stand within the GestStand object.
 * @param vehicleStand Reference to the GestStand object for stand management.
 */
void listVehiclesInStand(const GestStand& vehicleStand);

/**
 * @brief Lists stands by city within the GestStand object.
 * @param vehicleStand Reference to the GestStand object for stand management.
 */
void listStandsByCity(const GestStand& vehicleStand);

/**
 * @brief Initiates the process of purchasing a vehicle.
 * @param vehicleStand Reference to the GestStand object for stand management.
 * @param users Reference to the UserList containing user data.
 * @param auth The authenticated client User.
 */
void buyVehicle(GestStand& vehicleStand, UserList& users, User& auth);

/**
 * @brief Displays the purchase history of the authenticated client.
 * @param auth The authenticated client User.
 */
void clientPurchaseHistory(User& auth);

/**
 * @brief Changes the balance of the authenticated client.
 * @param auth The authenticated client User.
 */
void changeBalance(User& auth);

#endif //MENU_H
