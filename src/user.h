#ifndef USER_H
#define USER_H

#include <string>
#include <list>
#include <vector>

#include "utils.h"

enum class Role {
    client = 0,
    manager = 1,
    admin = 2
};

class User {
private:
    std::string username;
    std::string password;
    std::string name;
    int NIF;
    float balance;
    Role role; // 0 - client, 1 - manager
    std::vector<Vehicle*> purchaseHistory; // Add a vector to store purchased vehicles

public:
    // Default Constructor
    User();

    // Constructor
    User(const std::string& username, const std::string& password, const std::string& name, int NIF, float balance, Role role);

    // Destructor
    ~User();

    // Getters
        // [[nodiscard]] -> Generate a warning if the return value is ignored.
    [[nodiscard]] std::string getUsername() const;
    [[nodiscard]] std::string getPassword() const;
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getNIF() const;
    [[nodiscard]] float getBalance() const;
    [[nodiscard]] Role getRole() const;
    const std::vector<Vehicle*>& getPurchaseHistory() const;


    // Setters
    void setUsername(const std::string& newUsername);
    void setPassword(const std::string& newPassword);
    void setName(const std::string& newName);
    void setRole(Role newRole);
    void setNIF(int newNIF);
    void setBalance(float newBalance);

    void addToPurchaseHistory(Vehicle *vehicle);

    void displayPurchaseHistory() const;
};



/* ----------------------------------- UserList CLASS ------------------------------------------*/

class UserList {
private:
    std::list<User*> userList;

public:
    /**
     * @brief Find a user by their username in the linked list.
     * @param username The username to search for.
     * @return A pointer to the found user or nullptr if not found.
     */
    User* findUserByUsername(const std::string& username);

    /**
     * @brief Add a new user to the linked list.
     * @param user The User object to be added to the linked list.
     * @return 0 if the addition is successful.
     * @return -1 if a user with the same username already exists in the list.
     */
    int addUser(User* user);

    /**
    * @brief Check if the linked list is empty.
    */
    [[nodiscard]] bool isEmpty() const;

    /**
    * @brief Print the contents of the linked list.
    */
    void printUserList() const;

    /**
   * @brief Clear the linked list.
   */
    void clear();

    /**
     * @brief Get the number of users in the list.
     * @return The number of users in the list.
     */
    [[nodiscard]] int length() const;

    /**
     * @brief Removes a user from the list given an username.
     * @param username The username of the user to be removed.
     * @return  0 if the user is successfully removed.
     * @return -1 if the user with the specified username is not found.
     */
    int removeUserByUsername(const std::string& username);

    /**
     * @brief Attempt to log in a user by checking the provided username and password.
     * @param username The username to check.
     * @param password The password to check.
     * @return User* A pointer to the user if login is successful, nullptr otherwise.
     */
    User* login(const std::string& username, const std::string& password);

    /**
     * @brief Save user data to a txt file.
     * @param userList The UserList containing the user data to be saved.
     * @return 0 if the operation is successful.
     * @return -3 if there's an error opening the file.
     */
    static int saveUsersListTxt(UserList& userList);

    /**
     * @brief Load user data from a text file and add users to the provided UserList.
     * @param userList The UserList to which users will be added.
     * @return 0 if the operation is successful.
     * @return -3 if there's an error opening the file.
     */
    static int loadUsersTxtData(UserList& userList);

    const std::list<User*>& getUserList() const;
};

#endif //USER_H
