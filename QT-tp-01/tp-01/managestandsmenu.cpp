#include "managestandsmenu.h"
#include "ui_managestandsmenu.h"
#include "createstanddialog.h"

#include <QLineEdit>
#include <QSpinBox>

ManageStandsMenu::ManageStandsMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ManageStandsMenu)
{
    ui->setupUi(this);
}

ManageStandsMenu::~ManageStandsMenu()
{
    delete ui;
}

void ManageStandsMenu::on_createStandButton_clicked() {
    CreateStandDialog* createStandDialog = new CreateStandDialog(this);

    // Connect the dialog signal to the StandsManager slot
    connect(createStandDialog, &CreateStandDialog::standSubmitted, &standsManager, &StandsManager::createStand);

    // Show the CreateStandDialog when the button is clicked
    createStandDialog->show();

}
