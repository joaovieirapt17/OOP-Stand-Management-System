/********************************************************************************
** Form generated from reading UI file 'adminmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMENU_H
#define UI_ADMINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AdminMenu
{
public:
    QLabel *admin_label;
    QPushButton *manageManagersButton;
    QPushButton *manageClientsButton;
    QPushButton *manageStandsButton;

    void setupUi(QDialog *AdminMenu)
    {
        if (AdminMenu->objectName().isEmpty())
            AdminMenu->setObjectName("AdminMenu");
        AdminMenu->resize(800, 600);
        admin_label = new QLabel(AdminMenu);
        admin_label->setObjectName("admin_label");
        admin_label->setGeometry(QRect(20, 20, 141, 41));
        admin_label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 18px;\n"
"    font-weight: bold; \n"
"	background-color: #222;\n"
"    color: #fff;\n"
"    border-radius: 20px;    \n"
"    padding-right: 8px;\n"
"	padding-left: 8px;\n"
"}"));
        manageManagersButton = new QPushButton(AdminMenu);
        manageManagersButton->setObjectName("manageManagersButton");
        manageManagersButton->setGeometry(QRect(40, 230, 211, 141));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setBold(true);
        manageManagersButton->setFont(font);
        manageManagersButton->setCursor(QCursor(Qt::PointingHandCursor));
        manageManagersButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 20px;\n"
"    font-weight: bold; \n"
"	background-color: #1e6091;\n"
"    color: white;\n"
"    border-radius: 20px;    \n"
"    padding: 8px; \n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: #1e6091;\n"
"border: 2px solid black;\n"
"}"));
        manageClientsButton = new QPushButton(AdminMenu);
        manageClientsButton->setObjectName("manageClientsButton");
        manageClientsButton->setGeometry(QRect(270, 230, 231, 141));
        manageClientsButton->setFont(font);
        manageClientsButton->setCursor(QCursor(Qt::PointingHandCursor));
        manageClientsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 20px;\n"
"    font-weight: bold; \n"
"	background-color: #606c38;\n"
"    color: white;\n"
"    border: 2px solid white;\n"
"    border-radius: 20px;    \n"
"    padding: 8px; \n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: #606c38;\n"
"border: 2px solid black;\n"
"}"));
        manageStandsButton = new QPushButton(AdminMenu);
        manageStandsButton->setObjectName("manageStandsButton");
        manageStandsButton->setGeometry(QRect(520, 230, 231, 141));
        manageStandsButton->setFont(font);
        manageStandsButton->setCursor(QCursor(Qt::PointingHandCursor));
        manageStandsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font-size: 20px;\n"
"    font-weight: bold; \n"
"	background-color: #bc4749;\n"
"    color: white;\n"
"    border: 2px solid white;\n"
"    border-radius: 20px;    \n"
"    padding: 8px; \n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: #bc4749;\n"
"border: 2px solid black;\n"
"}"));

        retranslateUi(AdminMenu);

        QMetaObject::connectSlotsByName(AdminMenu);
    } // setupUi

    void retranslateUi(QDialog *AdminMenu)
    {
        AdminMenu->setWindowTitle(QCoreApplication::translate("AdminMenu", "Dialog", nullptr));
        admin_label->setText(QCoreApplication::translate("AdminMenu", "Admin Menu", nullptr));
        manageManagersButton->setText(QCoreApplication::translate("AdminMenu", "Manage Managers", nullptr));
        manageClientsButton->setText(QCoreApplication::translate("AdminMenu", "Manage Clients", nullptr));
        manageStandsButton->setText(QCoreApplication::translate("AdminMenu", "Manage Stands", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminMenu: public Ui_AdminMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMENU_H
