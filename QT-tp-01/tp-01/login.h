#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class login;
}
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
void onLoginBtnClicked();

private:
    Ui::login *ui;
    UserList userList;
};
#endif // LOGIN_H
