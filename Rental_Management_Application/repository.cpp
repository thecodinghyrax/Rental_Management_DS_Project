﻿#include "repository.h"


Repository::Repository()
{
    QDir databasePath;
    QString path = "../rentalDB.sqlite";
    const QString DRIVER("QSQLITE");
    if(!QSqlDatabase::isDriverAvailable(DRIVER)) {
        qWarning() << "ERROR: driver not available";
    }
    QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName(path);
    if(!db.open()) {
        qWarning() << "ERROR: " << db.lastError();
    }
    createTables();
}

Repository::~Repository(){

}

QVector<Customer> Repository::getCustomers(){
        QSqlQuery query;
        QVector<Customer> customers;
        query.prepare("SELECT firstName, lastName, address, city, state, zip, phoneNumber, DLNumber, CCNumber, custNumber FROM customers");
        query.exec();

        while(query.next()){
            QString firstName = query.value(0).toString();
            QString lastName = query.value(1).toString();
            QString address = query.value(2).toString();
            QString city = query.value(3).toString();
            QString state = query.value(4).toString();
            QString zip = query.value(5).toString();
            QString phoneNumber = query.value(6).toString();
            QString DLNumber = query.value(7).toString();
            QString CCNumber = query.value(8).toString();
            int custNumber = query.value(9).toInt();
            customers.push_back(Customer(firstName,lastName, address, city, state, zip, phoneNumber, DLNumber, CCNumber, custNumber));
        }

        return customers;
};

Customer Repository::getCustomerById(int id){
    QSqlQuery query;
    query.prepare("SELECT firstName, lastName, address, city, state, zip, phoneNumber, DLNumber, CCNumber, custNumber FROM customers WHERE custNumber = :custNumber");
    query.bindValue(":custNumber", id);
    query.exec();
    query.first();
    QString firstName = query.value(0).toString();
    QString lastName = query.value(1).toString();
    QString address = query.value(2).toString();
    QString city = query.value(3).toString();
    QString state = query.value(4).toString();
    QString zip = query.value(5).toString();
    QString phoneNumber = query.value(6).toString();
    QString DLNumber = query.value(7).toString();
    QString CCNumber = query.value(8).toString();
    int custNumber = query.value(9).toInt();

    Customer temp = Customer(firstName,lastName, address, city, state, zip, phoneNumber, DLNumber, CCNumber, custNumber);
    return temp;
};

void Repository::addCustomer(Customer cust){
    QSqlQuery query;
    query.prepare("INSERT INTO customers(firstName, lastName, address, city, state, zip, phoneNumber, DLNumber, CCNumber, custNumber) VALUES (:firstName, :lastName, :address, :city, :state, :zip, :phoneNumber, :DLNumber, :CCNumber, :custNumber)");
    query.bindValue(":firstName", cust.getFirstName());
    query.bindValue(":lastName", cust.getLastName());
    query.bindValue(":address", cust.getAddress());
    query.bindValue(":city", cust.getCity());
    query.bindValue(":state", cust.getState());
    query.bindValue(":zip", cust.getZip());
    query.bindValue(":phoneNumber", cust.getPhoneNumber());
    query.bindValue(":DLNumber", cust.getDLNumber());
    query.bindValue(":CCNumber", cust.getCCNumber());
    query.bindValue(":custNumber", getNextCustNumber());
    query.exec();
};

void Repository::updateCustomer(Customer cust){
    QSqlQuery query;
    query.prepare("UPDATE customers SET firstName = :firstName, lastName = :lastName, address = :address, city = :city," \
                  "state = :state, zip = :zip, phoneNumber = :phoneNumber, DLNumber = :DLNumber, CCNumber = :CCNumber WHERE custNumber = :custNumber");
    query.bindValue(":firstName", cust.getFirstName());
    query.bindValue(":lastName", cust.getLastName());
    query.bindValue(":address", cust.getAddress());
    query.bindValue(":city", cust.getCity());
    query.bindValue(":state", cust.getState());
    query.bindValue(":zip", cust.getZip());
    query.bindValue(":phoneNumber", cust.getPhoneNumber());
    query.bindValue(":DLNumber", cust.getDLNumber());
    query.bindValue(":CCNumber", cust.getCCNumber());
    query.bindValue(":custNumber", cust.getCustNumber());
    query.exec();

};

void Repository::deleteCustomerById(int id){
    QSqlQuery query;
    query.prepare("DELETE FROM customers WHERE custNumber = :id");
    query.bindValue(":id", id);
    query.exec();
};

int Repository::getNextCustNumber(){
    QSqlQuery query;
    query.exec("SELECT custNumber FROM customers ORDER BY custNumber DESC LIMIT 1");
    query.first();
    return query.value(0).toInt() + 1;
};


QVector<RentalVehicle> Repository::getVehicles(){
    QSqlQuery query;
    QVector<RentalVehicle> vehicles;
    query.prepare("SELECT vehicleNumber, catagory, make, model, year, milage, isRented, custNumber FROM rentalVehicles");
    query.exec();

    while(query.next()){
        int vehicleNumber = query.value(0).toInt();
        QString catagory = query.value(1).toString();
        QString make = query.value(2).toString();
        QString model = query.value(3).toString();
        int year = query.value(4).toInt();
        int milage = query.value(5).toInt();
        bool isRented = query.value(6).toBool();
        int custNumber = query.value(7).toInt();
        vehicles.push_back(RentalVehicle(vehicleNumber, catagory, make, model, year, milage, isRented, custNumber));
    }

    return vehicles;
};

RentalVehicle Repository::getVehicleById(int id){
    QSqlQuery query;
    query.prepare("SELECT vehicleNumber, catagory, make, model, year, milage, isRented, custNumber FROM rentalVehicles WHERE vehicleNumber = :vehicleNumber");
    query.bindValue(":vehicleNumber", id);
    query.exec();
    query.first();
    int vehicleNumber = query.value(0).toInt();
    QString catagory = query.value(1).toString();
    QString make = query.value(2).toString();
    QString model = query.value(3).toString();
    int year = query.value(4).toInt();
    int milage = query.value(5).toInt();
    bool isRented = query.value(6).toBool();
    int custNumber = query.value(7).toInt();

    RentalVehicle temp = RentalVehicle(vehicleNumber, catagory, make, model, year, milage, isRented, custNumber);
    return temp;
};

void Repository::addVehicle(RentalVehicle vehicle){
    QSqlQuery query;
    query.prepare("INSERT INTO rentalVehicles(catagory, make, model, year, milage, isRented, custNumber) VALUES (:catagory, :make, :model, :year, :milage, :isRented, :custNumber)");
    query.bindValue(":catagory", vehicle.getCatagory());
    query.bindValue(":make", vehicle.getMake());
    query.bindValue(":model", vehicle.getModel());
    query.bindValue(":year", vehicle.getYear());
    query.bindValue(":milage", vehicle.getMilage());
    query.bindValue(":isRented", vehicle.getIsRented());
    if(vehicle.getCustNumber() != -1){
        query.bindValue(":custNumber", vehicle.getCustNumber());
    }
    query.exec();
};

void Repository::updateVehicle(RentalVehicle vehicle){
    QSqlQuery query;
    query.prepare("UPDATE rentalVehicles SET catagory = :catagory, make = :make, model = :model," \
                  "year = :year, milage = :milage, isRented = :isRented, custNumber = :custNumber WHERE vehicleNumber = :vehicleNumber");
    query.bindValue(":vehicleNumber", vehicle.getVehicleNumber());
    query.bindValue(":catagory", vehicle.getCatagory());
    query.bindValue(":make", vehicle.getMake());
    query.bindValue(":model", vehicle.getModel());
    query.bindValue(":year", vehicle.getYear());
    query.bindValue(":milage", vehicle.getMilage());
    query.bindValue(":isRented", vehicle.getIsRented());
    query.bindValue(":custNumber", vehicle.getCustNumber());
    query.exec();
};

void Repository::deleteVehicleById(int id){
    QSqlQuery query;
    query.prepare("DELETE FROM rentalVehicles WHERE vehicleNumber = :id");
    query.bindValue(":id", id);
    query.exec();
};

QVector<Transaction> Repository::getTransactions(){
    QSqlQuery query;
    QVector<Transaction> transactions;
    query.prepare("SELECT id, rentalStartDate, rentalEndDate, chargeAmount, vehicleNumber, custNumber FROM transactions");
    query.exec();

    while(query.next()){
        int id = query.value(0).toInt();
        QDateTime rentalStartDate = query.value(1).toDateTime();
        QDateTime rentalEndDate = query.value(2).toDateTime();
        double chargeAmount = query.value(3).toDouble();
        int vehicleNumber = query.value(4).toInt();
        int custNumber = query.value(5).toInt();
        transactions.push_back(Transaction(id, rentalStartDate, rentalEndDate, chargeAmount, vehicleNumber, custNumber));
    }

    return transactions;
};

Transaction Repository::getTransactionById(int transId){
    QSqlQuery query;
    query.prepare("SELECT id, rentalStartDate, rentalEndDate, chargeAmount, vehicleNumber, custNumber FROM transactions WHERE id = :transId");
    query.bindValue(":transId", transId);
    query.exec();
    query.first();
    int id = query.value(0).toInt();
    QDateTime rentalStartDate = query.value(1).toDateTime();
    QDateTime rentalEndDate = query.value(2).toDateTime();
    double chargeAmount = query.value(3).toDouble();
    int vehicleNumber = query.value(4).toInt();
    int custNumber = query.value(5).toInt();

    Transaction temp = Transaction(id, rentalStartDate, rentalEndDate, chargeAmount, vehicleNumber, custNumber);
    return temp;
};

void Repository::addTransaction(Transaction transaction){
    QSqlQuery query;
    query.prepare("INSERT INTO transactions(rentalStartDate, chargeAmount, vehicleNumber, custNumber) VALUES (:rentalStartDate, :chargeAmount, :vehicleNumber, :custNumber)");
    query.bindValue(":rentalStartDate", transaction.getStartDate());
    query.bindValue(":chargeAmount", transaction.getChargeAmount());
    query.bindValue(":vehicleNumber", transaction.getVehicleId());
    query.bindValue(":custNumber", transaction.getCustNumber());
    query.exec();
};

void Repository::updateTransaction(Transaction transaction){
    QSqlQuery query;
    query.prepare("UPDATE transactions SET rentalStartDate = :rentalStartDate, rentalEndDate = :rentalEndDate, chargeAmount = :chargeAmount, vehicleNumber = :vehicleNumber, custNumber = :custNumber WHERE id = :id");
    query.bindValue(":id", transaction.getId());
    query.bindValue(":rentalStartDate", transaction.getStartDate());
    query.bindValue(":rentalEndDate", transaction.getEndDate());
    query.bindValue(":chargeAmount", transaction.getChargeAmount());
    query.bindValue(":vehicleNumber", transaction.getVehicleId());
    query.bindValue(":custNumber", transaction.getCustNumber());
    query.exec();
};

void Repository::deleteTransactionById(int id){
    QSqlQuery query;
    query.prepare("DELETE FROM transactions WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();
};

void Repository::testThings(){
    if(getCustomerById(6).getFirstName() == ""){
            //qCritical() << "Customer 6 was not found";
    }

};

void Repository::createTables(){
    QSqlQuery query;
    query.exec("DROP TABLE IF EXISTS customers");
    query.exec("DROP TABLE IF EXISTS rentalVehicles");
    query.exec("DROP TABLE IF EXISTS transactions");

    query.exec("CREATE TABLE customers(custNumber INTEGER PRIMARY KEY AUTOINCREMENT, firstName TEXT, lastName TEXT, address TEXT, city TEXT, state TEXT, zip TEXT, phoneNumber TEXT, DLNumber TEXT, CCNumber TEXT)");
    query.exec("CREATE TABLE rentalVehicles(vehicleNumber INTEGER PRIMARY KEY AUTOINCREMENT, catagory TEXT, make TEXT, model TEXT, year INTEGER, milage INTEGER, isRented INTEGER, custNumber INTEGER, FOREIGN KEY (custNumber) REFERENCES customers (custNumber))");
    query.exec("CREATE TABLE transactions(id INTEGER PRIMARY KEY AUTOINCREMENT, rentalStartDate DATETIME, rentalEndDate DATETIME, chargeAmount REAL, vehicleNumber INTEGER, custNumber INTEGER, FOREIGN KEY (vehicleNumber) REFERENCES rentalVehicles (vehicleNumber), FOREIGN KEY (custNumber) REFERENCES customers (custNumber))");

    addCustomer(Customer("Drew", "Crawford", "1234 SW Round Circle", "My Town", "Iowa", "78945", "123-456-7891", "1234PP7894", "1234569812345214"));
    addCustomer(Customer("Cathy", "Crawford", "1234 SW Round Circle", "My Town", "Iowa", "78945", "123-999-7891", "9999ML7894", "9999569812341111"));
    addCustomer(Customer("Larry", "Layabout", "3 Main", "Sun City", "MO", "56478", "111-111-1191", "1111FG1111", "7654324152637283"));
    addCustomer(Customer("Tom", "Thompson", "Lost Ln", "Overton", "CA", "01278", "999-888-7777", "9874AA1234", "9999999999999999"));
    addCustomer(Customer("Tony", "Peterson", "124 6th Ave", "Leadville", "CO", "78922", "222-478-3211", "555RT5555", "5555555555555559"));
    Customer tempCust = getCustomerById(5);
    tempCust.setLastName("Bologna");
    updateCustomer(tempCust);
    deleteCustomerById(4);
    addCustomer(Customer("Tom", "Thompson", "Lost Ln", "Overton", "CA", "01278", "999-888-7777", "9874AA1234", "9999999999999999"));

    addVehicle(RentalVehicle("premium", "Lexus", "400", 2023, 23, 0));
    addVehicle(RentalVehicle("compact", "Focus", "Focus", 2021, 8892, 0));
    addVehicle(RentalVehicle("compact", "Ford", "Focus", 2022, 192, 0));
    addVehicle(RentalVehicle("compact", "Ford", "Focus", 2018, 218892, 0));
    addVehicle(RentalVehicle("economy", "Ford", "Fiesta", 2020, 78922, 1, 5));
    addVehicle(RentalVehicle("standard", "Ford", "Fusion", 2020, 58892, 0));
    RentalVehicle tempVehicle = getVehicleById(6);
    tempVehicle.setMilage(tempVehicle.getMilage() + 1000);
    tempVehicle.setIsRented(true);
    tempVehicle.setCustNumber(1);
    updateVehicle(tempVehicle);
    deleteVehicleById(4);
    addVehicle(RentalVehicle("compact", "Ford", "Focus", 2018, 218892, 0));

    QDateTime current = QDateTime::currentDateTime();
    addTransaction(Transaction(current, 99.99, 1, 3));
    addTransaction(Transaction(current, 101.99, 2, 2));
    addTransaction(Transaction(current, 71.90, 5, 1));
    Transaction tempTrans = getTransactionById(3);
    QDateTime end;
    end = current.addDays(2);
    tempTrans.setEndDate(end);
    updateTransaction(tempTrans);
    deleteTransactionById(1);
    addTransaction(Transaction(current, 99.99, 1, 3));
};
