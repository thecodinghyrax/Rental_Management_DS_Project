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

class Repository
{
private:
    QSqlDatabase db;

public:
    Repository();
    ~Repository();
    QVector<Customer> getCustomers();
    Customer getCustomerById(int);
    QString addCustomer(Customer cust);
    int getNextCustNumber();
    void createCustomerTable();

};

#endif // REPOSITORY_H
