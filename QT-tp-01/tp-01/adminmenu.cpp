#include "adminmenu.h"
#include "ui_adminmenu.h"
#include "managestandsmenu.h"

AdminMenu::AdminMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminMenu)
{
    ui->setupUi(this);

    // Connect button signals to slots
    connect(ui->manageManagersButton, &QPushButton::clicked, this, &AdminMenu::onManageManagersClicked);
    connect(ui->manageClientsButton, &QPushButton::clicked, this, &AdminMenu::onManageClientsClicked);
    connect(ui->manageStandsButton, &QPushButton::clicked, this, &AdminMenu::onManageStandsClicked);
}

AdminMenu::~AdminMenu()
{
    delete ui;
}

// Slots for button clicks
void AdminMenu::onManageManagersClicked()
{
}

void AdminMenu::onManageClientsClicked()
{
}

void AdminMenu::onManageStandsClicked()
{
    // Create the ManageStandsMenu
    ManageStandsMenu *standsMenu = new ManageStandsMenu(this);
    // Hide the current window
    hide();

    // show the ManageStandsMenu
    standsMenu->exec();

    // delete the ManageStandsMenu when it's closed
    standsMenu->deleteLater();
}
