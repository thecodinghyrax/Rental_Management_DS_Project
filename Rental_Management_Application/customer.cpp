#include "customer.h"


Customer::Customer(){

};
Customer::Customer(std::string firstName,
                   std::string lastName,
                   std::string address,
                   std::string city,
                   std::string state,
                   std::string zip,
                   std::string phoneNumber){
    this->firstName = firstName;
    this->lastName = lastName;
    this->address = address;
    this->city = city;
    this->state = state;
    this->zip = zip;
    this->phoneNumber = phoneNumber;
};
Customer::~Customer(){

};
void Customer::setFirstName(std::string firstName){
        this->firstName = firstName;
};
void Customer::setLastName(std::string lastName){
        this->lastName = lastName;
};
void Customer::setAddress(std::string address){
        this->address = address;
};
void Customer::setCity(std::string city){
        this->city = city;
};
void Customer::setState(std::string state){
        this->state = state;
};
void Customer::setZip(std::string zip){
        this->zip = zip;
};
void Customer::setPhoneNumber(std::string phoneNumber){
        this->phoneNumber = phoneNumber;
};

std::string Customer::getFirstName(){
    return firstName;
};
std::string Customer::getLastName(){
        return lastName;
};
std::string Customer::getAddress(){
        return address;
};
std::string Customer::getCity(){
        return city;
};
std::string Customer::getState(){
        return state;
};
std::string Customer::getZip(){
        return zip;
};
std::string Customer::getPhoneNumber(){
        return phoneNumber;
};

std::string Customer::printCustomer(){
    std::string output;
    output.append("Customer[");;
    output.append(getFirstName() + " ");
    output.append(getLastName() + "\n");
    output.append(getAddress() + "\n");
    output.append(getCity() + ", ");
    output.append(getState() + " ");
    output.append(getZip() + "\n");
    output.append(getPhoneNumber() + "\n");
    return output;
};



