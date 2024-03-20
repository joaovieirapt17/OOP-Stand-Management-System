/********************************************************************************
** Form generated from reading UI file 'createvehicledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEVEHICLEDIALOG_H
#define UI_CREATEVEHICLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_CreateVehicleDialog
{
public:

    void setupUi(QDialog *CreateVehicleDialog)
    {
        if (CreateVehicleDialog->objectName().isEmpty())
            CreateVehicleDialog->setObjectName("CreateVehicleDialog");
        CreateVehicleDialog->resize(400, 300);

        retranslateUi(CreateVehicleDialog);

        QMetaObject::connectSlotsByName(CreateVehicleDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateVehicleDialog)
    {
        CreateVehicleDialog->setWindowTitle(QCoreApplication::translate("CreateVehicleDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateVehicleDialog: public Ui_CreateVehicleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEVEHICLEDIALOG_H
