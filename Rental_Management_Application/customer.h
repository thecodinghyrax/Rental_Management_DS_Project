/***************************************************************
* Name        : Customer
* Author      : Drew Crawford
* Created     : 12/9/22
***************************************************************/
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <sstream>
#include <QString>
#include <QHashFunctions>
#include <QHash>


class Customer
{
private:
    QString firstName;
    QString lastName;
    QString address;
    QString city;
    QString state;
    QString zip;
    QString phoneNumber;
    QString DLNumber;
    QString CCNumber;
    int custNumber;
public:
    /**************************************************************
    * Constructors
    ***************************************************************/
    /**************************************************************
    * Name: Drew Crawford
    * Class Name: Customer
    * Description: Default no-arg constructor
    * Input parameters: none
    ***************************************************************/
    Customer();

    /**************************************************************
    * Name: Drew Crawford
    * Class Name: Customer
    * Description: Constructor that accepts firstName, lastName, address
    *               city, state, zip, phone number, DL number, and CC number
    * Input: string firstName, string lastNamem string address,
    *       string city, string state, string zip, string phone number,
    *       string DL number, string CC number, int customerNumber
    ***************************************************************/
    Customer(QString, QString, QString, QString, QString,
              QString, QString, QString, QString, int);

    /**************************************************************
    * Name: Drew Crawford
    * Class Name: Customer
    * Description: Constructor that accepts firstName, lastName, address
    *               city, state, zip, phone number, DL number, and CC number
    * Input: string firstName, string lastNamem string address,
    *       string city, string state, string zip, string phone number,
    *       string DL number, string CC number
    ***************************************************************/
    Customer(QString, QString, QString, QString, QString,
              QString, QString, QString, QString);

    /**************************************************************
    * Name: Drew Crawford
    * Class Name: ~Classname(Change)
    * Description: Destructor
    * Input parameters: none
    ***************************************************************/
    ~Customer();


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
    void setFirstName(QString);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setLastName
    * Description: Sets the lastName
    * Input: string lastName
    * Output: none
    ***************************************************************/
    void setLastName(QString);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setAddress
    * Description: Sets the address
    * Input: string address
    * Output: none
    ***************************************************************/
    void setAddress(QString);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setCity
    * Description: Sets the city
    * Input: string city
    * Output: none
    ***************************************************************/
    void setCity(QString);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setState
    * Description: Sets the state
    * Input: string state
    * Output: none
    ***************************************************************/
    void setState(QString);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setZip
    * Description: Sets the zip
    * Input: string zip
    * Output: none
    ***************************************************************/
    void setZip(QString);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setPhoneNumber
    * Description: Sets the phone number
    * Input: string phone number
    * Output: none
    ***************************************************************/
    void setPhoneNumber(QString);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setDLNumber
    * Description: Sets the driver license number
    * Input: string driver license number
    * Output: none
    ***************************************************************/
    void setDLNumber(QString);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setCCNumber
    * Description: Sets the credit card number
    * Input: string credit card number
    * Output: none
    ***************************************************************/
    void setCCNumber(QString);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setCustNumber
    * Description: Sets the customer number
    * Input: string customer number
    * Output: none
    ***************************************************************/
    void setCustNumber(int);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getFirstName
    * Description: Gets the firstName
    * Input: none
    * Output: string firstName
    ***************************************************************/
    QString getFirstName();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getLastName
    * Description: Gets the lastName
    * Input: none
    * Output: string lastName
    ***************************************************************/
    QString getLastName();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getAddress
    * Description: Gets the address
    * Input: none
    * Output: string address
    ***************************************************************/
    QString getAddress();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getCity
    * Description: Gets the city
    * Input: none
    * Output: string city
    ***************************************************************/
    QString getCity();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getState
    * Description: Gets the state
    * Input: none
    * Output: string state
    ***************************************************************/
    QString getState();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getZip
    * Description: Gets the zip
    * Input: none
    * Output: string zip
    ***************************************************************/
    QString getZip();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getPhoneNumber
    * Description: Gets the phone number
    * Input: none
    * Output: string phone number
    ***************************************************************/
    QString getPhoneNumber();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getDLNumber
    * Description: Gets the driver license number
    * Input: none
    * Output: string driver license number
    ***************************************************************/
    QString getDLNumber();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getCCNumber
    * Description: Gets the credit card number
    * Input: none
    * Output: string credit card number
    ***************************************************************/
    QString getCCNumber();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getCustNumber
    * Description: Gets the customer number
    * Input: none
    * Output: string customer number
    ***************************************************************/
    int getCustNumber();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: printCustomer
    * Description: return all customer data as a string
    * Input: none
    * Output: string all customer data
    ***************************************************************/
    QString printCustomer();



};

#endif // CUSTOMER_H
