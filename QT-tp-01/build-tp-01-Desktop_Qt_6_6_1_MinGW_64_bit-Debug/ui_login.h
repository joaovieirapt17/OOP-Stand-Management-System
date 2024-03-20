/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QPushButton *LoginBtn;
    QLabel *logInSuccessful;
    QFrame *LogMain;
    QGridLayout *gridLayout;
    QLineEdit *password_lineEdit;
    QLineEdit *userName_lineEdit;
    QLabel *password_label;
    QLabel *userName_label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(800, 600);
        centralwidget = new QWidget(login);
        centralwidget->setObjectName("centralwidget");
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(260, 70, 331, 81));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../images/standvirtual_logo.png")));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(270, 380, 301, 81));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMinimumSize(QSize(100, 0));
        frame_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border-radius: 20px;\n"
"background-color: #3498db;\n"
"color: white;\n"
"padding: 8px 250px;\n"
"}\n"
"\n"
"QPushButton::hover {\n"
"background-color: #2980b9;\n"
"}"));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setObjectName("gridLayout_3");
        LoginBtn = new QPushButton(frame_2);
        LoginBtn->setObjectName("LoginBtn");
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(LoginBtn->sizePolicy().hasHeightForWidth());
        LoginBtn->setSizePolicy(sizePolicy1);
        LoginBtn->setMinimumSize(QSize(120, 40));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(18);
        LoginBtn->setFont(font);
        LoginBtn->setCursor(QCursor(Qt::PointingHandCursor));
        LoginBtn->setFocusPolicy(Qt::StrongFocus);
        LoginBtn->setAutoFillBackground(false);
        LoginBtn->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(LoginBtn, 0, 0, 1, 1);

        logInSuccessful = new QLabel(centralwidget);
        logInSuccessful->setObjectName("logInSuccessful");
        logInSuccessful->setGeometry(QRect(270, 150, 381, 21));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setBold(true);
        font1.setItalic(false);
        logInSuccessful->setFont(font1);
        logInSuccessful->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font-size: 15px;\n"
"    color: green;\n"
"    font-weight: bold;\n"
"}"));
        LogMain = new QFrame(centralwidget);
        LogMain->setObjectName("LogMain");
        LogMain->setGeometry(QRect(190, 170, 461, 211));
        sizePolicy1.setHeightForWidth(LogMain->sizePolicy().hasHeightForWidth());
        LogMain->setSizePolicy(sizePolicy1);
        LogMain->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    width: 150px;\n"
"    height: 30px;\n"
"    border-radius: 20px;\n"
"    list-style: none;\n"
"    border: 1px solid grey;\n"
"	padding-left: 12px;\n"
"	padding-right: 12px;\n"
"}\n"
"\n"
"QLabel {\n"
"color: black;\n"
"}"));
        LogMain->setFrameShape(QFrame::NoFrame);
        LogMain->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(LogMain);
        gridLayout->setObjectName("gridLayout");
        password_lineEdit = new QLineEdit(LogMain);
        password_lineEdit->setObjectName("password_lineEdit");
        sizePolicy1.setHeightForWidth(password_lineEdit->sizePolicy().hasHeightForWidth());
        password_lineEdit->setSizePolicy(sizePolicy1);
        password_lineEdit->setMinimumSize(QSize(300, 40));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(14);
        password_lineEdit->setFont(font2);
        password_lineEdit->setCursor(QCursor(Qt::IBeamCursor));
        password_lineEdit->setAutoFillBackground(false);
        password_lineEdit->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(password_lineEdit, 4, 1, 1, 1);

        userName_lineEdit = new QLineEdit(LogMain);
        userName_lineEdit->setObjectName("userName_lineEdit");
        sizePolicy1.setHeightForWidth(userName_lineEdit->sizePolicy().hasHeightForWidth());
        userName_lineEdit->setSizePolicy(sizePolicy1);
        userName_lineEdit->setMinimumSize(QSize(300, 40));
        userName_lineEdit->setFont(font2);
        userName_lineEdit->setCursor(QCursor(Qt::IBeamCursor));
        userName_lineEdit->setFrame(true);
        userName_lineEdit->setCursorPosition(0);

        gridLayout->addWidget(userName_lineEdit, 1, 1, 1, 1);

        password_label = new QLabel(LogMain);
        password_label->setObjectName("password_label");
        sizePolicy1.setHeightForWidth(password_label->sizePolicy().hasHeightForWidth());
        password_label->setSizePolicy(sizePolicy1);
        password_label->setFont(font);

        gridLayout->addWidget(password_label, 3, 1, 1, 1);

        userName_label = new QLabel(LogMain);
        userName_label->setObjectName("userName_label");
        userName_label->setEnabled(true);
        sizePolicy1.setHeightForWidth(userName_label->sizePolicy().hasHeightForWidth());
        userName_label->setSizePolicy(sizePolicy1);
        userName_label->setFont(font);
        userName_label->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(userName_label, 0, 1, 1, 1);

        login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(login);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        login->setMenuBar(menubar);
        statusbar = new QStatusBar(login);
        statusbar->setObjectName("statusbar");
        login->setStatusBar(statusbar);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "login", nullptr));
        label_2->setText(QString());
        LoginBtn->setText(QCoreApplication::translate("login", "Log In", nullptr));
        logInSuccessful->setText(QString());
        password_lineEdit->setPlaceholderText(QString());
        password_label->setText(QCoreApplication::translate("login", "<html><head/><body><p><span style=\" font-size:16pt;\">Password</span></p></body></html>", nullptr));
        userName_label->setText(QCoreApplication::translate("login", "<html><head/><body><p><span style=\" font-size:16pt;\">Username</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
