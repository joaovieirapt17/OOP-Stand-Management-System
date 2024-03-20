#include "createvehicledialog.h"
#include "ui_createvehicledialog.h"
#include <QMessageBox>

CreateVehicleDialog::CreateVehicleDialog(GestStand& vehicleStand, QWidget* parent)
    : QDialog(parent), ui(new Ui::CreateVehicleDialog), vehicleStand(vehicleStand) {
    ui->setupUi(this);

    // Connect buttons to slots
    connect(ui->addButton, &QPushButton::clicked, this, &CreateVehicleDialog::on_addButton_clicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &CreateVehicleDialog::on_cancelButton_clicked);
}

CreateVehicleDialog::~CreateVehicleDialog() {
    delete ui;
}

void CreateVehicleDialog::on_addButton_clicked() {
    Vehicle* newVehicle = createVehicleFromInput();

    // Check if the vehicle creation was successful
    if (newVehicle != nullptr) {
        // Display stands and ask the user to select a stand
        // For simplicity, let's assume you have a function displayStands() in GestStand
        vehicleStand.displayStands();

        bool ok;
        QString standOption = QInputDialog::getText(this, "Select a Stand", "Enter Stand Code:", QLineEdit::Normal, "", &ok);

        if (ok) {
            int result = vehicleStand.addVehicleToStand(newVehicle, vehicleStand.findStandByCode(standOption.toStdString()));

            if (result == 0) {
                // Save stands list and show a success message
                vehicleStand.saveStandsListTxt();
                QMessageBox::information(this, "Success", "Vehicle created and added to the stand successfully.");
            } else if (result == -1) {
                // Show an error message for duplicate ID
                QMessageBox::critical(this, "Error", "Vehicle with the same ID already exists.");
            } else {
                // Handle other errors as needed
                QMessageBox::critical(this, "Error", "An unexpected error occurred.");
            }
        } else {
            // User canceled stand selection
            QMessageBox::information(this, "Canceled", "Vehicle creation canceled.");
        }

        // Clean up
        delete newVehicle;
    }
}

void CreateVehicleDialog::on_cancelButton_clicked() {
    // Close the dialog without creating a vehicle
    close();
}

Vehicle* CreateVehicleDialog::createVehicleFromInput() {
    // Implement this function to retrieve user input from the UI elements
    // and create a new vehicle using your existing logic.
    // You'll need to replace cin/cout with appropriate Qt widgets.
    // Return nullptr in case of failure.
    // For simplicity, you can use QMessageBox to display error messages.
    // You can use QInputDialog for simple text input from the user.
    // Adapt this based on the UI elements you use in your dialog.

    // Example:
    int newLicensePlateYear = QInputDialog::getInt(this, "Enter License Plate Year", "License Plate Year:");

    // Repeat this process for other input parameters...

    // Use the retrieved parameters to create a new vehicle
    return VehicleFactory::createVehicle(/* pass the parameters here */);
}
