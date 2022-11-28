#include "repository.h"



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
    createCustomerTable();
}

Repository::~Repository(){

}

QVector<Customer> Repository::getCustomers(){
        QSqlQuery query;
        QVector<Customer> customers;
        query.prepare("SELECT firstName, lastName, address, city, state, zip, phoneNumber, DLNumber, CCNumber, custNumber FROM Customers");
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
    query.prepare("SELECT firstName, lastName, address, city, state, zip, phoneNumber, DLNumber, CCNumber, custNumber FROM Customers WHERE custNumber = :custNumber");
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

QString Repository::addCustomer(Customer cust){
    QSqlQuery query;
    query.prepare("INSERT INTO Customers(firstName, lastName, address, city, state, zip, phoneNumber, DLNumber, CCNumber, custNumber) VALUES (:firstName, :lastName, :address, :city, :state, :zip, :phoneNumber, :DLNumber, :CCNumber, :custNumber)");
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
    return "";
};
void Repository::updateCustomer(Customer cust){
    QSqlQuery query;
    query.prepare("UPDATE Customers SET firstName = :firstName, lastName = :lastName, address = :address, city = :city," \
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
    query.prepare("DELETE FROM Customers WHERE custNumber = :id");
    query.bindValue(":id", id);
    query.exec();
};

int Repository::getNextCustNumber(){
    QSqlQuery query;
    query.exec("SELECT custNumber FROM Customers ORDER BY custNumber DESC LIMIT 1");
    query.first();
    return query.value(0).toInt() + 1;
};

void Repository::testThings(){
    if(getCustomerById(6).getFirstName() == ""){
            //qCritical() << "Customer 6 was not found";
    }

};

void Repository::createCustomerTable(){
    QSqlQuery query;
    query.exec("DROP TABLE IF EXISTS customers");
    query.exec("DROP TABLE IF EXISTS rentalVehicles");
    query.exec("CREATE TABLE Customers(firstName TEXT, lastName TEXT, address TEXT, city TEXT, state TEXT, zip TEXT, phoneNumber TEXT, DLNumber TEXT, CCNumber TEXT, custNumber INT PRIMARY KEY)");
    query.exec("CREATE TABLE rentalVehicles(id INT PRIMARY KEY, catagory TEXT, make TEXT, model TEXT, year INT, milage INT, isRented INT, custNumber INT, FOREIGN KEY (custNumber) REFERENCES customers (custNumber))");
    QSqlQuery insert1;
    insert1.prepare("INSERT INTO Customers(firstName, lastName, address, city, state, zip, phoneNumber, DLNumber, CCNumber, custNumber) VALUES (:firstName, :lastName, :address, :city, :state, :zip, :phoneNumber, :DLNumber, :CCNumber, :custNumber)");
    insert1.bindValue(":firstName", "Drew");
    insert1.bindValue(":lastName", "Crawford");
    insert1.bindValue(":address", "1234 SW Round Circle");
    insert1.bindValue(":city", "My Town");
    insert1.bindValue(":state", "Iowa");
    insert1.bindValue(":zip", "78945");
    insert1.bindValue(":phoneNumber", "123-456-7891");
    insert1.bindValue(":DLNumber", "1234PP7894");
    insert1.bindValue(":CCNumber", "1234569812345214");
    insert1.bindValue(":custNumber", 1);
    insert1.exec();
//    QSqlQuery insert2;
//    insert2.prepare("INSERT INTO Customers(firstName, lastName, address, city, state, zip, phoneNumber, DLNumber, CCNumber, custNumber) VALUES (:firstName, :lastName, :address, :city, :state, :zip, :phoneNumber, :DLNumber, :CCNumber, :custNumber)");
    insert1.bindValue(":firstName", "Cathy");
    insert1.bindValue(":lastName", "Crawford");
    insert1.bindValue(":address", "1234 SW Round Circle");
    insert1.bindValue(":city", "My Town");
    insert1.bindValue(":state", "Iowa");
    insert1.bindValue(":zip", "78945");
    insert1.bindValue(":phoneNumber", "123-999-7891");
    insert1.bindValue(":DLNumber", "9999ML7894");
    insert1.bindValue(":CCNumber", "9999569812341111");
    insert1.bindValue(":custNumber", 2);
    insert1.exec();
//    QSqlQuery insert3;
//    insert3.prepare("INSERT INTO Customers(firstName, lastName, address, city, state, zip, phoneNumber, DLNumber, CCNumber, custNumber) VALUES (:firstName, :lastName, :address, :city, :state, :zip, :phoneNumber, :DLNumber, :CCNumber, :custNumber)");
    insert1.bindValue(":firstName", "Larry");
    insert1.bindValue(":lastName", "Layabout");
    insert1.bindValue(":address", "3 Main");
    insert1.bindValue(":city", "Sun City");
    insert1.bindValue(":state", "MO");
    insert1.bindValue(":zip", "56478");
    insert1.bindValue(":phoneNumber", "111-111-1191");
    insert1.bindValue(":DLNumber", "1111FG1111");
    insert1.bindValue(":CCNumber", "7654324152637283");
    insert1.bindValue(":custNumber", 3);
    insert1.exec();
//    QSqlQuery insert4;
//    insert4.prepare("INSERT INTO Customers(firstName, lastName, address, city, state, zip, phoneNumber, DLNumber, CCNumber, custNumber) VALUES (:firstName, :lastName, :address, :city, :state, :zip, :phoneNumber, :DLNumber, :CCNumber, :custNumber)");
    insert1.bindValue(":firstName", "Tom");
    insert1.bindValue(":lastName", "Thompson");
    insert1.bindValue(":address", "Lost Ln");
    insert1.bindValue(":city", "Overton");
    insert1.bindValue(":state", "CA");
    insert1.bindValue(":zip", "01278");
    insert1.bindValue(":phoneNumber", "999-888-7777");
    insert1.bindValue(":DLNumber", "9874AA1234");
    insert1.bindValue(":CCNumber", "9999999999999999");
    insert1.bindValue(":custNumber", 4);
    insert1.exec();
//    QSqlQuery insert5;
//    insert5.prepare("INSERT INTO Customers(firstName, lastName, address, city, state, zip, phoneNumber, DLNumber, CCNumber, custNumber) VALUES (:firstName, :lastName, :address, :city, :state, :zip, :phoneNumber, :DLNumber, :CCNumber, :custNumber)");
    insert1.bindValue(":firstName", "Tony");
    insert1.bindValue(":lastName", "Peterson");
    insert1.bindValue(":address", "114 6th Ave");
    insert1.bindValue(":city", "Leadville");
    insert1.bindValue(":state", "CO");
    insert1.bindValue(":zip", "78922");
    insert1.bindValue(":phoneNumber", "222-478-3211");
    insert1.bindValue(":DLNumber", "555RT5555");
    insert1.bindValue(":CCNumber", "5555555555555559");
    insert1.bindValue(":custNumber", 5);
    insert1.exec();
    QSqlQuery insert2;
    insert2.prepare("INSERT INTO rentalVehicles(id, catagory, make, model, year, milage, isRented, custNumber) VALUES (:id, :catagory, :make, :model, :year, :milage, :isRented, :custNumber)");
    insert2.bindValue(":id", 1);
    insert2.bindValue(":catagory", "economy");
    insert2.bindValue(":make", "Ford");
    insert2.bindValue(":model", "Fiesta");
    insert2.bindValue(":year", 2020);
    insert2.bindValue(":milage", 78922);
    insert2.bindValue(":isRented", 1);
    insert2.bindValue(":custNumber", 5);
    insert2.exec();
    insert2.bindValue(":id", 2);
    insert2.bindValue(":catagory", "compact");
    insert2.bindValue(":make", "Ford");
    insert2.bindValue(":model", "Focus");
    insert2.bindValue(":year", 2021);
    insert2.bindValue(":milage", 8892);
    insert2.bindValue(":isRented", 0);
    insert2.bindValue(":custNumber", NULL);
    insert2.exec();
    insert2.bindValue(":id", 3);
    insert2.bindValue(":catagory", "compact");
    insert2.bindValue(":make", "Ford");
    insert2.bindValue(":model", "Focus");
    insert2.bindValue(":year", 2022);
    insert2.bindValue(":milage", 192);
    insert2.bindValue(":isRented", 0);
    insert2.bindValue(":custNumber", NULL);
    insert2.exec();
    insert2.bindValue(":id", 4);
    insert2.bindValue(":catagory", "compact");
    insert2.bindValue(":make", "Ford");
    insert2.bindValue(":model", "Focus");
    insert2.bindValue(":year", 2018);
    insert2.bindValue(":milage", 218892);
    insert2.bindValue(":isRented", 0);
    insert2.bindValue(":custNumber", NULL);
    insert2.exec();
    insert2.bindValue(":id", 5);
    insert2.bindValue(":catagory", "standard");
    insert2.bindValue(":make", "Ford");
    insert2.bindValue(":model", "Fusion");
    insert2.bindValue(":year", 2020);
    insert2.bindValue(":milage", 58892);
    insert2.bindValue(":isRented", 0);
    insert2.bindValue(":custNumber", NULL);
    insert2.exec();

//    query.exec("CREATE TABLE rentalVehicles(id INT PRIMARY KEY, catagory TEXT, make TEXT, model TEXT, year INT, milage INT, isRented INT, custNumber INT, FOREIGN KEY (custNumber) REFERENCES customers (custNumber)");
};
