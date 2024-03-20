#include "user.h"

#include <iostream>
#include <fstream>

using namespace std;

// DEFAULT CONSTRUCTOR
User::User() {
    role = Role::client; // Default role = client.
}

// USER CONSTRUCTOR
User::User(const string& username, const string& password, const string& name, int NIF, float balance, Role role) {
    this->username = username;
    this->password = password;
    this->name = name;
    this->NIF = NIF;
    this->balance = balance;
    this->role = role;
}

// USER DESTRUCTOR
User::~User() = default;

// GETTERS
string User::getUsername() const {
    return username;
}

string User::getPassword() const {
    return password;
}

string User::getName() const {
    return name;
}

int User::getNIF() const {
    return NIF;
}

float User::getBalance() const {
    return balance;
}

Role User::getRole() const {
    return role;
}

const vector<Vehicle*>& User::getPurchaseHistory() const {
    return purchaseHistory;
}

// SETTERS
void User::setUsername(const string& newUsername) {
    username = newUsername;
}

void User::setPassword(const string& newPassword) {
    password = newPassword;
}

void User::setName(const string& newName) {
    name = newName;
}

void User::setNIF(int newNIF) {
    NIF = newNIF;
}

void User::setBalance(float newBalance) {
    balance = newBalance;
}

/* ------------------------------------------- UserList Methods -----------------------------------------------*/

// Method to find a user by Username
User* UserList::findUserByUsername(const string& username) {
    for (auto & itr : userList) {
        if (itr->getUsername() == username) {
            return itr; // Returns the pointer to the founded user
        }
    }

    return nullptr; // User not found
}

int UserList::addUser(User* user) {
    // Check if the user with the same username already exists
    User* result = findUserByUsername(user->getUsername());

    if (result != nullptr) {
        return -1; // User with the same username already exists
    }

    // Add the new user to the list
    userList.push_back(user);

    return 0; // User added successfully
}

int UserList::removeUserByUsername(const string& username) {
    for (auto itr = userList.begin(); itr != userList.end(); itr++) {
        if ((*itr)->getUsername() == username) {
            userList.erase(itr);
            return 0; // User removed successfully
        }
    }

    return -1; // User not found
}

void UserList::printUserList() const {
    // Check for an empty list
    if (userList.empty()) {
        cout << "User List is empty" << endl;
        return;
    }

    // Iterates the list
    for (const auto& user : userList) {
        cout << "Username: " << user->getUsername() << " Password: " << user->getPassword() << " Name: " << user->getName() << endl;
    }
}

bool UserList::isEmpty() const {
    return userList.empty();
}

void UserList::clear() {
    userList.clear();
}

int UserList::length() const {
    return static_cast<int>(userList.size());
}

const list<User*>& UserList::getUserList() const {
    return userList;
}

/* ------------------------------------------- Login + Load/Save Data ------------------------------------------------*/

User* UserList::login(const string& username, const string& password) {
    // Find the user in the list based on the provided username
    User* user = findUserByUsername(username);

    if (user == nullptr) {
        return nullptr; // User not found
    }

    if (user->getPassword() == password) {
        return user; // Login successful
    }

    return nullptr; // Incorrect password
}

int UserList::saveUsersListTxt(UserList& userListToSave) {
    ofstream file("users_data.txt");

    if (!file.is_open()) {
        return -3; // File not opened successfully
    }

    // Iterate through the list and write each user´s data to the 'txt' file
    for (const auto& user : userListToSave.userList) {
        // Write user data to the text file
        file << "----- USER -----\n";
        file << "Username: " << user->getUsername() << "\n";
        file << "Password: " << user->getPassword() << "\n";
        file << "Name: " << user->getName() << "\n";
        file << "NIF: " << user->getNIF() << "\n";
        file << "Balance: " << user->getBalance() << "\n";
        file << "Role: " << roleToString(user->getRole()) << "\n";
        file << "\n" ;
    }

    file.close();

    return 0; // Success
}

int UserList::loadUsersTxtData(UserList& userListToLoad) {
    ifstream file("users_data.txt");

    // Check if the file is successfully opened
    if (!file.is_open()) {
        cerr << "Error opening the text file." << endl;
        return -3;
    }

    // Read the text data from the file and add each user to the list
    while (true) {
        string line;
        getline(file, line);

        if (file.eof()) {
            break; // End of file
        }

        // Check if the line is the beginning of a new user
        if (line == "----- USER -----") {
            // Read the username
            getline(file, line);
            string username = line.substr(line.find(':') + 2);

            // Read the password
            getline(file, line);
            string password = line.substr(line.find(':') + 2);

            // Read the name
            getline(file, line);
            string name = line.substr(line.find(':') + 2);

            // Read the NIF
            getline(file, line);
            int NIF = stoi(line.substr(line.find(':') + 2)); // stoi - convert string to integer

            // Read the balance
            getline(file, line);
            float balance = stof(line.substr(line.find(':') + 2)); // stof - convert string to float

            // Read the role
            getline(file, line);
            string roleString = line.substr(line.find(':') + 2);
            Role role = stringToRole(roleString);

            // Add the user to the list
            userListToLoad.addUser(new User(username, password, name, NIF, balance, role));
        }
    }

    file.close();

    return 0; // Success
}

void User::addToPurchaseHistory(Vehicle* vehicle) {
    purchaseHistory.push_back(vehicle);
}

void User::displayPurchaseHistory() const {
    cout << "Purchase History:\n";
    for (const auto& vehicle : purchaseHistory) {
        cout << "Vehicle ID: " << vehicle->getVehicleID() << ", Brand: " << vehicle->getBrand() << ", Price: €" << vehicle->getPrice() << "\n";
    }
}
