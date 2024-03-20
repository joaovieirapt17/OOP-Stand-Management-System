#ifndef CREATESTANDDIALOG_H
#define CREATESTANDDIALOG_H

#include <QDialog>

namespace Ui {
class CreateStandDialog;
}

class CreateStandDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateStandDialog(QWidget *parent = nullptr);
    ~CreateStandDialog();

private slots:
    void on_submitButton_clicked();

private:
    Ui::CreateStandDialog *ui;

signals:
    void standSubmitted(const QString& cityName, int standNumber);
};

#endif // CREATESTANDDIALOG_H
