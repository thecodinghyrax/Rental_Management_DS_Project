#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QDir>
#include "customer.h"

class Repository
{
private:
    QSqlDatabase db;

public:
    Repository();
    ~Repository();
    void createCustomerTable();
};

#endif // REPOSITORY_H
