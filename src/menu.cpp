#include <iostream>
#include <string>
#include <conio.h> // _getch()
#include <limits> // numeric_limits (clean buffer)


#include "menu.h"

using namespace std;

void anyKey() {
    cout << "\n Press any key to continue...";
    _getch();
}

/* ------------ Initial Menu -------------- */
int initialMenu(UserList& userList, User** auth) {
    int option = 1;

    do {

        cout << "+--------------------------------------------------------------+\n";
        cout << "|                      SOFTWARE STAND MANAGEMENT               |\n";
        cout << "+--------------------------------------------------------------+\n\n";
        cout << "[ 1 ] Authenticate\n";
        cout << "[ 0 ] Exit\n\n";
        cout << "Option:";
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        if (option == 1) {
            if (loginMenu(userList, auth) == 0) {
                return 0;
            }
        }
    } while (option != 0);

    return -1;
}

/* ------------ Login Menu -------------- */
int loginMenu(UserList& userList, User** auth) {
    char username[100], password[100];
    int option = 1;

    do {
        cout << "+------------------------+\n";
        cout << "|      AUTHENTICATION    |\n";
        cout << "+------------------------+\n\n";

        cout << " | Username: ";
        cin >> username;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "| Password: ";
        cin >> password;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        *auth = userList.login(username, password);

        if (*auth != nullptr) {
            return 0;
        }

        if (*auth == nullptr) {
            do {
                cout << "+---------------------------------\n";
                cout << "|   Invalid authentication data!  |\n";
                cout << "+---------------------------------\n\n";
                cout << "[1] Try again!\n";
                cout << "[0] Cancel\n\n";
                cout << "Option: ";
                cin >> option;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

            } while (option < 0 || option > 1);
        }
    } while (*auth == nullptr && option != 0);

    return -1;
}

/* ------------ Admin Menu -------------- */
int adminMenu(const User& auth, UserList& users, GestStand& stands) {
    int choice;

    do {
        cout << "+--------------------------------------+\n";
        cout << "|              ADMIN MENU              |\n";
        cout << "+--------------------------------------+\n\n";

        cout << "[ 1 ] Manage Managers\n";
        cout << "[ 2 ] Manage Clients\n";
        cout << "[ 3 ] Manage Stands\n";
        cout << "[ 9 ] End Session\n";
        cout << "[ 0 ] Exit\n\n";
        cout << "Option: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                manageManagersMenu(auth, users);
                break;
            case 2:
                manageClientsMenu(auth, users);
                break;
            case 3:
                manageStandsMenu(auth, stands);
                break;
            case 9:
                return -4;
            default:
                break;
        }
    } while (choice != 0);

    return 0;
}

/* 1 - Manage Managers Menu */
void manageManagersMenu(const User& auth, UserList& users) {
    int choice;

    do {
        cout << "+--------------------------------------+\n";
        cout << "|         MANAGE MANAGERS MENU         |\n";
        cout << "+--------------------------------------+\n\n";

        cout << "[ 1 ] Register Manager\n";
        cout << "[ 2 ] Edit Managers Data\n";
        cout << "[ 3 ] List Registered Managers\n";
        cout << "[ 4 ] Delete Manager Account\n";
        cout << "[ 0 ] Exit\n\n";
        cout << "Option: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                createManager(users);
                anyKey();
                break;
            case 2:
                editManagerData(users);
                anyKey();
                break;
            case 3:
                listRegisteredManagers(users);
                anyKey();
                break;
            case 4:
                removeManager(users);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option! Try again...\n";
                break;
        }
    } while (choice != 0);
}

int createManager(UserList& users) {
    int option, result;
    User* newManager = nullptr; // Declare the object outside the loop

    do {
        cout << "| New Manager\n";

        cout << "  | Username: ";
        string newUsername;
        cin >> newUsername;

        cout << " | Password: ";
        string newPassword;
        cin >> newPassword;

        cout << " | Name: ";
        string newName;
        cin.ignore();
        getline(cin, newName); // Accept names with spaces

        cout << " | NIF: ";
        int newNIF;
        cin >> newNIF;

        cout << " | Balance: ";
        float newBalance;
        cin >> newBalance;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Allocate memory for newManager
        newManager = new User(newUsername, newPassword, newName, newNIF, newBalance, Role::manager);

        // Add the new manager to the UserList
        result = users.addUser(newManager);

        switch (result) {
            case 0: // Success
                UserList::saveUsersListTxt(users);  // Save the manager to txt file
                cout << "Manager created successfully.\n";
                return 0;
            case -1:
                do {
                    cout << "Username already exists\n";
                    cout << "[1] Try again!\n";
                    cout << "[0] Cancel\n\n";
                    cout << "Option: ";
                    cin >> option;
                    while (cin.get() != '\n');
                } while (option < 0 || option > 1);
                break;
            default:
                break;
        }
    } while (option != 0);

    delete newManager;
    return -1;
}

void editManagerData(UserList& users) {
    int option = 1, selected, newNif;
    string username, newName, newPassword;
    User* user = nullptr; // Declare the object outside the loop

    do {
        cout << "Manager Username: ";
        cin >> username;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        user = users.findUserByUsername(username);

        if (user == nullptr) {
            do {
                cout << "User not found!\n\n";
                cout << "[1] Try again\n";
                cout << "[0] Cancel\n\n";
                cout << "Option: ";
                cin >> option;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } while (option < 0 || option > 1);
        } else {
            do {
                cout << "Which field do you want to edit?\n";
                cout << "[1] Name\n";
                cout << "[2] Password\n";
                cout << "[3] NIF\n";
                cout << "[0] Cancel\n";
                cout << "Option: ";
                cin >> selected;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (selected) {
                    case 0:
                        return;

                    case 1:
                        cout << "| New name: ";
                        cin.ignore();
                        getline(cin, newName);
                        user->setName(newName);
                        UserList::saveUsersListTxt(users);
                        cout << "\nName changed successfully!\n";
                        break;

                    case 2:
                        cout << "| New password: ";
                        cin >> newPassword;
                        user->setPassword(newPassword);
                        UserList::saveUsersListTxt(users);
                        cout << "\nPassword changed successfully!\n";
                        break;

                    case 3:
                        cout << "| New NIF: ";
                        cin >> newNif;
                        user->setNIF(newNif);
                        UserList::saveUsersListTxt(users);
                        cout << "\nNIF changed Successfully!\n";
                    default:
                        cout << "Invalid Option! Try again. \n";
                        break;
                }

                if (selected != 0) {
                    do {
                        cout << "\nDo you want to continue altering data for this user?";
                        cout << "\n[1] Yes";
                        cout << "\n[0] No";
                        cout << "\nOption: ";
                        cin >> option;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } while (option != 0 && option != 1);
                }
            } while (selected != 0 && option != 0);
        }
    } while (option != 0);
}

void listRegisteredManagers(const UserList& userList) {
    for (const auto& user : userList.getUserList()) {
        if (user->getRole() == Role::manager && user->getUsername() != "admin") {
            cout << user->getName() << endl;
        }
    }
}

void removeManager(UserList& users) {
    int option = 0;
    string username;

    do {
        cout << "Username of the manager to remove: ";
        cin >> username;

        // Find the provided user in the list
        User* user = users.findUserByUsername(username);

        if (user == nullptr) {
            cout << "User not found!\n\n";
            cout << "[1] Try again\n";
            cout << "[0] Cancel\n\n";
            cin >> option;
            continue;
        }

        // Check if the user is client
        if (user->getRole() != Role::manager) {
            cout << "The user is not a client!" << endl;
            cout << "[1] Try again\n";
            cout << "[0] Cancel\n\n";
            cin >> option;
            continue;
        }

        // Remove the user from the list
        int result = users.removeUserByUsername(username);

        switch (result) {
            case 0:
                cout << "User removed successfully!" << endl;
                UserList::saveUsersListTxt(users); // saves the updated list to the txt file
                return;

            case -1:
                cout << "User doesnt exist!" << endl;
                cout << "[1] Try again\n";
                cout << "[0] Cancel\n\n";
                cin >> option;
                break;
            default:
                break;
        }
    } while (option != 0);
}

/* ------------ Manager Menu -------------- */
int managerMenu(const User& auth, UserList& users, GestStand& stands) {
    int choice;

    do {
        cout << "+--------------------------------------+\n";
        cout << "|               MANAGER MENU           |\n";
        cout << "+--------------------------------------+\n\n";

        cout << "[ 1 ] Manage Clients\n";
        cout << "[ 2 ] Manage Stands\n";
        cout << "[ 9 ] End Session\n";
        cout << "[ 0 ] Exit\n\n";
        cout << "Option: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                manageClientsMenu(auth, users);
                break;
            case 2:
                manageStandsMenu(auth, stands);
                break;
            case 9:
                return -4;

            default:
                break;
        }
    } while (choice != 0);

    return 0;
}

/* 2 - Manage Clients Menu */
void manageClientsMenu(const User& auth, UserList& users) {
    int choice;

    do {
        cout << "+--------------------------------------+\n";
        cout << "|         MANAGE CLIENTS MENU          |\n";
        cout << "+--------------------------------------+\n\n";

        cout << "[ 1 ] Register Client\n";
        cout << "[ 2 ] Edit Clients Data\n";
        cout << "[ 3 ] List Registered Clients\n";
        cout << "[ 4 ] Delete Client Account\n";
        cout << "[ 0 ] Exit\n\n";
        cout << "Option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createClient(users);
                anyKey();
                break;
            case 2:
                editClientData(users);
                anyKey();
                break;
            case 3:
                listRegisteredClients(users);
                anyKey();
                break;
            case 4:
                removeClient(users);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option! Try again...\n";
                break;
        }
    } while (choice != 0);
}


int createClient(UserList& users) {
    int option, result;
    User* newClient = nullptr; // Declare the object outside the loop

    do {
        cout << "| New Client\n";

        cout << "  | Username: ";
        string newUsername;
        cin >> newUsername;

        cout << "  | Password: ";
        string newPassword;
        cin >> newPassword;

        cout << "  | Name: ";
        string newName;
        cin.ignore();
        getline(cin, newName); // Accept names with spaces

        cout << "  | NIF: ";
        int newNIF;
        cin >> newNIF;

        cout << "  | Balance: ";
        float newBalance;
        cin >> newBalance;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Allocate memory for newClient
        newClient = new User(newUsername, newPassword, newName, newNIF, newBalance, Role::client);

        // Add the new client to the UserList
        result = users.addUser(newClient);

        switch (result) {
            case 0: // Success
                UserList::saveUsersListTxt(users);  // Save the client to txt file
                cout << "Client created successfully.\n";
                return 0;
            case -1:
                do {
                    cout << "Username already exists\n";
                    cout << "[1] Try again!\n";
                    cout << "[0] Cancel\n\n";
                    cout << "Option: ";
                    cin >> option;
                    while (cin.get() != '\n');
                } while (option < 0 || option > 1);
                break;
            default:
                break;
        }
    } while (option != 0);

    delete newClient;
    return -1;
}

void editClientData(UserList& users) {
    int option = 1, selected, newNif;
    float newBalance;
    string username, newName, newPassword;
    User* user = nullptr; // Declare the object outside the loop

    do {
        cout << "Client Username: ";
        cin >> username;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        user = users.findUserByUsername(username);

        if (user == nullptr) {
            do {
                cout << "User not found!\n\n";
                cout << "[1] Try again\n";
                cout << "[0] Cancel\n\n";
                cout << "Option: ";
                cin >> option;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } while (option < 0 || option > 1);
        } else {
            do {
                cout << "Which field do you want to edit?\n";
                cout << "[1] Name\n";
                cout << "[2] Password\n";
                cout << "[3] NIF\n";
                cout << "[4] Balance\n";
                cout << "[0] Cancel\n";
                cout << "Option: ";
                cin >> selected;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (selected) {
                    case 0:
                        return;

                    case 1:
                        cout << "| New name: ";
                        cin.ignore();
                        getline(cin, newName);
                        user->setName(newName);
                        UserList::saveUsersListTxt(users);
                        cout << "\nName changed successfully!\n";
                        break;

                    case 2:
                        cout << "| New password: ";
                        cin >> newPassword;
                        user->setPassword(newPassword);
                        UserList::saveUsersListTxt(users);
                        cout << "\nPassword changed successfully!\n";
                        break;

                    case 3:
                        cout << "| New NIF: ";
                        cin >> newNif;
                        user->setNIF(newNif);
                        UserList::saveUsersListTxt(users);
                        cout << "\nNIF changed Successfully!\n";

                    case 4:
                        cout << "| New Balance: ";
                        cin >> newBalance;
                        user->setBalance(newBalance);
                        UserList::saveUsersListTxt(users);
                        cout << "\nBalance changed Successfully!\n";
                    default:
                        cout << "Invalid Option! Try again. \n";
                        break;
                }

                if (selected != 0) {
                    do {
                        cout << "\nDo you want to continue altering data for this user?";
                        cout << "\n[1] Yes";
                        cout << "\n[0] No";
                        cout << "\nOption: ";
                        cin >> option;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } while (option != 0 && option != 1);
                }
            } while (selected != 0 && option != 0);
        }
    } while (option != 0);
}

void listRegisteredClients(const UserList& userList) {
    for (const auto& user : userList.getUserList()) {
        if (user->getRole() == Role::client) {
            cout << user->getName() << endl;
        }
    }
}

void removeClient(UserList& users) {
    int option = 0;
    string username;

    do {
        cout << "Username of the client to remove: ";
        cin >> username;

        // Find the provided user in the list
        User* user = users.findUserByUsername(username);

        if (user == nullptr) {
            cout << "User not found!\n\n";
            cout << "[1] Try again\n";
            cout << "[0] Cancel\n\n";
            cin >> option;
            continue;
        }

        // Check if the user is client
        if (user->getRole() != Role::client) {
            cout << "The user is not a client!" << endl;
            cout << "[1] Try again\n";
            cout << "[0] Cancel\n\n";
            cin >> option;
            continue;
        }

        // Remove the user from the list
        int result = users.removeUserByUsername(username);

        switch (result) {
            case 0:
                cout << "User removed successfully!" << endl;
                UserList::saveUsersListTxt(users); // saves the updated list to the txt file
                return;

            case -1:
                cout << "User doesnt exist!" << endl;
                cout << "[1] Try again\n";
                cout << "[0] Cancel\n\n";
                cin >> option;
                break;
            default:
                break;
        }
    } while (option != 0);
}


/* 3-  Manage Stands Menu */
void manageStandsMenu(const User& auth, GestStand& stands) {
    int choice;

    do {
        cout << "+--------------------------------------+\n";
        cout << "|         MANAGE STANDS MENU           |\n";
        cout << "+--------------------------------------+\n\n";

        cout << "[ 1 ] Create Stand\n";
        cout << "[ 2 ] Create Vehicle\n";
        cout << "[ 3 ] Move Vehicle to Another Stand\n";
        cout << "[ 4 ] Edit Vehicle Data\n";
        cout << "[ 5 ] List Vehicles in a Stand\n";
        cout << "[ 6 ] List Stands by City Name\n";
        cout << "[ 7 ] Remove Vehicle from Stand\n";
        cout << "[ 0 ] Exit\n\n";
        cout << "Option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createStand(stands);
                anyKey();
                break;
            case 2:
                createVehicle(stands);
                anyKey();
                break;
            case 3:
                moveVehicleToAnotherStand(stands);
                anyKey();
                break;
            case 4:
                editVehicleData(stands);
                anyKey();
                break;
            case 5:
                listVehiclesInStand(stands);
                anyKey();
                break;
            case 6:
                listStandsByCity(stands);
                anyKey();
                break;
            case 7:
                removeVehicleFromStand(stands);
                anyKey();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option! Try again...\n";
                break;
        }
    } while (choice != 0);
}


int createStand(GestStand& stands) {
    int option, result;
    Stand* newStand = nullptr;

    do {
        cout << "| New Stand\n";

        cout << "  | City Name: ";
        string newCityName;
        cin >> newCityName;

        cout << "  | Stand Number (between 1 and 99): ";
        int newStandNumber;
        cin >> newStandNumber;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Allocate memory for newStand
        newStand = new Stand(newCityName, newStandNumber);

        // Add the new stand to the VehicleStand
        result = stands.addStand(newCityName, newStandNumber);

        switch (result) {
            case 0: // Success
                stands.saveStandsDataTxt();  // Save the stand to txt file
                cout << "Stand created successfully.\n";
                return 0;
            case -1:
                do {
                    cout << "Stand with the same code already exists\n";
                    cout << "[1] Try again!\n";
                    cout << "[0] Cancel\n\n";
                    cout << "Option: ";
                    cin >> option;
                    while (cin.get() != '\n');
                } while (option < 0 || option > 1);
                break;
            default:
                break;
        }
    } while (option != 0);

    delete newStand;
    return -1;
}

int createVehicle(GestStand& vehicleStand) {
    int option, result;
    Vehicle* newVehicle = nullptr;

    do {
        cout << "| New Vehicle\n";

        // Vehicle Type
        cout << "\n  | Vehicle Type:\n";
        cout << "    [1] Coupe\n";
        cout << "    [2] Sedan\n";
        cout << "    [3] Motorcycle\n";
        int vehicleTypeOption;
        cout << "    Option: ";
        cin >> vehicleTypeOption;

        cout << "  | License Plate Year: ";
        int newLicensePlateYear;
        cin >> newLicensePlateYear;

        cout << " | Brand: ";
        string newBrand;
        cin.ignore();
        getline(cin, newBrand);

        // Motor Type
        MotorType newMotorType;
        do {
            cout << "\n  | Motor Type:\n";
            cout << "    [1] Electric\n";
            cout << "    [2] Combustion\n";
            if (vehicleTypeOption != 3) {
                cout << "    [3] Hybrid\n";
            }
            cout << "    Option: ";
            cin >> option;

            switch (option) {
                case 1:
                    newMotorType = MotorType::ELECTRIC;
                    break;
                case 2:
                    newMotorType = MotorType::COMBUSTION;
                    break;
                case 3:
                    if (vehicleTypeOption != 3) {
                        newMotorType = MotorType::HYBRID;
                    } else {
                        cout << "Hybrid motor type is not available for motorcycles. Please choose again!\n";
                        continue; // back to the beginning of the loop
                    }
                    break;
                default:
                    cout << "Please choose a valid option between 1 and 3.\n";
            }
        } while (option < 1 || option > 3);

        FuelType primaryFuelType, secondaryFuelType;
        if (newMotorType == MotorType::ELECTRIC) {
            // Electric vehicles the fuel type must be electricity
            primaryFuelType = FuelType::ELECTRICITY;
            secondaryFuelType = FuelType::NONE;

        } else if (newMotorType == MotorType::HYBRID) {
            cout << "\n  | Primary Combustion Motor Fuel Type:\n";
            do {
                cout << "    [1] DIESEL\n";
                cout << "    [2] GASOLINE\n";
                cout << "    [3] LPG\n";
                cout << "    Option: ";
                cin >> option;

                switch (option) {
                    case 1:
                        primaryFuelType = FuelType::DIESEL;
                        break;
                    case 2:
                        primaryFuelType = FuelType::GASOLINE;
                        break;
                    case 3:
                        primaryFuelType = FuelType::LPG;
                        break;
                    default:
                        cout << "Please choose a valid option between 1 and 3.\n";
                }
            } while (option < 1 || option > 3);

            cout << "\n  | Secondary Electric Motor Fuel Type:\n";
            do {
                cout << "    [1] ELECTRICITY\n";
                cout << "    Option: ";
                cin >> option;

                if (option == 1) {
                    secondaryFuelType = FuelType::ELECTRICITY;
                } else {
                    cout << "Please choose a valid option!\n";
                }
            } while (option != 1);
        } else { // If isn't a hybrid vehicle or motor type isn't electric
            do {
                cout << "\n  | Fuel Type:\n";
                cout << "    [1] DIESEL\n";
                cout << "    [2] GASOLINE\n";
                cout << "    [3] LPG\n";
                cout << "    Option: ";
                cin >> option;

                switch (option) {
                    case 1:
                        primaryFuelType = FuelType::DIESEL;
                        break;
                    case 2:
                        primaryFuelType = FuelType::GASOLINE;
                        break;
                    case 3:
                        primaryFuelType = FuelType::LPG;
                        break;
                    default:
                        cout << "Please choose a valid option between 1 and 4.\n";
                }

            } while (option < 1 || option > 4);

            secondaryFuelType = FuelType::NONE;
        }

        // Motor power and his capacity
        float power, capacity, power2, capacity2;
        cout << "\n  | Motor Specs:\n";
        cout << "    | Primary Motor Power: ";
        cin >> power;
        cout << "    | Primary Motor Capacity: ";
        cin >> capacity;

        // Second motor specs
        if (newMotorType == MotorType::HYBRID) {
            cout << "    | Secondary Motor Power: ";
            cin >> power2;
            cout << "    | Secondary Motor Capacity: ";
            cin >> capacity2;

            // Check if second motor specs are provided for hybrid vehicles
            if (power2 == 0 && capacity2 == 0) {
                cout << "Error: Secondary motor's power and capacity are required for hybrid vehicles.\n";
                return -1;
            }
        } else {
            power2 = 0;
            capacity2 = 0;
        }

        float price;
        cout << "\n  | Price: ";
        cin >> price;

        do {
            switch (vehicleTypeOption) {
                case 1:
                    newVehicle = VehicleFactory::createVehicle("coupe", newLicensePlateYear, newBrand, primaryFuelType, secondaryFuelType, newMotorType, power, capacity, power2, capacity2, price);
                    break;
                case 2:
                    newVehicle = VehicleFactory::createVehicle("sedan", newLicensePlateYear, newBrand, primaryFuelType, secondaryFuelType, newMotorType, power, capacity, power2, capacity2, price);
                    break;
                case 3: {
                    // Motorcycle Type
                    cout << "\n  | Motorcycle Type:\n";
                    cout << "    [1] Motorcycle with Fairing\n";
                    cout << "    [2] Motorcycle without Fairing\n";
                    cout << "    Option: ";
                    int motorcycleTypeOption;
                    cin >> motorcycleTypeOption;

                    bool hasFairing;
                    switch (motorcycleTypeOption) {
                        case 1:
                            hasFairing = true;
                            break;
                        case 2:
                            hasFairing = false;
                            break;
                        default:
                            cout << "Please choose a valid option 1 or 2.\n";
                            continue; // goes back to the beginning of the loop
                    }

                    newVehicle = VehicleFactory::createVehicle("motorcycle", hasFairing, newLicensePlateYear, newBrand, primaryFuelType, newMotorType, power, capacity, price);
                    break;
                }
                default:
                    cout << "Please choose a number between 1 and 4.\n";
            }
        } while (vehicleTypeOption < 1 || vehicleTypeOption > 4);

        cout << "\n| Select a Stand to add the Vehicle:\n";

        // Check if there is available stands to add the vehicle
        if (vehicleStand.getStandVehicleMap().empty()) {
            cout << "No stands available.\n";

            int createStandOption;
            cout << "[1] Create a new Stand\n";
            cout << "[0] Cancel\n";
            cout << "Option: ";
            cin >> createStandOption;

            if (createStandOption == 1) {
                int createStandResult = createStand(vehicleStand);

                if (createStandResult == 0 ) { // created stand successfully
                    cout << "\n| Select a Stand to add the Vehicle:\n";
                    vehicleStand.displayStands();
                    cout << "    Option: ";
                    string standOption;
                    cin >> standOption;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    // add the vehicle to the VehicleStand
                    result = vehicleStand.addVehicleToStand(newVehicle, vehicleStand.findStandByCode(standOption));
                }
            } else {
                cout << "Returning to the main menu...\n";
                return -1;
            }
        } else {
            // Existing stands are available
            vehicleStand.displayStands();
            cout << "    Option: ";
            string standOption;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> standOption;

            // add the vehicle to the VehicleStand
            result = vehicleStand.addVehicleToStand(newVehicle, vehicleStand.findStandByCode((standOption)));
        }
            switch (result) {
                case 0:
                    vehicleStand.saveStandsDataTxt();
                    cout << "Vehicle created and added to the stand successfully.\n";
                    return 0;
                case -1:
                    do {
                        cout << "Vehicle with the same ID already exists\n";
                        cout << "[1] Try again!\n";
                        cout << "[0] Cancel\n\n";
                        cout << "Option: ";
                        cin >> option;
                        while (cin.get() != '\n');
                    } while (option < 0 || option > 1);
                    break;
                default:
                    break;
            }

        } while (option != 0);

    delete newVehicle;
    return -1;
}

int moveVehicleToAnotherStand(GestStand& vehicleStand) {
    cout << "\t|Move Vehicle to Another Stand\n";

    // displays all the map (stands and vehicles)
    vehicleStand.displayMapStandsVehicles();

    int vehicleID;
    cout << "Enter the ID of the vehicle to move: ";
    cin >> vehicleID;

    string destinationStandCode;
    cout << "Enter the code of the destination stand: ";
    cin >> destinationStandCode;

    // move the vehicle to the destination stand
    vehicleStand.moveVehicle(vehicleStand.findVehicleByID(vehicleID), destinationStandCode);

    cout << "Vehicle moved successfully." << endl;

    return 0;
}

void removeVehicleFromStand(GestStand& vehicleStand) {
    int option = 0;
    int vehicleID;

    vehicleStand.displayMapStandsVehicles();

    do {
        cout << "Enter the ID of the vehicle to remove: ";
        cin >> vehicleID;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (vehicleStand.removeVehicleByID(vehicleID)) {
            case 0:
                cout << "Vehicle removed successfully!" << endl;
                return;
            case -1:
                cout << "[1] Try again!\n";
                cout << "[0] Cancel\n\n";
                cin >> option;
                break;
        }
    } while (option != 0);
}

void editVehicleData(GestStand& vehicleStand) {
    int option = 1, selected, Id, newLicensePlateYear;
    string brand, newBrand;
    Vehicle* vehicle = nullptr;

    do {
        cout << "Vehicle Id: ";
        cin >> Id;

        vehicle = vehicleStand.findVehicleByID(Id);

        if (vehicle == nullptr) {
            do {
                cout << "Vehicle not found!\n\n";
                cout << "[1] Try again\n";
                cout << "[0] Cancel\n\n";
                cout << "Option: ";
                cin >> option;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } while (option < 0 || option > 1);
        } else {
            do {
                cout << "Which field do you want to edit?\n";
                cout << "[1] License Plate Year\n";
                cout << "[2] Brand\n";
                cout << "[0] Cancel\n";
                cout << "Option: ";
                cin >> selected;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                switch (selected) {
                    case 0:
                        return;

                    case 1:
                        cout << "| New License Plate Year: ";
                        cin >> newLicensePlateYear;
                        vehicle->setLicensePlateYear(newLicensePlateYear);
                        vehicleStand.saveStandsDataTxt();
                        cout << "\nLicense Plate Year changed successfully!\n";
                        break;

                    case 2:
                        cout << "| New Brand: ";
                        cin.ignore();
                        getline(cin, newBrand);
                        vehicle->setBrand(newBrand);
                        vehicleStand.saveStandsDataTxt();
                        cout << "\nBrand changed successfully!\n";
                        break;
                    default:
                        cout << "Invalid Option! Try again... \n";
                        break;
                }
                if (selected != 0) {
                    do {
                        cout << "\nDo you want to continue altering data for this vehicle?";
                        cout << "\n[1] Yes";
                        cout << "\n[0] No";
                        cout << "\nOption: ";
                        cin >> option;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } while (option != 0 && option != 1);
                }
            } while (selected != 0 && option != 0);
        }
    } while (option != 0);
}


/* --------------------------------- Client Menu ----------------------------------- */

int clientMenu(User auth, UserList& users, GestStand& stands) {
    int choice;

    do {
        cout << "+--------------------------------------+\n";
        cout << "|             CLIENT MENU              |\n";
        cout << "+--------------------------------------+\n\n";

        cout << "[ 1 ] Buy Vehicle\n";
        cout << "[ 2 ] List Vehicles in Stand\n";
        cout << "[ 3 ] List Stands by City\n";
        cout << "[ 4 ] Edit Own Data\n";
        cout << "[ 5 ] View Purchase History\n";
        cout << "[ 6 ] Load Balance\n";
        cout << "[ 0 ] Exit\n\n";
        cout << "Option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                buyVehicle(stands, users, auth);
                anyKey();
                break;
            case 2:
                listVehiclesInStand(stands);
                anyKey();
                break;
            case 3:
                listStandsByCity(stands);
                anyKey();
                break;
            case 4:
                editClientOwnData(users, auth);
                anyKey();
                break;
            case 5:
                clientPurchaseHistory(auth);
                anyKey();
                break;
            case 6:
                changeBalance(auth);
                anyKey();
                break;
            case 0:
                break;
            default:
                cout << "Invalid option! Try again...\n";
                break;
        }
    } while (choice != 0);

    return 0;
}


void editClientOwnData(UserList& users, User& auth) {
    int option = 1, selected, newNif;
    string newName, newPassword;

    do {
        cout << "Which field do you want to edit?\n";
        cout << "[1] Name\n";
        cout << "[2] Password\n";
        cout << "[3] NIF\n";
        cout << "[0] Cancel\n";
        cout << "Option: ";
        cin >> selected;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (selected) {
            case 0:
                return;

            case 1:
                cout << "| New name: ";
                cin.ignore();
                getline(cin, newName);
                auth.setName(newName);
                UserList::saveUsersListTxt(users);
                cout << "\nName changed successfully!\n";
                break;

            case 2:
                cout << "| New password: ";
                cin >> newPassword;
                auth.setPassword(newPassword);
                UserList::saveUsersListTxt(users);
                cout << "\nPassword changed successfully!\n";
                break;

            case 3:
                cout << "| New NIF: ";
                cin >> newNif;
                auth.setNIF(newNif);
                UserList::saveUsersListTxt(users);
                cout << "\nNIF changed Successfully!\n";
                break;
            default:
                cout << "Invalid Option! Try again. \n";
                break;
        }

        if (selected != 0) {
            do {
                cout << "\nDo you want to continue altering your data?";
                cout << "\n[1] Yes";
                cout << "\n[0] No";
                cout << "\nOption: ";
                cin >> option;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } while (option != 0 && option != 1);
        }
    } while (selected != 0 && option != 0);
}

void listVehiclesInStand(const GestStand& vehicleStand) {
    string standCode;

    // Display all the stands
    cout << "Available Stands:\n";
    vehicleStand.displayStands();

    cout << "Enter the code of the Stand: ";
    cin >> standCode;

    Stand* chosenStand = vehicleStand.findStandByCode(standCode);

    if (chosenStand != nullptr) {
        // Get the list of vehicles in the chosen stand
        VehicleList* vehicleList = vehicleStand.getVehicleListByStand(chosenStand);

        // Display the vehicles
        cout << "\nVehicles in Stand " << standCode << ":\n";
        vehicleList->printVehicleList();
    } else {
        cout << "Stand not found.\n";
    }
}

void listStandsByCity(const GestStand& vehicleStand) {
    string cityName;

    cout << "Enter the city name to list stands: ";
    cin >> cityName;

    cout << "\nStands in " << cityName << ":\n";

    // Iterate through all stands
    for (const auto& standKeyValue : vehicleStand.getStandVehicleMap()) {
        const Stand* stand = standKeyValue.first;

        // Check if the stand's city name matches the specified city
        if (stand->getCityName() == cityName) {
            cout << "Code: " << stand->toString() << ", City: " << stand->getCityName() << ", Number: " << stand->getNumber() << endl;
        }
    }
}

void buyVehicle(GestStand& vehicleStand, UserList& users, User& auth) {
    if (vehicleStand.getStandVehicleMap().empty()) {
        cout << "There is no stands available.\n";
        return;
    }

    // Display user's balance
    cout << "Current Balance: $" << auth.getBalance() << "\n\n";

    // Display available stands and vehicles
    vehicleStand.displayStands();

    // Input for vehicle code
    cout << "Enter the code of the stand you want to visit: ";
    string standCode;
    cin >> standCode;

    // find the stand based on the provided code
    Stand* stand = vehicleStand.findStandByCode(standCode);

    if (stand != nullptr) {
        // get the list of vehicles for the selected stand
        VehicleList* vehicleList = vehicleStand.getVehicleListByStand(stand);

        if (vehicleList != nullptr) {
            // Show available vehicle options
            cout << "Available vehicles at stand " << stand->toString() << ":\n";
            vehicleList->printVehicleList();

            // Ask the user to choose a vehicle
            cout << "Choose the ID of the vehicle you want to buy: ";
            int vehicleID;
            cin >> vehicleID;

            // Find the vehicle in the list
            Vehicle* selectedVehicle = vehicleList->findVehicleByID(vehicleID);

            // check if the vehicle is found
            if (selectedVehicle != nullptr) {
                // Check if the user has enough balance
                if (auth.getBalance() < selectedVehicle->getPrice()) {
                    cout << "Insufficient balance to buy this vehicle!\n";
                    return;
                }

                // user balance updated
                auth.setBalance(auth.getBalance() - selectedVehicle->getPrice());

                // Add the purchased vehicle to the user purchase history
                auth.addToPurchaseHistory(selectedVehicle);

                // Show the success of the purchase
                cout << "Vehicle purchased successfully!\n\n";
                cout << "New Balance: $" << auth.getBalance() << "\n";

                vehicleList->removeVehicleByID(vehicleID); // remove the vehicle

                // Save the changes
                UserList::saveUsersListTxt(users);
                vehicleStand.saveStandsDataTxt();

                return;
            } else {
                cout << "Vehicle not found.\n";
            }
        } else {
            cout << "This stand has no available vehicles.\n";
        }
    }
}

void clientPurchaseHistory(User& auth) {
    const vector<Vehicle*>& purchaseHistory = auth.getPurchaseHistory(); // Get purchase history

    if (purchaseHistory.empty()) {
        cout << "You haven't made any purchase.\n";
    } else {
        auth.displayPurchaseHistory(); // Display purchase history

    }
}

void changeBalance(User& auth) {
    float amount;

    cout << "Enter the amount you want to load: ";
    cin >> amount;

    // Check if the entered value is valid
    if (amount > 0) {
        // Add the amount to the existing balance
        auth.setBalance(auth.getBalance() + amount);
        cout << "Load successful. New balance: " << auth.getBalance() << endl;
    }
    else {
        cout << "Invalid amount." << endl;
    }
}


