#include "repository.h"



Repository::Repository()
{
    QDir databasePath;
    //QString path = databasePath.currentPath()+"/rentalDB.sqlite";
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
    qCritical() << temp.getFirstName();
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
    qCritical() << cust.getFirstName();
    qCritical() << cust.getLastName();
    qCritical() << cust.getAddress();
    qCritical() << cust.getCity();
    qCritical() << cust.getState();
    qCritical() << cust.getZip();
    qCritical() << cust.getPhoneNumber();
    qCritical() << cust.getDLNumber();
    qCritical() << cust.getCCNumber();
    qCritical() << cust.getCustNumber();
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
int Repository::getNextCustNumber(){
    QSqlQuery query;
    query.prepare("SELECT custNumber FROM Customers ORDER BY custNumber ASC LIMIT 1");
    qCritical() << query.value(0).toInt() + 1;
    return query.value(0).toInt() + 1;
};

void Repository::testThings(){
    if(getCustomerById(6).getFirstName() == ""){
            qCritical() << "Customer 6 was not found";
    }

};

void Repository::createCustomerTable(){
    QSqlQuery query;
    query.exec("DROP TABLE IF EXISTS customers");
    query.exec("CREATE TABLE Customers(firstName TEXT, lastName TEXT, address TEXT, city TEXT, state TEXT, zip TEXT, phoneNumber TEXT, DLNumber TEXT, CCNumber TEXT, custNumber INT PRIMARY KEY)");
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
    QSqlQuery insert2;
    insert2.prepare("INSERT INTO Customers(firstName, lastName, address, city, state, zip, phoneNumber, DLNumber, CCNumber, custNumber) VALUES (:firstName, :lastName, :address, :city, :state, :zip, :phoneNumber, :DLNumber, :CCNumber, :custNumber)");
    insert2.bindValue(":firstName", "Cathy");
    insert2.bindValue(":lastName", "Crawford");
    insert2.bindValue(":address", "1234 SW Round Circle");
    insert2.bindValue(":city", "My Town");
    insert2.bindValue(":state", "Iowa");
    insert2.bindValue(":zip", "78945");
    insert2.bindValue(":phoneNumber", "123-999-7891");
    insert2.bindValue(":DLNumber", "9999ML7894");
    insert2.bindValue(":CCNumber", "9999569812341111");
    insert2.bindValue(":custNumber", 2);
    insert2.exec();
    QSqlQuery insert3;
    insert3.prepare("INSERT INTO Customers(firstName, lastName, address, city, state, zip, phoneNumber, DLNumber, CCNumber, custNumber) VALUES (:firstName, :lastName, :address, :city, :state, :zip, :phoneNumber, :DLNumber, :CCNumber, :custNumber)");
    insert3.bindValue(":firstName", "Larry");
    insert3.bindValue(":lastName", "Layabout");
    insert3.bindValue(":address", "3 Main");
    insert3.bindValue(":city", "Sun City");
    insert3.bindValue(":state", "MO");
    insert3.bindValue(":zip", "56478");
    insert3.bindValue(":phoneNumber", "111-111-1191");
    insert3.bindValue(":DLNumber", "1111FG1111");
    insert3.bindValue(":CCNumber", "7654324152637283");
    insert3.bindValue(":custNumber", 3);
    insert3.exec();
    QSqlQuery insert4;
    insert4.prepare("INSERT INTO Customers(firstName, lastName, address, city, state, zip, phoneNumber, DLNumber, CCNumber, custNumber) VALUES (:firstName, :lastName, :address, :city, :state, :zip, :phoneNumber, :DLNumber, :CCNumber, :custNumber)");
    insert4.bindValue(":firstName", "Tom");
    insert4.bindValue(":lastName", "Thompson");
    insert4.bindValue(":address", "Lost Ln");
    insert4.bindValue(":city", "Overton");
    insert4.bindValue(":state", "CA");
    insert4.bindValue(":zip", "01278");
    insert4.bindValue(":phoneNumber", "999-888-7777");
    insert4.bindValue(":DLNumber", "9874AA1234");
    insert4.bindValue(":CCNumber", "9999999999999999");
    insert4.bindValue(":custNumber", 4);
    insert4.exec();
    QSqlQuery insert5;
    insert5.prepare("INSERT INTO Customers(firstName, lastName, address, city, state, zip, phoneNumber, DLNumber, CCNumber, custNumber) VALUES (:firstName, :lastName, :address, :city, :state, :zip, :phoneNumber, :DLNumber, :CCNumber, :custNumber)");
    insert5.bindValue(":firstName", "Tony");
    insert5.bindValue(":lastName", "Peterson");
    insert5.bindValue(":address", "114 6th Ave");
    insert5.bindValue(":city", "Leadville");
    insert5.bindValue(":state", "CO");
    insert5.bindValue(":zip", "78922");
    insert5.bindValue(":phoneNumber", "222-478-3211");
    insert5.bindValue(":DLNumber", "555RT5555");
    insert5.bindValue(":CCNumber", "5555555555555559");
    insert5.bindValue(":custNumber", 5);
    insert5.exec();
};
