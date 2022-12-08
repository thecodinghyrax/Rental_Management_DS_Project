/***************************************************************
* Name        : RentalVehicle
* Author      : Drew Crawford
* Created     : 12/9/22
***************************************************************/
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
    /**************************************************************
    * Constructors
    ***************************************************************/

    /**************************************************************
    * Name: Drew Crawford
    * Class Name: RentalVehicle
    * Description: Default no-arg constructor
    * Input parameters: none
    ***************************************************************/
    RentalVehicle();

    /**************************************************************
    * Name: Drew Crawford
    * Class Name: RentalVehicle
    * Description: Constructor that accepts a catagory, make, model,
    *               year, milage, isRented, and customer nunmber
    * Input: QString catagory, QString make, QString model,
             int year, int milage, bool isRented, int custNumber
    ***************************************************************/
    RentalVehicle(QString, QString, QString,int, int, bool, int);

    /**************************************************************
    * Name: Drew Crawford
    * Class Name: RentalVehicle
    * Description: Constructor that accepts a catagory, make, model,
    *               year, milage and isRented.
    * Input: QString catagory, QString make, QString model,
             int year, int milage, bool isRented
    ***************************************************************/
    RentalVehicle(QString, QString, QString,int, int, bool);

    /**************************************************************
    * Name: Drew Crawford
    * Class Name: RentalVehicle
    * Description: Constructor that accepts a vehicle number, catagory,
    *               make, model, year, milage, isRented, and customer nunmber
    * Input: int vehicleNumber, QString catagory, QString make, QString model,
             int year, int milage, bool isRented, int custNumber
    ***************************************************************/
    RentalVehicle(int, QString, QString, QString, int, int, bool, int);

    /**************************************************************
    * Name: Drew Crawford
    * Class Name: ~RentalVehicle
    * Description: Destructor
    * Input parameters: none
    ***************************************************************/
    ~RentalVehicle();

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
    void setVehicleNumber(int);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setVehicleNumber
    * Description: Sets the vehicleNumber
    * Input: int/vehicleNumber
    * Output: none
    ***************************************************************/
    void setCatagory(QString);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setMake
    * Description: Sets the make
    * Input: QString/make
    * Output: none
    ***************************************************************/
    void setMake(QString);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setModel
    * Description: Sets the model
    * Input: QString/model
    * Output: none
    ***************************************************************/
    void setModel(QString);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setYear
    * Description: Sets the year
    * Input: int/year
    * Output: none
    ***************************************************************/
    void setYear(int);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setMilage
    * Description: Sets the milage
    * Input: int/milage
    * Output: none
    ***************************************************************/
    void setMilage(int);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setIsRented
    * Description: Sets the idRented value. True if rented else false
    * Input: bool/isRented
    * Output: none
    ***************************************************************/
    void setIsRented(bool);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: setCustNumber
    * Description: Sets the custNumber
    * Input: int/custNumber
    * Output: none
    ***************************************************************/
    void setCustNumber(int);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getVehicleNumber
    * Description: Gets the vehicleNumber
    * Input: none
    * Output: int/vehicleNumber
    ***************************************************************/
    int getVehicleNumber();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getCatagory
    * Description: Gets the catagory
    * Input: none
    * Output: QString/catagory
    ***************************************************************/
    QString getCatagory();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getMake
    * Description: Gets the make
    * Input: none
    * Output: QString/make
    ***************************************************************/
    QString getMake();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getModel
    * Description: Gets the model
    * Input: none
    * Output: QString/model
    ***************************************************************/
    QString getModel();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getYear
    * Description: Gets the year
    * Input: none
    * Output: int/year
    ***************************************************************/
    int getYear();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getMilage
    * Description: Gets the milage
    * Input: none
    * Output: int/milage
    ***************************************************************/
    int getMilage();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getIsRented
    * Description: Gets the isRented value. True if rented else false
    * Input: none
    * Output: bool/isRented
    ***************************************************************/
    bool getIsRented();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: getCustNumber
    * Description: Gets the custNumber
    * Input: none
    * Output: int/custNumber
    ***************************************************************/
    int getCustNumber();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: printVehicle
    * Description: Gets the rental vehicle data
    * Input: none
    * Output: QString/ all vehicle data
    ***************************************************************/
    QString printVehicle();
};

#endif // RENTALVEHICLE_H
