#include "transactions.h"

Transactions::Transactions(QDateTime start, double amount, int vehicleId, int custNumber){
    setStartDate(start);
    setChargeAmount(amount);
    setVehicleId(vehicleId);
    setCustNumber(custNumber);
};
Transactions::~Transactions(){

};

void Transactions::setStartDate(QDateTime start){
    this->rentalStartDate = start;
};
void Transactions::setEndDate(QDateTime end){
    this->rentalEndDate = end;
};
void Transactions::setChargeAmount(double amount){
    this->chargeAmount = amount;
};
void Transactions::setVehicleId(int id){
    this->vehicleId = id;
};
void Transactions::setCustNumber(int id){
    this->custNumber = id;
};
void Transactions::setReturnNote(QString note){
    this->returnNote = note;
};

QDateTime Transactions::getStartDate(){
    return rentalStartDate;
};
QDateTime Transactions::getEndDate(){
    return rentalEndDate;
};
double Transactions::getChargeAmount(){
    return chargeAmount;
};
int Transactions::getVehicleId(){
    return vehicleId;
};
int Transactions::getCustNumber(){
    return custNumber;
};
QString Transactions::getReturnNote(){
    return returnNote;
};
QString Transactions::printTransaction(){
    QString trans;
    trans.append("Customer Number: " + QString::number(getCustNumber()) + "\n");
    trans.append("Vehicle ID: " + QString::number(getVehicleId()) + "\n");

    trans.append("Start Date: " + getStartDate().toString() + "\n");
    trans.append("End Date: " + getEndDate().toString() + "\n");

    trans.append("Charge Amount: " + QString::number(getChargeAmount()) + "\n");
    trans.append("Return Note: " + getReturnNote() + "\n");
    trans.append("--------------------------------------------------------------");
    return trans;
};
