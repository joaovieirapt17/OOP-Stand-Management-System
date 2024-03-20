#include "login.h"
#include "user.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    UserList userList;

    // Create a new user and add it to the list
    User* newUser = new User("testuser", "password123", "Test User", 123456789, 100.0, Role::admin);
    userList.addUser(newUser);

    User* newUser2 = new User("admin", "admin", "Test User", 123456789, 100.0, Role::admin);
    userList.addUser(newUser2);

    userList.saveUsersListTxt(userList); // Save the UserList to a file

    // Show the login window
    login w;
    w.show();

    return a.exec();
}
