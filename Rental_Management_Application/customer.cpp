#include "customer.h"


Customer::Customer(){

};
Customer::Customer(QString firstName,
                   QString lastName,
                   QString address,
                   QString city,
                   QString state,
                   QString zip,
                   QString phoneNumber,
                   QString DLNumber,
                   QString CCNumber){
    this->firstName = firstName;
    this->lastName = lastName;
    this->address = address;
    this->city = city;
    this->state = state;
    this->zip = zip;
    this->phoneNumber = phoneNumber;
    this->DLNumber = DLNumber;
    this->CCNumber = CCNumber;
};
Customer::~Customer(){

};
void Customer::setFirstName(QString firstName){
        this->firstName = firstName;
};
void Customer::setLastName(QString lastName){
        this->lastName = lastName;
};
void Customer::setAddress(QString address){
        this->address = address;
};
void Customer::setCity(QString city){
        this->city = city;
};
void Customer::setState(QString state){
        this->state = state;
};
void Customer::setZip(QString zip){
        this->zip = zip;
};
void Customer::setPhoneNumber(QString phoneNumber){
        this->phoneNumber = phoneNumber;
};
void Customer::setDLNumber(QString DLNumber){
        this->DLNumber = DLNumber;
};
void Customer::setCCNumber(QString CCNumber){
        this->CCNumber = CCNumber;
};

QString Customer::getFirstName(){
    return firstName;
};
QString Customer::getLastName(){
        return lastName;
};
QString Customer::getAddress(){
        return address;
};
QString Customer::getCity(){
        return city;
};
QString Customer::getState(){
        return state;
};
QString Customer::getZip(){
        return zip;
};
QString Customer::getPhoneNumber(){
        return phoneNumber;
};
QString Customer::getDLNumber(){
        return DLNumber;
};
QString Customer::getCCNumber(){
        return CCNumber;
};

QString Customer::printCustomer(){
    QString output;
    output.append("Customer[");;
    output.append(getFirstName() + " ");
    output.append(getLastName() + "\n");
    output.append(getAddress() + "\n");
    output.append(getCity() + ", ");
    output.append(getState() + " ");
    output.append(getZip() + "\n");
    output.append(getPhoneNumber() + "\n");
    output.append(getDLNumber() + "\n");
    output.append(getCCNumber() + "\n");
    return output;
};



