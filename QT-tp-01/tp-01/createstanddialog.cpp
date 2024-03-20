#include "createstanddialog.h"
#include "ui_createstanddialog.h"
#include <QMessageBox>

CreateStandDialog::CreateStandDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreateStandDialog)
{
    ui->setupUi(this);

    // Connect the submit clicked signal to the
    connect(ui->submitButton, &QPushButton::clicked, this, &CreateStandDialog::on_submitButton_clicked);
}

CreateStandDialog::~CreateStandDialog()
{
    delete ui;
}

void CreateStandDialog::on_submitButton_clicked() {
    QString standName = ui->cityName_lineEdit->text();
    int standNumber = ui->standNumber_lineEdit->text().toInt();

    if (standName.isEmpty() || standNumber <= 0) {
        QMessageBox::critical(this, "Error", "Stand name or number is invalid.");
        return;
    }

    emit standSubmitted(standName, standNumber);

    accept();
}

