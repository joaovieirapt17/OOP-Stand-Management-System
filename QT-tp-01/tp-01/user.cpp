#include "user.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>

// DEFAULT CONSTRUCTOR
User::User(QObject* parent) : QObject(parent), role(Role::client) {
}

// USER CONSTRUCTOR
User::User(const QString& username, const QString& password, const QString& name, int NIF, float balance, Role role, QObject* parent)
    : QObject(parent), username(username), password(password), name(name), NIF(NIF), balance(balance), role(role) {
}

// USER DESTRUCTOR
User::~User() = default;

// GETTERS
QString User::getUsername() const {
    return username;
}

QString User::getPassword() const {
    return password;
}

QString User::getName() const {
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

const QList<Vehicle*>& User::getPurchaseHistory() const {
    return purchaseHistory;
}

// SETTERS
void User::setUsername(const QString& newUsername) {
    username = newUsername;
}

void User::setPassword(const QString& newPassword) {
    password = newPassword;
}

void User::setName(const QString& newName) {
    name = newName;
}

void User::setNIF(int newNIF) {
    NIF = newNIF;
}

void User::setBalance(float newBalance) {
    balance = newBalance;
}

void User::addToPurchaseHistory(Vehicle* vehicle) {
    purchaseHistory.append(vehicle);
    emit purchaseHistoryChanged();
}

void User::displayPurchaseHistory() const {
    qDebug() << "Purchase History:";
    for (const auto& vehicle : purchaseHistory) {
        qDebug() << "Vehicle ID:" << vehicle->getVehicleID() << ", Brand:" << vehicle->getBrand() << ", Price: €" << vehicle->getPrice();
    }
}

/* ------------------------------------------- UserList Methods -----------------------------------------------*/

UserList::UserList(QObject* parent) : QObject(parent) {
}

User* UserList::findUserByUsername(const QString& username) {
    for (auto& user : userList) {
        if (user->getUsername() == username) {
            return user; // Returns the pointer to the founded user
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
    userList.append(user);
    emit userListChanged();

    return 0; // User added successfully
}

int UserList::removeUserByUsername(const QString& username) {
    for (auto itr = userList.constBegin(); itr != userList.constEnd(); ++itr) {
        if ((*itr)->getUsername() == username) {
            userList.erase(itr);
            emit userListChanged();
            return 0; // User removed successfully
        }
    }

    return -1; // User not found
}

void UserList::printUserList() const {
    // Check for an empty list
    if (userList.isEmpty()) {
        qDebug() << "User List is empty";
        return;
    }

    // Iterates the list
    for (const auto& user : userList) {
        qDebug() << "Username:" << user->getUsername() << "Password:" << user->getPassword() << "Name:" << user->getName();
    }
}

bool UserList::isEmpty() const {
    return userList.isEmpty();
}

void UserList::clear() {
    userList.clear();
    emit userListChanged();
}

int UserList::length() const {
    return userList.size();
}

const QList<User*>& UserList::getUserList() const {
    return userList;
}

User* UserList::getLoggedInUser() const {
    return loggedInUser;
}

/* ------------------------------------------- Login + Load/Save Data ------------------------------------------------*/

User* UserList::login(const QString& username, const QString& password) {
    // Find the user in the list based on the provided username
    User* user = findUserByUsername(username);

    if (user == nullptr) {
        return nullptr; // User not found
    }

    if (user->getPassword() == password) {
        loggedInUser = user;
        return user; // Login successful
    }

    return nullptr; // Incorrect password
}

int UserList::saveUsersListTxt(UserList& userListToSave) {
    QFile file("users_data.txt");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return -3; // File not opened successfully
    }

    QTextStream out(&file);

    // Iterate through the list and write each user´s data to the 'txt' file
    for (const auto& user : userListToSave.userList) {
        // Write user data to the text file
        out << "----- USER -----\n";
        out << "Username: " << user->getUsername() << "\n";
        out << "Password: " << user->getPassword() << "\n";
        out << "Name: " << user->getName() << "\n";
        out << "NIF: " << user->getNIF() << "\n";
        out << "Balance: " << user->getBalance() << "\n";
        out << "Role: " << roleToString(user->getRole()) << "\n";
        out << "\n";
    }

    file.close();

    return 0; // Success
}

int UserList::loadUsersTxtData(UserList& userListToLoad) {
    QFile file("users_data.txt");

    // Check if the file is successfully opened
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error opening the text file.";
        return -3;
    }

    QTextStream in(&file);

    // Read the text data from the file and add each user to the list
    while (!in.atEnd()) {
        QString line = in.readLine();

        // Check if the line is the beginning of a new user
        if (line == "----- USER -----") {
            // Read the username
            QString usernameLine = in.readLine();
            QString username = usernameLine.mid(usernameLine.indexOf(':') + 2);

            // Read the password
            QString passwordLine = in.readLine();
            QString password = passwordLine.mid(passwordLine.indexOf(':') + 2);

            // Read the name
            QString nameLine = in.readLine();
            QString name = nameLine.mid(nameLine.indexOf(':') + 2);

            // Read the NIF
            QString nifLine = in.readLine();
            int NIF = nifLine.mid(nifLine.indexOf(':') + 2).toInt();

            // Read the balance
            QString balanceLine = in.readLine();
            float balance = balanceLine.mid(balanceLine.indexOf(':') + 2).toFloat();

            // Read the role
            QString roleLine = in.readLine();
            QString roleString = roleLine.mid(roleLine.indexOf(':') + 2);
            Role role = stringToRole(roleString);

            // Add the user to the list
            userListToLoad.addUser(new User(username, password, name, NIF, balance, role));
        }
    }

    file.close();

    return 0; // Success
}

