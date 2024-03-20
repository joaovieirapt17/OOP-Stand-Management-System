/********************************************************************************
** Form generated from reading UI file 'createstanddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATESTANDDIALOG_H
#define UI_CREATESTANDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CreateStandDialog
{
public:
    QLineEdit *cityName_lineEdit;
    QLabel *cityName_label;
    QLabel *manageStands_label;
    QLineEdit *standNumber_lineEdit;
    QLabel *standNumber_label;
    QPushButton *submitButton;

    void setupUi(QDialog *CreateStandDialog)
    {
        if (CreateStandDialog->objectName().isEmpty())
            CreateStandDialog->setObjectName("CreateStandDialog");
        CreateStandDialog->resize(450, 500);
        cityName_lineEdit = new QLineEdit(CreateStandDialog);
        cityName_lineEdit->setObjectName("cityName_lineEdit");
        cityName_lineEdit->setGeometry(QRect(90, 170, 251, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(14);
        cityName_lineEdit->setFont(font);
        cityName_lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    width: 150px;\n"
"    height: 30px;\n"
"    border-radius: 10px;\n"
"    list-style: none;\n"
"    border: 1px solid grey;\n"
"	padding-left: 12px;\n"
"	padding-right: 12px;\n"
"}"));
        cityName_label = new QLabel(CreateStandDialog);
        cityName_label->setObjectName("cityName_label");
        cityName_label->setEnabled(true);
        cityName_label->setGeometry(QRect(90, 140, 91, 23));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cityName_label->sizePolicy().hasHeightForWidth());
        cityName_label->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(16);
        cityName_label->setFont(font1);
        cityName_label->setFrameShape(QFrame::NoFrame);
        manageStands_label = new QLabel(CreateStandDialog);
        manageStands_label->setObjectName("manageStands_label");
        manageStands_label->setGeometry(QRect(10, 10, 111, 41));
        manageStands_label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 16px;\n"
"    font-weight: bold; \n"
"	background-color: #222;\n"
"    color: #fff;\n"
"    border-radius: 16px;    \n"
"    padding-right: 8px;\n"
"	padding-left: 8px;\n"
"}"));
        standNumber_lineEdit = new QLineEdit(CreateStandDialog);
        standNumber_lineEdit->setObjectName("standNumber_lineEdit");
        standNumber_lineEdit->setGeometry(QRect(90, 270, 251, 41));
        standNumber_lineEdit->setFont(font);
        standNumber_lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border-radius: 10px;\n"
"    list-style: none;\n"
"    border: 1px solid grey;\n"
"	padding-left: 12px;\n"
"	padding-right: 12px;\n"
"}"));
        standNumber_label = new QLabel(CreateStandDialog);
        standNumber_label->setObjectName("standNumber_label");
        standNumber_label->setEnabled(true);
        standNumber_label->setGeometry(QRect(90, 240, 131, 23));
        sizePolicy.setHeightForWidth(standNumber_label->sizePolicy().hasHeightForWidth());
        standNumber_label->setSizePolicy(sizePolicy);
        standNumber_label->setFont(font1);
        standNumber_label->setFrameShape(QFrame::NoFrame);
        submitButton = new QPushButton(CreateStandDialog);
        submitButton->setObjectName("submitButton");
        submitButton->setGeometry(QRect(150, 360, 111, 41));
        QFont font2;
        font2.setPointSize(16);
        submitButton->setFont(font2);
        submitButton->setCursor(QCursor(Qt::PointingHandCursor));
        submitButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    width: 100px;\n"
"    height: 35px;\n"
"    background: #98c9a3; \n"
"    color: #ffffff; \n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background: #7fba8f;\n"
"	border: 1px solid black;\n"
"}"));

        retranslateUi(CreateStandDialog);

        QMetaObject::connectSlotsByName(CreateStandDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateStandDialog)
    {
        CreateStandDialog->setWindowTitle(QCoreApplication::translate("CreateStandDialog", "Dialog", nullptr));
        cityName_label->setText(QCoreApplication::translate("CreateStandDialog", "<html><head/><body><p><span style=\" font-size:14pt;\">City Name</span></p></body></html>", nullptr));
        manageStands_label->setText(QCoreApplication::translate("CreateStandDialog", "New Stand", nullptr));
        standNumber_label->setText(QCoreApplication::translate("CreateStandDialog", "<html><head/><body><p><span style=\" font-size:14pt;\">Number</span></p></body></html>", nullptr));
        submitButton->setText(QCoreApplication::translate("CreateStandDialog", "Submit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateStandDialog: public Ui_CreateStandDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATESTANDDIALOG_H
