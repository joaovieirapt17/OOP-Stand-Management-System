#include <iostream>
#include "menu.h"

using namespace std;


int loadData(UserList& userList, GestStand& stands) {
    int loadUsersResult = UserList::loadUsersTxtData(userList);

    // Check if loading failed
    if (loadUsersResult != 0) {
        User adminUser("admin", "admin", "admin",0, 0, Role::admin); // admin user
        userList.addUser(&adminUser);
        UserList::saveUsersListTxt(userList);
        return -1;
    }

    // Load stands and vehicles from file
    int loadStandsResult = stands.loadStandsDataTxt();
    // stands.loadCsvData("stands.csv");
    if (loadStandsResult != 0) {
        cerr << "Error loading stands and vehicles data. Probably the file doesn't exist." << endl;
        return -2;
    }

    return 0; // Success
}


int main() {
    int result = 0;

    UserList users;
    GestStand* stands = new VehicleStand();

    // Load data
    loadData(users, *stands);

    // Pointer to store the authenticated user
    User* auth = nullptr;

    do {
        if (initialMenu(users, &auth) == -1) return 0;

        if (auth->getRole() == Role::admin) {
            result = adminMenu(*auth, users, *stands);
        } else if (auth->getRole() == Role::manager) {
            result = managerMenu(*auth, users, *stands);
        } else if (auth->getRole() == Role::client) {
            result = clientMenu(*auth, users, *stands);
        }

    } while (result == -4);

    printf("Exiting...");

    return 0;
}
