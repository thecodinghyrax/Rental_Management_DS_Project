/***************************************************************
* Name        : RentalVehicle
* Author      : Drew Crawford
* Created     : 12/9/22
***************************************************************/
#include "rentalvehicle.h"

/**************************************************************
* Constructors
***************************************************************/

/**************************************************************
* Name: Drew Crawford
* Class Name: RentalVehicle
* Description: Default no-arg constructor
* Input parameters: none
***************************************************************/
RentalVehicle::RentalVehicle()
{

}

/**************************************************************
* Name: Drew Crawford
* Class Name: RentalVehicle
* Description: Constructor that accepts a catagory, make, model,
*               year, milage, isRented, and customer nunmber
* Input: QString catagory, QString make, QString model,
         int year, int milage, bool isRented, int custNumber
***************************************************************/
RentalVehicle::RentalVehicle(QString catagory, QString make, QString model,
                             int year, int milage, bool isRented, int custNumber)
{
    setCatagory(catagory);
    setMake(make);
    setModel(model);
    setYear(year);
    setMilage(milage);
    setIsRented(isRented);
    setCustNumber(custNumber);
}

/**************************************************************
* Name: Drew Crawford
* Class Name: RentalVehicle
* Description: Constructor that accepts a catagory, make, model,
*               year, milage and isRented.
* Input: QString catagory, QString make, QString model,
         int year, int milage, bool isRented
***************************************************************/
RentalVehicle::RentalVehicle(QString catagory, QString make, QString model,
                             int year, int milage, bool isRented)
{
    setCatagory(catagory);
    setMake(make);
    setModel(model);
    setYear(year);
    setMilage(milage);
    setIsRented(isRented);
    setCustNumber(-1);
}

/**************************************************************
* Name: Drew Crawford
* Class Name: RentalVehicle
* Description: Constructor that accepts a vehicle number, catagory,
*               make, model, year, milage, isRented, and customer nunmber
* Input: int vehicleNumber, QString catagory, QString make, QString model,
         int year, int milage, bool isRented, int custNumber
***************************************************************/
RentalVehicle::RentalVehicle(int vehicleNumber, QString catagory, QString make, QString model,
                             int year, int milage, bool isRented, int custNumber)
{
    setVehicleNumber(vehicleNumber);
    setCatagory(catagory);
    setMake(make);
    setModel(model);
    setYear(year);
    setMilage(milage);
    setIsRented(isRented);
    setCustNumber(custNumber);
}

/**************************************************************
* Name: Drew Crawford
* Class Name: ~RentalVehicle
* Description: Destructor
* Input parameters: none
***************************************************************/
RentalVehicle::~RentalVehicle()
{

}

/***************************************************************
* Class Methods
***************************************************************/

/**************************************************************
* Name: Drew Crawford
* Method Name: setVehicleNumber
* Description: Sets the vehicleNumber
* Input: int/vehicleNumber
* Output: none
***************************************************************/
void RentalVehicle::setVehicleNumber(int vehicleNumber)
{
    this->vehicleNumber = vehicleNumber;
}

/**************************************************************
* Name: Drew Crawford
* Method Name: setVehicleNumber
* Description: Sets the vehicleNumber
* Input: int/vehicleNumber
* Output: none
***************************************************************/
void RentalVehicle::setCatagory(QString catagory)
{
    this->catagory = catagory;
}

/**************************************************************
* Name: Drew Crawford
* Method Name: setMake
* Description: Sets the make
* Input: QString/make
* Output: none
***************************************************************/
void RentalVehicle::setMake(QString make)
{
    this->make = make;
}

/**************************************************************
* Name: Drew Crawford
* Method Name: setModel
* Description: Sets the model
* Input: QString/model
* Output: none
***************************************************************/
void RentalVehicle::setModel(QString model)
{
    this->model = model;
}

/**************************************************************
* Name: Drew Crawford
* Method Name: setYear
* Description: Sets the year
* Input: int/year
* Output: none
***************************************************************/
void RentalVehicle::setYear(int year)
{
    this->year = year;
}

/**************************************************************
* Name: Drew Crawford
* Method Name: setMilage
* Description: Sets the milage
* Input: int/milage
* Output: none
***************************************************************/
void RentalVehicle::setMilage(int milage)
{
    this->milage = milage;
}

/**************************************************************
* Name: Drew Crawford
* Method Name: setIsRented
* Description: Sets the idRented value. True if rented else false
* Input: bool/isRented
* Output: none
***************************************************************/
void RentalVehicle::setIsRented(bool isRented)
{
    this->isRented = isRented;
}

/**************************************************************
* Name: Drew Crawford
* Method Name: setCustNumber
* Description: Sets the custNumber
* Input: int/custNumber
* Output: none
***************************************************************/
void RentalVehicle::setCustNumber(int custNumber)
{
    this->custNumber = custNumber;
}

/**************************************************************
* Name: Drew Crawford
* Method Name: getVehicleNumber
* Description: Gets the vehicleNumber
* Input: none
* Output: int/vehicleNumber
***************************************************************/
int RentalVehicle::getVehicleNumber()
{
    return this->vehicleNumber;
}

/**************************************************************
* Name: Drew Crawford
* Method Name: getCatagory
* Description: Gets the catagory
* Input: none
* Output: QString/catagory
***************************************************************/
QString RentalVehicle::getCatagory()
{
    return this->catagory;
}

/**************************************************************
* Name: Drew Crawford
* Method Name: getMake
* Description: Gets the make
* Input: none
* Output: QString/make
***************************************************************/
QString RentalVehicle::getMake()
{
    return this->make;
}

/**************************************************************
* Name: Drew Crawford
* Method Name: getModel
* Description: Gets the model
* Input: none
* Output: QString/model
***************************************************************/
QString RentalVehicle::getModel()
{
    return this->model;
}

/**************************************************************
* Name: Drew Crawford
* Method Name: getYear
* Description: Gets the year
* Input: none
* Output: int/year
***************************************************************/
int RentalVehicle::getYear()
{
    return this->year;
}

/**************************************************************
* Name: Drew Crawford
* Method Name: getMilage
* Description: Gets the milage
* Input: none
* Output: int/milage
***************************************************************/
int RentalVehicle::getMilage()
{
    return this->milage;
}

/**************************************************************
* Name: Drew Crawford
* Method Name: getIsRented
* Description: Gets the isRented value. True if rented else false
* Input: none
* Output: bool/isRented
***************************************************************/
bool RentalVehicle::getIsRented()
{
    return this->isRented;
}

/**************************************************************
* Name: Drew Crawford
* Method Name: getCustNumber
* Description: Gets the custNumber
* Input: none
* Output: int/custNumber
***************************************************************/
int RentalVehicle::getCustNumber()
{
    return this->custNumber;
}

/**************************************************************
* Name: Drew Crawford
* Method Name: printVehicle
* Description: Gets the rental vehicle data
* Input: none
* Output: QString/ all vehicle data
***************************************************************/
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
