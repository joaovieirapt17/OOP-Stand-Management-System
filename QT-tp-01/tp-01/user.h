#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>
#include <QList>

#include "utils.h"

enum class Role {
    client = 0,
    manager = 1,
    admin = 2
};

class User : public QObject {
    Q_OBJECT

private:
    QString username;
    QString password;
    QString name;
    int NIF;
    float balance;
    Role role;
    QList<Vehicle*> purchaseHistory;

public:
    // Default Constructor
    User(QObject* parent = nullptr);

    // Constructor
    User(const QString& username, const QString& password, const QString& name, int NIF, float balance, Role role, QObject* parent = nullptr);

    // Destructor
    ~User();

    // Getters
    [[nodiscard]] QString getUsername() const;
    [[nodiscard]] QString getPassword() const;
    [[nodiscard]] QString getName() const;
    [[nodiscard]] int getNIF() const;
    [[nodiscard]] float getBalance() const;
    [[nodiscard]] Role getRole() const;
    const QList<Vehicle*>& getPurchaseHistory() const;

    // Setters
    void setUsername(const QString& newUsername);
    void setPassword(const QString& newPassword);
    void setName(const QString& newName);
    void setRole(Role newRole);
    void setNIF(int newNIF);
    void setBalance(float newBalance);

    void addToPurchaseHistory(Vehicle* vehicle);

    Q_INVOKABLE void displayPurchaseHistory() const;


signals:
    void purchaseHistoryChanged();

};



/* ----------------------------------- UserList CLASS ------------------------------------------*/

class UserList : public QObject {
    Q_OBJECT

private:
    QList<User*> userList;
    User* loggedInUser = nullptr;

public:
    UserList(QObject* parent = nullptr);

    User* findUserByUsername(const QString& username);
    int addUser(User* user);
    [[nodiscard]] bool isEmpty() const;
    void printUserList() const;
    void clear();
    [[nodiscard]] int length() const;
    int removeUserByUsername(const QString& username);
    User* login(const QString& username, const QString& password);

    static int saveUsersListTxt(UserList& userList);
    static int loadUsersTxtData(UserList& userList);

    const QList<User*>& getUserList() const;

    User* getLoggedInUser() const;

signals:
    void userListChanged();

};

#endif // USER_H
