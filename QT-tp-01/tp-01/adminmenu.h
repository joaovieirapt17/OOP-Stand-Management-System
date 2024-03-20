#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QDialog>

namespace Ui {
class AdminMenu;
}

class AdminMenu : public QDialog
{
    Q_OBJECT

public:
    explicit AdminMenu(QWidget *parent = nullptr);
    ~AdminMenu();

private slots:
    void onManageManagersClicked();
    void onManageClientsClicked();
    void onManageStandsClicked();

private:
    Ui::AdminMenu *ui;
};

#endif // ADMINMENU_H
