#include "customer.h"
#include "qmessagebox.h"


Customer::Customer()
{
    setFirstName("Not Entered");
    setLastName("Not Entered");
    setAddress("Not Entered");
    setCity("Not Entered");
    setState("Not Entered");
    setZip("Not Entered");
    setPhoneNumber("Not Entered");
    setDLNumber("Not Entered");
    setCCNumber("Not Entered");
    // setCustomerNumber will need to be call after the DL and CC info is entered
}


Customer::Customer(QString firstName,
                   QString lastName,
                   QString address,
                   QString city,
                   QString state,
                   QString zip,
                   QString phoneNumber,
                   QString DLNumber,
                   QString CCNumber){
    setFirstName(firstName);
    setLastName(lastName);
    setAddress(address);
    setCity(city);
    setState(state);
    setZip(zip);
    setPhoneNumber(phoneNumber);
    setDLNumber(DLNumber);
    setCCNumber(CCNumber);
    setCustNumber();

};

Customer::Customer(QString firstName,
                   QString lastName,
                   QString address,
                   QString city,
                   QString state,
                   QString zip,
                   QString phoneNumber,
                   QString DLNumber,
                   QString CCNumber,
                   int custNumber){
    setFirstName(firstName);
    setLastName(lastName);
    setAddress(address);
    setCity(city);
    setState(state);
    setZip(zip);
    setPhoneNumber(phoneNumber);
    setDLNumber(DLNumber);
    setCCNumber(CCNumber);
    setCustNumber(custNumber);

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

void Customer::setCustNumber(){
    int id = createCustNumber(this->getCCNumber(), this->getDLNumber());
    this->custNumber = id;
};

void Customer::setCustNumber(int custNumber){
    this->custNumber = custNumber;
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

int Customer::getCustNumber(){
    return custNumber;
};


int Customer::createCustNumber(QString str1, QString str2){

    uint value1 = 0;
    for(int i = 0; i < str1.length(); ++i){
        value1 += str1[i].digitValue();
        }
    uint value2 = 0;
    for(int i = 0; i < str2.length(); ++i){
        value2 += str2[i].digitValue();
        }
    return (value1 * value1 * value2 * value2) % 1000000;
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




