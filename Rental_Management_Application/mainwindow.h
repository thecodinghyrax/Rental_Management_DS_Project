#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QVector>
#include <QFile>
#include <QStandardPaths>
#include <QTextStream>
#include <QSet>
#include <QMap>
#include "customer.h"
#include "qlistwidget.h"
#include "rentalvehicle.h"
#include "inventory.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Customer getCustById(int);

private slots:

    bool validate(QString, QString, int, int);

    bool loadCustomers();

    bool loadVehicles();

    bool saveCustomers();

    bool saveVehilces();

    void on_welcomeNavBtn_clicked();

    void on_addCustomerNavBtn_clicked();

    void on_rentNavBtn_clicked();

    void on_returnNavBtn_clicked();

    void on_viewTransactionsNavBtn_clicked();

    void on_returnQueueNavBtn_clicked();

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

    void on_listWidget_itemClicked(QListWidgetItem *item);

    int getCustomerIndexById(int);

    void on_editCustSubmitBtn_clicked();

    void clearAllInput();

    void on_deleteCustSubmitBtn_clicked();

    void on_selectEconomyBtn_clicked();

    void on_selectCompactBtn_clicked();

    void on_selectStandardBtn_clicked();

    void on_selectPremiumBtn_clicked();

    void on_customerSearchBox_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QVector<Customer> customers;
    Inventory inventory;
    QMap<int, RentalVehicle*> transactions;
};
#endif // MAINWINDOW_H
