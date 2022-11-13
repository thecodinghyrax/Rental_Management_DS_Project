#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QVector>
#include "customer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_welcomeNavBtn_clicked();

    void on_addCustomerNavBtn_clicked();

    void on_rentNavBtn_clicked();

    void on_returnNavBtn_clicked();

    void on_viewTransactionsNavBtn_clicked();

    void on_returnQueueNavBtn_clicked();

    bool validate(QString, QString, int, int);

    void on_firstNameInput_textChanged(const QString &arg1);

    void on_lastNameInput_textChanged(const QString &arg1);

    void on_addressInput_textChanged(const QString &arg1);

    void on_cityInput_textChanged(const QString &arg1);

    void on_stateInput_textChanged(const QString &arg1);

    void on_zipInput_textChanged(const QString &arg1);

    void on_phoneNumberInput_textChanged(const QString &arg1);

    void on_DLInput_textChanged(const QString &arg1);

    void on_CCInput_textChanged(const QString &arg1);

    void on_addCustSubmitBtn_clicked();

    void on_loadCustList_clicked();

private:
    Ui::MainWindow *ui;
    QVector<Customer> customers;
};
#endif // MAINWINDOW_H
