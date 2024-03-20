#ifndef MANAGESTANDSMENU_H
#define MANAGESTANDSMENU_H

#include "standsmanager.h"
#include "createStandDialog.h"

#include <QDialog>

namespace Ui {
class ManageStandsMenu;
}

class ManageStandsMenu : public QDialog
{
    Q_OBJECT

public:
    explicit ManageStandsMenu(QWidget *parent = nullptr);
    ~ManageStandsMenu();

private slots:
    void on_createStandButton_clicked();

    void on_createStandButton_2_clicked();

private:
    Ui::ManageStandsMenu *ui;
    StandsManager standsManager;
    CreateStandDialog createStandDialog;
};

#endif // MANAGESTANDSMENU_H
