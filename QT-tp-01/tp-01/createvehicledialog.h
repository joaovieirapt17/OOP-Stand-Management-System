#ifndef CREATEVEHICLEDIALOG_H
#define CREATEVEHICLEDIALOG_H

#include <QDialog>
#include "stand.h"
#include "vehicle.h"

namespace Ui {
class CreateVehicleDialog;
}

class CreateVehicleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateVehicleDialog(GestStand& vehicleStand, QWidget* parent = nullptr);
    ~CreateVehicleDialog();

private slots:
    void on_addButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::CreateVehicleDialog *ui;
    GestStand& vehicleStand;

    // Helper function to create a vehicle based on user input
    Vehicle* createVehicleFromInput();
};

#endif // CREATEVEHICLEDIALOG_H
