/***************************************************************
* Name        : Transaction
* Author      : Drew Crawford
* Created     : 12/9/22
***************************************************************/
#include "transaction.h"

/**************************************************************
* Constructors
***************************************************************/

/**************************************************************
* Name: Drew Crawford
* Class Name: Transaction
* Description: Default no-arg constructor
* Input parameters: none
***************************************************************/
Transaction::Transaction(){

};

/**************************************************************
* Name: Drew Crawford
* Class Name: Transaction
* Description: Constructor that accepts start, amount, numberOfDays,
*              vehicleId and custNumber
* Input: QDateTime/start, double/amount, int/numberOfDays,
*       int/vehicleId, int/custNumber
***************************************************************/
Transaction::Transaction(QDateTime start, double amount, int numberOfDays, int vehicleId, int custNumber){
    setStartDate(start);
    setChargeAmount(amount);
    setNumberOfDays(numberOfDays);
    setVehicleId(vehicleId);
    setCustNumber(custNumber);
};

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
Transaction::Transaction(QDateTime start, QDateTime end, double amount, int numberOfDays,int vehicleId, int custNumber, QString returnNote){
    setStartDate(start);
    setEndDate(end);
    setChargeAmount(amount);
    setNumberOfDays(numberOfDays);
    setVehicleId(vehicleId);
    setCustNumber(custNumber);
    setReturnNote(returnNote);
};

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
Transaction::Transaction(int id, QDateTime start, QDateTime end, double amount, int numberOfDays,int vehicleId, int custNumber, QString returnNote){
    setId(id);
    setStartDate(start);
    setEndDate(end);
    setChargeAmount(amount);
    setNumberOfDays(numberOfDays);
    setVehicleId(vehicleId);
    setCustNumber(custNumber);
    setReturnNote(returnNote);
};

/**************************************************************
* Name: Drew Crawford
* Class Name: ~Transaction
* Description: Destructor
* Input parameters: none
***************************************************************/
Transaction::~Transaction(){

};

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
void Transaction::setId(int id){
    this->id = id;
}

/**************************************************************
* Name: Drew Crawford
* Method Name: setStartDate
* Description: Sets the start date
* Input: QDateTime/start
* Output: none
***************************************************************/
void Transaction::setStartDate(QDateTime start){
    this->rentalStartDate = start;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: setEndDate
* Description: Sets the end date
* Input: QDateTime/end
* Output: none
***************************************************************/
void Transaction::setEndDate(QDateTime end){
    this->rentalEndDate = end;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: setChargeAmount
* Description: Sets the charge amount
* Input: double/amount
* Output: none
***************************************************************/
void Transaction::setChargeAmount(double amount){
    this->chargeAmount = amount;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: setNumberOfDays
* Description: Sets the setNumberOfDays of the rental
* Input: int/numberOfDays
* Output: none
***************************************************************/
void Transaction::setNumberOfDays(int numberOfDays){
    this->numberOfDays = numberOfDays;
}

/**************************************************************
* Name: Drew Crawford
* Method Name: setVehicleId
* Description: Sets the vehicle id
* Input: int/id
* Output: none
***************************************************************/
void Transaction::setVehicleId(int id){
    this->vehicleId = id;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: setCustNumber
* Description: Sets the customer id
* Input: int/id
* Output: none
***************************************************************/
void Transaction::setCustNumber(int id){
    this->custNumber = id;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: setReturnNote
* Description: Sets the text describing the condition of the returned vehicle
* Input: QString/note
* Output: none
***************************************************************/
void Transaction::setReturnNote(QString note){
    this->returnNote = note;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: getId
* Description: Gets the transaction id
* Input: none
* Output: int/id
***************************************************************/
int Transaction::getId(){
    return id;
}

/**************************************************************
* Name: Drew Crawford
* Method Name: getStartDate
* Description: Gets the rentalStartDate
* Input: none
* Output: QDateTime/rentalStartDate
***************************************************************/
QDateTime Transaction::getStartDate(){
    return rentalStartDate;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: getEndDate
* Description: Gets the rentalEndDate
* Input: none
* Output: QDateTime/rentalEndDate
***************************************************************/
QDateTime Transaction::getEndDate(){
    return rentalEndDate;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: getChargeAmount
* Description: Gets the chargeAmount
* Input: none
* Output: double/chargeAmount
***************************************************************/
double Transaction::getChargeAmount(){
    return chargeAmount;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: getNumberOfDays
* Description: Gets the numberOfDays the vehicle was rented for
* Input: none
* Output: int/numberOfDays
***************************************************************/
int Transaction::getNumberOfDays(){
    return numberOfDays;
}

/**************************************************************
* Name: Drew Crawford
* Method Name: getVehicleId
* Description: Gets the vehicleId
* Input: none
* Output: int/vehicleId
***************************************************************/
int Transaction::getVehicleId(){
    return vehicleId;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: getCustNumber
* Description: Gets the custNumber
* Input: none
* Output: int/custNumber
***************************************************************/
int Transaction::getCustNumber(){
    return custNumber;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: getReturnNote
* Description: Gets the returnNote
* Input: none
* Output: QString/returnNote
***************************************************************/
QString Transaction::getReturnNote(){
    return returnNote;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: printTransaction
* Description: Gets all data from a transaction
* Input: none
* Output: QString/all data from a transaction
***************************************************************/
QString Transaction::printTransaction(){
    QString trans;
    trans.append("Transaction ID: " + QString::number(getId()) + "\n");
    trans.append("Customer Number: " + QString::number(getCustNumber()) + "\n");
    trans.append("Vehicle ID: " + QString::number(getVehicleId()) + "\n");

    trans.append("Start Date: " + getStartDate().toString() + "\n");
    trans.append("End Date: " + getEndDate().toString() + "\n");

    trans.append("Charge Amount: $" + QString::number(getChargeAmount()) + "\n");
    trans.append("Number of Days: " + QString::number(getNumberOfDays()) + "\n");
    trans.append("Return Note: " + getReturnNote() + "\n");
    trans.append("--------------------------------------------------------------\n");
    return trans;
};
