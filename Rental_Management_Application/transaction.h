/***************************************************************
* Name        : Transaction
* Author      : Drew Crawford
* Created     : 12/9/22
***************************************************************/
#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <chrono>
#include <QString>
#include <QDateTime>

class Transaction
{
private:
    int id;
    QDateTime rentalStartDate;
    QDateTime rentalEndDate;
    double chargeAmount;
    int numberOfDays;
    int vehicleId;
    int custNumber;
    QString returnNote;
public:

    /**************************************************************
    * Constructors
    ***************************************************************/

    /**************************************************************
    * Name: Drew Crawford
    * Class Name: Transaction
    * Description: Default no-arg constructor
    * Input parameters: none
    ***************************************************************/
    Transaction();

    /**************************************************************
    * Name: Drew Crawford
    * Class Name: Transaction
    * Description: Constructor that accepts start, amount, numberOfDays,
    *              vehicleId and custNumber
    * Input: QDateTime/start, double/amount, int/numberOfDays,
    *       int/vehicleId, int/custNumber
    ***************************************************************/
    Transaction(QDateTime, double, int, int, int);

    /**************************************************************
    * Name: Drew Crawford
    * Class Name: Transaction
    * Description: Constructor that accepts start, end, amount,
    *               numberOfDays, vehicleId, custNumber
    *               and returnNote
    * Input: QDateTime start, QDateTime end, double amount,
    *       int numberOfDays,int vehicleId, int custNumber,
    *       QString returnNote
    ***************************************************************/
    Transaction(QDateTime, QDateTime, double, int, int, int, QString);

    /**************************************************************
    * Name: Drew Crawford
    * Class Name: Transaction
    * Description: Constructor that accepts id, start, end, amount,
    *               numberOfDays, vehicleId, custNumber
    *               and returnNote
    * Input: int id, QDateTime start, QDateTime end, double amount,
    *        int numberOfDays,int vehicleId, int custNumber,
    *        QString returnNote
    ***************************************************************/
    Transaction(int, QDateTime, QDateTime, double, int, int, int, QString);

    /**************************************************************
    * Name: Drew Crawford
    * Class Name: ~Transaction
    * Description: Destructor
    * Input parameters: none
    ***************************************************************/
    ~Transaction();

    /***************************************************************
    * Class Methods
    ***************************************************************/

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setId
    * Description: Sets the id
    * Input: int/id
    * Output: none
    ***************************************************************/
    void setId(int);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setStartDate
    * Description: Sets the start date
    * Input: QDateTime/start
    * Output: none
    ***************************************************************/
    void setStartDate(QDateTime);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setEndDate
    * Description: Sets the end date
    * Input: QDateTime/end
    * Output: none
    ***************************************************************/
    void setEndDate(QDateTime);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setChargeAmount
    * Description: Sets the charge amount
    * Input: double/amount
    * Output: none
    ***************************************************************/
    void setChargeAmount(double);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setNumberOfDays
    * Description: Sets the setNumberOfDays of the rental
    * Input: int/numberOfDays
    * Output: none
    ***************************************************************/
    void setNumberOfDays(int);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setVehicleId
    * Description: Sets the vehicle id
    * Input: int/id
    * Output: none
    ***************************************************************/
    void setVehicleId(int);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setCustNumber
    * Description: Sets the customer id
    * Input: int/id
    * Output: none
    ***************************************************************/
    void setCustNumber(int);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setReturnNote
    * Description: Sets the text describing the condition of the returned vehicle
    * Input: QString/note
    * Output: none
    ***************************************************************/
    void setReturnNote(QString);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getId
    * Description: Gets the transaction id
    * Input: none
    * Output: int/id
    ***************************************************************/
    int getId();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getStartDate
    * Description: Gets the rentalStartDate
    * Input: none
    * Output: QDateTime/rentalStartDate
    ***************************************************************/
    QDateTime getStartDate();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getEndDate
    * Description: Gets the rentalEndDate
    * Input: none
    * Output: QDateTime/rentalEndDate
    ***************************************************************/
    QDateTime getEndDate();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getChargeAmount
    * Description: Gets the chargeAmount
    * Input: none
    * Output: double/chargeAmount
    ***************************************************************/
    double getChargeAmount();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getNumberOfDays
    * Description: Gets the numberOfDays the vehicle was rented for
    * Input: none
    * Output: int/numberOfDays
    ***************************************************************/
    int getNumberOfDays();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getVehicleId
    * Description: Gets the vehicleId
    * Input: none
    * Output: int/vehicleId
    ***************************************************************/
    int getVehicleId();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getCustNumber
    * Description: Gets the custNumber
    * Input: none
    * Output: int/custNumber
    ***************************************************************/
    int getCustNumber();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getReturnNote
    * Description: Gets the returnNote
    * Input: none
    * Output: QString/returnNote
    ***************************************************************/
    QString getReturnNote();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: printTransaction
    * Description: Gets all data from a transaction
    * Input: none
    * Output: QString/all data from a transaction
    ***************************************************************/
    QString printTransaction();



};

#endif // TRANSACTION_H
