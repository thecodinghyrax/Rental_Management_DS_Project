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
    Customer();
//    Customer(QString, QString, QString, QString,
//             QString, QString, QString, QString, QString);
    Customer(QString, QString, QString, QString, QString,
              QString, QString, QString, QString, int);
    ~Customer();
    void setFirstName(QString);
    void setLastName(QString);
    void setAddress(QString);
    void setCity(QString);
    void setState(QString);
    void setZip(QString);
    void setPhoneNumber(QString);
    void setDLNumber(QString);
    void setCCNumber(QString);
    //void setCustNumber();
    void setCustNumber(int);

    QString getFirstName();
    QString getLastName();
    QString getAddress();
    QString getCity();
    QString getState();
    QString getZip();
    QString getPhoneNumber();
    QString getDLNumber();
    QString getCCNumber();
    int getCustNumber();

    int createCustNumber(QString, QString);
    QString printCustomer();



};

#endif // CUSTOMER_H
