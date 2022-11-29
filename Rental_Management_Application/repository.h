#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDir>
#include <QVariant>
#include <QVector>
#include <QDebug>
#include "customer.h"
#include "rentalvehicle.h"
#include "transaction.h"

class Repository
{
private:
    QSqlDatabase db;
    QMap<QString, double> rentalPrices;

public:
    Repository();
    ~Repository();

    QVector<Customer> getCustomers();
    Customer getCustomerById(int);
    void addCustomer(Customer cust);
    void updateCustomer(Customer);
    void deleteCustomerById(int);
    int getNextCustNumber();

    QVector<RentalVehicle> getVehicles();
    RentalVehicle getVehicleById(int);
    int getAvailableVehicleIdByCatagory(QString);
    void addVehicle(RentalVehicle vehicle);
    void updateVehicle(RentalVehicle);
    void deleteVehicleById(int);
    double getPriceById(int);

    QVector<Transaction> getTransactions();
    Transaction getTransactionById(int);
    void addTransaction(Transaction transaction);
    void updateTransaction(Transaction);
    void deleteTransactionById(int);

    void setRentalPrice(QString, double);
    void setDefaultRentalPrices();
    void updateRentalPrice(QString, double);
    double getRentalPrice(QString);

    void testThings();
    void createTables();


};

#endif // REPOSITORY_H
