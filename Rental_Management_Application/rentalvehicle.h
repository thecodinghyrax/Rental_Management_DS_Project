#ifndef RENTALVEHICLE_H
#define RENTALVEHICLE_H

#include "customer.h"

class RentalVehicle
{
private:
    int vehicleNumber;
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

    void setVehicleNumber(int);
    void setCatagory(QString);
    void setMake(QString);
    void setModel(QString);
    void setYear(int);
    void setMilage(int);
    void setIsRented(bool);
    void setCustNumber(int);

    int getVehicleNumber();
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
