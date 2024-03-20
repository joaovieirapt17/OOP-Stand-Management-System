#ifndef ADDVEHICLEDIALOG_H
#define ADDVEHICLEDIALOG_H

#include <QDialog>

namespace Ui {
class AddVehicleDialog;
}

class AddVehicleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddVehicleDialog(QWidget *parent = nullptr);
    ~AddVehicleDialog();

private:
    Ui::AddVehicleDialog *ui;
};

#endif // ADDVEHICLEDIALOG_H
