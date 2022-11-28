#ifndef RENTALVEHICLE_H
#define RENTALVEHICLE_H

#include "customer.h"

class RentalVehicle
{
private:
    int id;
    QString catagory;
    QString make;
    QString model;
    int year;
    int milage;
    bool isRented;
    int custNumber;
public:
    RentalVehicle();
    RentalVehicle(int, QString, QString, QString, int, int, int);
    ~RentalVehicle();

    void setId(int);
    void setCatagory(QString);
    void setMake(QString);
    void setModel(QString);
    void setYear(int);
    void setMilage(int);
    void setIsRented(bool);
    void setCustNumber(int);

    int getId();
    QString getCatagory();
    QString getMake();
    QString getModel();
    int getYear();
    int getMilage();
    bool getIsRented();
    int getCustNumber();

    QString printVehicle();
};

#endif // RENTALVEHICLE_H
