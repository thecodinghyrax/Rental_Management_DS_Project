/***************************************************************
* Name        : Repository
* Author      : Drew Crawford
* Created     : 12/9/22
***************************************************************/
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
#include <QSqlTableModel>
#include "customer.h"
#include "rentalvehicle.h"
#include "transaction.h"


class Repository
{
private:
    QSqlDatabase db;
    QMap<QString, double> rentalPrices;

public:

    /**************************************************************
    * Constructors
    ***************************************************************/

    /**************************************************************
    * Name: Drew Crawford
    * Class Name: Repository
    * Description: Constructor that accepts a QMap of ints and
    *               QVectors of Transaction objects
    * Input: QMap<int, QVector<Transaction>>/map
    ***************************************************************/
    Repository(QMap<int, QVector<Transaction>>&);

    /**************************************************************
    * Name: Drew Crawford
    * Class Name: ~Repository
    * Description: Destructor
    * Input parameters: none
    ***************************************************************/
    ~Repository();

    /***************************************************************
    * Class Methods
    ***************************************************************/

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getCustomers
    * Description: Gets all customers found in the db
    * Input: none
    * Output: QVector<Customer>/customers
    ***************************************************************/
    QVector<Customer> getCustomers();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getCustomerById
    * Description: Gets a customer from the db by id
    * Input: int/id
    * Output: Customer/the customer with a matching id
    ***************************************************************/
    Customer getCustomerById(int);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: addCustomer
    * Description: Adds a Customer object to the db
    * Input: Customer/cust
    * Output: none
    ***************************************************************/
    void addCustomer(Customer cust);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: updateCustomer
    * Description: Updates a Customer in the db
    * Input: Customer/cust
    * Output: none
    ***************************************************************/
    void updateCustomer(Customer);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: deleteCustomerById
    * Description: Deletes a Customer from the db with a matching id
    * Input: int/id
    * Output: none
    ***************************************************************/
    void deleteCustomerById(int);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getNextCustNumber
    * Description: Gets the highest customer number in the db and returns
    *               a number one more than that
    * Input: none
    * Output: int/the highest Customer number plus one
    ***************************************************************/
    int getNextCustNumber();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getVehicles
    * Description: Gets all rental vehicles from the db
    * Input: none
    * Output: QVector<RentalVehicle>/All vehicles from the db
    ***************************************************************/
    QVector<RentalVehicle> getVehicles();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getRentedVehicles
    * Description: Gets all rental vehicles from the db that have
    *               a isRented value of true
    * Input: none
    * Output: QVector<RentalVehicle>/All rented vehicles
    ***************************************************************/
    QVector<RentalVehicle> getRentedVehicles();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getVehicleById
    * Description: Gets a vehicle from the db by its id
    * Input: int/id
    * Output: RentalVehicle/the vehicle with a matching id
    ***************************************************************/
    RentalVehicle getVehicleById(int);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getAvailableVehicleIdByCatagory
    * Description: Gets a single vehicle with a matching catagory
    *               that is not currently rented. Return -1 if
    *               none are avaible.
    * Input: QString/catagory
    * Output: RentalVehicle/the vehicle with a matching id
    ***************************************************************/
    int getAvailableVehicleIdByCatagory(QString);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: addVehicle
    * Description: Adds a rental vehicle to the db
    * Input:RentalVehicle/vehicle
    * Output: none
    ***************************************************************/
    void addVehicle(RentalVehicle vehicle);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: updateVehicle
    * Description: Udates a rental vehicle in the db
    * Input:RentalVehicle/vehicle
    * Output: none
    ***************************************************************/
    void updateVehicle(RentalVehicle);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: deleteVehicleById
    * Description: Deletes a rental vehicle from the db with a
    *               matching id
    * Input:int/id
    * Output: none
    ***************************************************************/
    void deleteVehicleById(int);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getTransactions
    * Description: Gets all Transactions from the db
    * Input: none
    * Output: QVector<Transaction>/transactions
    ***************************************************************/
    QVector<Transaction> getTransactions();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getTransactionsByCustId
    * Description: Gets all Transactions from the db with a
    *               matcching customer Id
    * Input: int/custId
    * Output: QVector<Transaction>/transactions for a customer
    ***************************************************************/
    QVector<Transaction> getTransactionsByCustId(int);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getCompletedTransactionsByCustId
    * Description: Gets all Transactions from the db with a
    *               matcching customer Id and an end date
    * Input: int/custId
    * Output: QVector<Transaction>/transactions for a customer with end date
    ***************************************************************/
    QVector<Transaction> getCompletedTransactionsByCustId(int);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getTransactionById
    * Description: Gets a single transaction from the db with
    *               a matching id
    * Input: int/transId
    * Output: Transaction/transaction with matching id
    ***************************************************************/
    Transaction getTransactionById(int);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getTransactionByRentedVehicleId
    * Description: Gets the last transaction for a single vehicle.
    *           If the vehicle is currently rented, this will be
    *           the current (open) transaction.
    * Input: int/vehicleId
    * Output: Transaction/last transaction with matching vehicle id
    ***************************************************************/
    Transaction getTransactionByRentedVehicleId(int);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: addTransaction
    * Description: Adds a transacgtion to the db
    * Input: Transaction/transaction
    * Output: none
    ***************************************************************/
    void addTransaction(Transaction transaction);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: updateTransaction
    * Description: Updates a transacgtion in the db
    * Input: Transaction/transaction
    * Output: none
    ***************************************************************/
    void updateTransaction(Transaction);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: deleteTransactionById
    * Description: Deletes a transacgtion in the db with a matching id
    * Input: int/id
    * Output: none
    ***************************************************************/
    void deleteTransactionById(int);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setRentalPrice
    * Description: Sets a rental price for a matching catagory
    * Input: QString/catagory, double/price
    * Output: none
    ***************************************************************/
    void setRentalPrice(QString, double);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setDefaultRentalPrices
    * Description: Sets the default rental prices for all vehicles catagories
    * Input: none
    * Output: none
    ***************************************************************/
    void setDefaultRentalPrices();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: updateRentalPrice
    * Description: Update a catagory price
    * Input: QString/catagory, double/price
    * Output: none
    ***************************************************************/
    void updateRentalPrice(QString, double);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getRentalPrice
    * Description: Gets the price of a catagory
    * Input: QString/catagory
    * Output: none
    ***************************************************************/
    double getRentalPrice(QString);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getHistoryModel
    * Description: Creates a data modle to be used in a QTableView showing
    *               all transactions with an end date (completed)
    * Input: QSqlQueryModel/ *model
    * Output: none
    ***************************************************************/
    void getHistoryModel(QSqlQueryModel *model);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: sortTransactionByDate
    * Description: sorts a QVector of Transactions by date. This
    *               is an insersion sort algorithm written by Drew.
    * Input: QVector<Transaction>/&transactions
    * Output: none
    ***************************************************************/
    void sortTransactionByDate(QVector<Transaction>&);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: updateCustTransMap
    * Description: Clears the customer transaction map and adds back
    *               all customers and their sorted transactions.
    * Input: QMap<int, QVector<Transaction>>/& map
    * Output: none
    ***************************************************************/
    void updateCustTransMap(QMap<int, QVector<Transaction>>&);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: createTables
    * Description: Resets all tables in the db and populates them
    *               with test data.
    * Input: none
    * Output: none
    ***************************************************************/
    void createTables();

};

#endif // REPOSITORY_H
