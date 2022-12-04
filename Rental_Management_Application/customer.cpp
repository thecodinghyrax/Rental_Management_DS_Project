/***************************************************************
* Name        : Customer
* Author      : Drew Crawford
* Created     : 12/5/22
***************************************************************/
#include "customer.h"


/**************************************************************
* Constructors
***************************************************************/
/**************************************************************
* Name: Drew Crawford
* Class Name: Customer
* Description: Default no-arg constructor
* Input parameters: none
***************************************************************/
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
    setCustNumber(-1);
}

/**************************************************************
* Name: Drew Crawford
* Class Name: Customer
* Description: Constructor that accepts firstName, lastName, address
*               city, state, zip, phone number, DL number, and CC number
* Input: string firstName, string lastNamem string address,
*       string city, string state, string zip, string phone number,
*       string DL number, string CC number, int customerNumber
***************************************************************/
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

/**************************************************************
* Name: Drew Crawford
* Class Name: Customer
* Description: Constructor that accepts firstName, lastName, address
*               city, state, zip, phone number, DL number, and CC number
* Input: string firstName, string lastNamem string address,
*       string city, string state, string zip, string phone number,
*       string DL number, string CC number
***************************************************************/
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
    setCustNumber(-1);
};

/**************************************************************
* Name: Drew Crawford
* Class Name: ~Classname(Change)
* Description: Destructor
* Input parameters: none
***************************************************************/
Customer::~Customer(){

};


/***************************************************************
* Class Methods
***************************************************************/
/**************************************************************
* Name: Drew Crawford
* Method Name: setFirstName
* Description: Sets the firstName
* Input: string firstName
* Output: none
***************************************************************/
void Customer::setFirstName(QString firstName){
        this->firstName = firstName;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: setLastName
* Description: Sets the lastName
* Input: string lastName
* Output: none
***************************************************************/
void Customer::setLastName(QString lastName){
        this->lastName = lastName;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: setAddress
* Description: Sets the address
* Input: string address
* Output: none
***************************************************************/
void Customer::setAddress(QString address){
        this->address = address;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: setCity
* Description: Sets the city
* Input: string city
* Output: none
***************************************************************/
void Customer::setCity(QString city){
        this->city = city;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: setState
* Description: Sets the state
* Input: string state
* Output: none
***************************************************************/
void Customer::setState(QString state){
        this->state = state;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: setZip
* Description: Sets the zip
* Input: string zip
* Output: none
***************************************************************/
void Customer::setZip(QString zip){
        this->zip = zip;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: setPhoneNumber
* Description: Sets the phone number
* Input: string phone number
* Output: none
***************************************************************/
void Customer::setPhoneNumber(QString phoneNumber){
        this->phoneNumber = phoneNumber;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: setDLNumber
* Description: Sets the driver license number
* Input: string driver license number
* Output: none
***************************************************************/
void Customer::setDLNumber(QString DLNumber){
        this->DLNumber = DLNumber;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: setCCNumber
* Description: Sets the credit card number
* Input: string credit card number
* Output: none
***************************************************************/
void Customer::setCCNumber(QString CCNumber){
        this->CCNumber = CCNumber;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: setCustNumber
* Description: Sets the customer number
* Input: string customer number
* Output: none
***************************************************************/
void Customer::setCustNumber(int custNumber){
    this->custNumber = custNumber;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: getFirstName
* Description: Gets the firstName
* Input: none
* Output: string firstName
***************************************************************/
QString Customer::getFirstName(){
    return firstName;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: getLastName
* Description: Gets the lastName
* Input: none
* Output: string lastName
***************************************************************/
QString Customer::getLastName(){
        return lastName;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: getAddress
* Description: Gets the address
* Input: none
* Output: string address
***************************************************************/
QString Customer::getAddress(){
        return address;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: getCity
* Description: Gets the city
* Input: none
* Output: string city
***************************************************************/
QString Customer::getCity(){
        return city;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: getState
* Description: Gets the state
* Input: none
* Output: string state
***************************************************************/
QString Customer::getState(){
        return state;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: getZip
* Description: Gets the zip
* Input: none
* Output: string zip
***************************************************************/
QString Customer::getZip(){
        return zip;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: getPhoneNumber
* Description: Gets the phone number
* Input: none
* Output: string phone number
***************************************************************/
QString Customer::getPhoneNumber(){
        return phoneNumber;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: getDLNumber
* Description: Gets the driver license number
* Input: none
* Output: string driver license number
***************************************************************/
QString Customer::getDLNumber(){
        return DLNumber;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: getCCNumber
* Description: Gets the credit card number
* Input: none
* Output: string credit card number
***************************************************************/
QString Customer::getCCNumber(){
        return CCNumber;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: getCustNumber
* Description: Gets the customer number
* Input: none
* Output: string customer number
***************************************************************/
int Customer::getCustNumber(){
    return custNumber;
};

/**************************************************************
* Name: Drew Crawford
* Method Name: printCustomer
* Description: return all customer data as a string
* Input: none
* Output: string all customer data
***************************************************************/
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




