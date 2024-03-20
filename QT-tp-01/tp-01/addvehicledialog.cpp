#include "addvehicledialog.h"
#include "ui_addvehicledialog.h"

AddVehicleDialog::AddVehicleDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddVehicleDialog)
{
    ui->setupUi(this);
}

AddVehicleDialog::~AddVehicleDialog()
{
    delete ui;
}
