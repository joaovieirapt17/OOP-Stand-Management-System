#include "login.h"
#include "ui_login.h"
#include "adminmenu.h"

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);

    // Connect the loginButton's clicked signal to the on_loginButton_clicked slot
    connect(ui->LoginBtn, &QPushButton::clicked, this, &login::onLoginBtnClicked);
    connect(ui->password_lineEdit, &QLineEdit::returnPressed, this, &login::onLoginBtnClicked); // work with "enter" key

    setTabOrder(ui->userName_lineEdit, ui->password_lineEdit);

    userList.loadUsersTxtData(userList); // load users
}

login::~login()
{
    delete ui;
}

void login::onLoginBtnClicked()
{
    QString username = ui->userName_lineEdit->text();
    QString password = ui->password_lineEdit->text();

    User* loggedInUser = userList.login(username, password);

    if (loggedInUser != nullptr) {
        Role userRole = loggedInUser->getRole();

        if (userRole == Role::admin) {
            this->close();

            AdminMenu* adminMenu = new AdminMenu();
            adminMenu->show();
        } else {
            ui->logInSuccessful->setText("Log In Successful! Welcome, " + loggedInUser->getUsername());
        }
    } else {
        qDebug() << "Login failed. Incorrect username or password.";

        ui->logInSuccessful->setText("Login failed. Incorrect username or password.");

    }
}
