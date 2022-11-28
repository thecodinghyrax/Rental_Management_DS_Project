#include "rentalvehicle.h"

RentalVehicle::RentalVehicle()
{

}

RentalVehicle::RentalVehicle(int vehicleNumber, QString catagory, QString make, QString model,
                             int year, int milage, int custNumber)
{
    setVehicleNumber(vehicleNumber);
    setCatagory(catagory);
    setMake(make);
    setModel(model);
    setYear(year);
    setMilage(milage);
    setIsRented(false);
    setCustNumber(custNumber);
}

RentalVehicle::~RentalVehicle()
{

}

void RentalVehicle::setVehicleNumber(int vehicleNumber)
{
    this->vehicleNumber = vehicleNumber;
}

void RentalVehicle::setCatagory(QString catagory)
{
    this->catagory = catagory;
}

void RentalVehicle::setMake(QString make)
{
    this->make = make;
}

void RentalVehicle::setModel(QString model)
{
    this->model = model;
}

void RentalVehicle::setYear(int year)
{
    this->year = year;
}

void RentalVehicle::setMilage(int milage)
{
    this->milage = milage;
}

void RentalVehicle::setIsRented(bool isRented)
{
    this->isRented = isRented;
}

void RentalVehicle::setCustNumber(int custNumber)
{
    this->custNumber = custNumber;
}


int RentalVehicle::getVehicleNumber()
{
    return this->vehicleNumber;
}

QString RentalVehicle::getCatagory()
{
    return this->catagory;
}

QString RentalVehicle::getMake()
{
    return this->make;
}

QString RentalVehicle::getModel()
{
    return this->model;
}

int RentalVehicle::getYear()
{
    return this->year;
}

int RentalVehicle::getMilage()
{
    return this->milage;
}

bool RentalVehicle::getIsRented()
{
    return this->isRented;
}

int RentalVehicle::getCustNumber()
{
    return this->custNumber;
}

QString RentalVehicle::printVehicle()
{
    QString temp = "";
    temp += QString::number(getVehicleNumber()) + ", ";
    temp += getCatagory() + ", ";
    temp += getMake() + ", ";
    temp += getModel() + ", ";
    temp += QString::number(getYear()) + ", ";
    temp += QString::number(getMilage()) + ", ";
    if(getIsRented()){
        temp += "true, ";
        temp += QString::number(getCustNumber()) + ", ";
    }else {
        temp += "false, ";
    }

    return temp;
}
