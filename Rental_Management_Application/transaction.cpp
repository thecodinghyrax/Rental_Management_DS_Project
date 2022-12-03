#include "transaction.h"

Transaction::Transaction(QDateTime start, double amount, int numberOfDays, int vehicleId, int custNumber){
    setStartDate(start);
    setChargeAmount(amount);
    setNumberOfDays(numberOfDays);
    setVehicleId(vehicleId);
    setCustNumber(custNumber);
};
Transaction::Transaction(QDateTime start, QDateTime end, double amount, int numberOfDays,int vehicleId, int custNumber, QString returnNote){
    setStartDate(start);
    setEndDate(end);
    setChargeAmount(amount);
    setNumberOfDays(numberOfDays);
    setVehicleId(vehicleId);
    setCustNumber(custNumber);
    setReturnNote(returnNote);
};
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
Transaction::~Transaction(){

};
void Transaction::setId(int id){
    this->id = id;
}
void Transaction::setStartDate(QDateTime start){
    this->rentalStartDate = start;
};
void Transaction::setEndDate(QDateTime end){
    this->rentalEndDate = end;
};
void Transaction::setChargeAmount(double amount){
    this->chargeAmount = amount;
};
void Transaction::setNumberOfDays(int numberOfDays){
    this->numberOfDays = numberOfDays;
}
void Transaction::setVehicleId(int id){
    this->vehicleId = id;
};
void Transaction::setCustNumber(int id){
    this->custNumber = id;
};
void Transaction::setReturnNote(QString note){
    this->returnNote = note;
};

int Transaction::getId(){
    return id;
}
QDateTime Transaction::getStartDate(){
    return rentalStartDate;
};
QDateTime Transaction::getEndDate(){
    return rentalEndDate;
};
double Transaction::getChargeAmount(){
    return chargeAmount;
};
int Transaction::getNumberOfDays(){
    return numberOfDays;
}
int Transaction::getVehicleId(){
    return vehicleId;
};
int Transaction::getCustNumber(){
    return custNumber;
};
QString Transaction::getReturnNote(){
    return returnNote;
};
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
