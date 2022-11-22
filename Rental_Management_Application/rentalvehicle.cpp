#include "rentalvehicle.h"

RentalVehicle::RentalVehicle()
{

}

RentalVehicle::RentalVehicle(int id, QString catagory, QString make, QString model,
                             int year, int milage, int renterId)
{
    setId(id);
    setCatagory(catagory);
    setMake(make);
    setModel(model);
    setYear(year);
    setMilage(milage);
    setIsRented(false);
    setRenterId(renterId);
}

RentalVehicle::~RentalVehicle()
{

}

void RentalVehicle::setId(int id)
{
    this->id = id;
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

void RentalVehicle::setRenterId(int renterId)
{
    this->renterId = renterId;
}


int RentalVehicle::getId()
{
    return this->id;
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

int RentalVehicle::getRenterId()
{
    return this->renterId;
}

QString RentalVehicle::printVehicle()
{
    QString temp = "";
    temp += QString::number(getId()) + ", ";
    temp += getCatagory() + ", ";
    temp += getMake() + ", ";
    temp += getModel() + ", ";
    temp += QString::number(getYear()) + ", ";
    temp += QString::number(getMilage()) + ", ";
    if(getIsRented()){
        temp += "true, ";
        temp += QString::number(getRenterId()) + ", ";
    }else {
        temp += "false, ";
    }

    return temp;
}