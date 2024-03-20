/********************************************************************************
** Form generated from reading UI file 'managestandsmenu.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGESTANDSMENU_H
#define UI_MANAGESTANDSMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ManageStandsMenu
{
public:
    QLabel *showUserName_label;
    QLabel *manageStands_label;
    QPushButton *createStandButton;
    QLabel *label;
    QPushButton *createStandButton_2;
    QPushButton *createStandButton_3;
    QPushButton *createStandButton_4;

    void setupUi(QDialog *ManageStandsMenu)
    {
        if (ManageStandsMenu->objectName().isEmpty())
            ManageStandsMenu->setObjectName("ManageStandsMenu");
        ManageStandsMenu->resize(660, 519);
        showUserName_label = new QLabel(ManageStandsMenu);
        showUserName_label->setObjectName("showUserName_label");
        showUserName_label->setEnabled(true);
        showUserName_label->setGeometry(QRect(50, 120, 91, 23));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(showUserName_label->sizePolicy().hasHeightForWidth());
        showUserName_label->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(14);
        showUserName_label->setFont(font);
        showUserName_label->setFrameShape(QFrame::NoFrame);
        manageStands_label = new QLabel(ManageStandsMenu);
        manageStands_label->setObjectName("manageStands_label");
        manageStands_label->setGeometry(QRect(490, 10, 161, 41));
        manageStands_label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 18px;\n"
"    font-weight: bold; \n"
"	background-color: #222;\n"
"    color: #fff;\n"
"    border-radius: 20px;    \n"
"    padding-right: 8px;\n"
"	padding-left: 8px;\n"
"}"));
        createStandButton = new QPushButton(ManageStandsMenu);
        createStandButton->setObjectName("createStandButton");
        createStandButton->setGeometry(QRect(190, 190, 271, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setStrikeOut(false);
        createStandButton->setFont(font1);
        createStandButton->setCursor(QCursor(Qt::PointingHandCursor));
        createStandButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: #86B6F6; \n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 8px 16px; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 1px solid black;\n"
"}"));
        label = new QLabel(ManageStandsMenu);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 20, 111, 91));
        label->setPixmap(QPixmap(QString::fromUtf8("../images/icons8-user-100.png")));
        createStandButton_2 = new QPushButton(ManageStandsMenu);
        createStandButton_2->setObjectName("createStandButton_2");
        createStandButton_2->setGeometry(QRect(190, 250, 271, 41));
        createStandButton_2->setFont(font1);
        createStandButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        createStandButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: #86B6F6; \n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 8px 16px; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 1px solid black;\n"
"}"));
        createStandButton_3 = new QPushButton(ManageStandsMenu);
        createStandButton_3->setObjectName("createStandButton_3");
        createStandButton_3->setGeometry(QRect(190, 370, 271, 41));
        createStandButton_3->setFont(font1);
        createStandButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        createStandButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: #86B6F6; \n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 8px 16px; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 1px solid black;\n"
"}"));
        createStandButton_4 = new QPushButton(ManageStandsMenu);
        createStandButton_4->setObjectName("createStandButton_4");
        createStandButton_4->setGeometry(QRect(190, 310, 271, 41));
        createStandButton_4->setFont(font1);
        createStandButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        createStandButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: #86B6F6; \n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 8px 16px; \n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    border: 1px solid black;\n"
"}"));

        retranslateUi(ManageStandsMenu);

        QMetaObject::connectSlotsByName(ManageStandsMenu);
    } // setupUi

    void retranslateUi(QDialog *ManageStandsMenu)
    {
        ManageStandsMenu->setWindowTitle(QCoreApplication::translate("ManageStandsMenu", "Dialog", nullptr));
        showUserName_label->setText(QCoreApplication::translate("ManageStandsMenu", "<html><head/><body><p>Welcome</p></body></html>", nullptr));
        manageStands_label->setText(QCoreApplication::translate("ManageStandsMenu", "Manage Stands", nullptr));
#if QT_CONFIG(tooltip)
        createStandButton->setToolTip(QCoreApplication::translate("ManageStandsMenu", "<html><head/><body><p>Regist Stand</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        createStandButton->setText(QCoreApplication::translate("ManageStandsMenu", "Regist Stand", nullptr));
        label->setText(QString());
#if QT_CONFIG(tooltip)
        createStandButton_2->setToolTip(QCoreApplication::translate("ManageStandsMenu", "<html><head/><body><p>Regist Stand</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        createStandButton_2->setText(QCoreApplication::translate("ManageStandsMenu", "Regist Vehicle", nullptr));
#if QT_CONFIG(tooltip)
        createStandButton_3->setToolTip(QCoreApplication::translate("ManageStandsMenu", "<html><head/><body><p>Regist Stand</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        createStandButton_3->setText(QCoreApplication::translate("ManageStandsMenu", "Delete Vehicle From Stand", nullptr));
#if QT_CONFIG(tooltip)
        createStandButton_4->setToolTip(QCoreApplication::translate("ManageStandsMenu", "<html><head/><body><p>Regist Stand</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        createStandButton_4->setText(QCoreApplication::translate("ManageStandsMenu", "Move Vehicle To Another Stand", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageStandsMenu: public Ui_ManageStandsMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGESTANDSMENU_H
