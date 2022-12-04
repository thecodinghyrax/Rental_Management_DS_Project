#include "repository.h"


Repository::Repository(QMap<int, QVector<Transaction>>& map)
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
    setDefaultRentalPrices();
    updateCustTransMap(map);
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

QVector<RentalVehicle> Repository::getRentedVehicles(){
    QSqlQuery query;
    QVector<RentalVehicle> rentedVehicles;
    query.prepare("SELECT vehicleNumber, catagory, make, model, year, milage, isRented, custNumber FROM rentalVehicles WHERE isRented = 1");
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
        rentedVehicles.push_back(RentalVehicle(vehicleNumber, catagory, make, model, year, milage, isRented, custNumber));
    }
    return rentedVehicles;
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

int Repository::getAvailableVehicleIdByCatagory(QString catagory){
    QSqlQuery query;
    query.prepare("SELECT vehicleNumber, catagory FROM rentalVehicles WHERE catagory = :catagory AND isRented = 0 ORDER BY year DESC LIMIT 1");
    query.bindValue(":catagory", catagory);
    query.exec();
    query.first();
    if(query.value(0).toString() == ""){
        return -1;
    } else {
        return query.value(0).toInt();
    }
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
    if(vehicle.getCustNumber() != -1){
        query.bindValue(":custNumber", vehicle.getCustNumber());
    }

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
    query.prepare("SELECT id, rentalStartDate, rentalEndDate, chargeAmount, numberOfDays, vehicleNumber, custNumber, returnNote FROM transactions");
    query.exec();

    while(query.next()){
        int id = query.value(0).toInt();
        QDateTime rentalStartDate = query.value(1).toDateTime();
        QDateTime rentalEndDate = query.value(2).toDateTime();
        double chargeAmount = query.value(3).toDouble();
        int numberOfDays = query.value(4).toInt();
        int vehicleNumber = query.value(5).toInt();
        int custNumber = query.value(6).toInt();
        QString returnNote = query.value(7).toString();
        transactions.push_back(Transaction(id, rentalStartDate, rentalEndDate, chargeAmount, numberOfDays, vehicleNumber, custNumber, returnNote));
    }

    return transactions;
};

QVector<Transaction> Repository::getTransactionsByCustId(int custId){
    QSqlQuery query;
    QVector<Transaction> transactions;
    query.prepare("SELECT id, rentalStartDate, rentalEndDate, chargeAmount, numberOfDays, vehicleNumber, custNumber, returnNote FROM transactions WHERE custNumber = :id");
    query.bindValue(":id", custId);
    query.exec();

    while(query.next()){
        int id = query.value(0).toInt();
        QDateTime rentalStartDate = query.value(1).toDateTime();
        QDateTime rentalEndDate = query.value(2).toDateTime();
        double chargeAmount = query.value(3).toDouble();
        int numberOfDays = query.value(4).toInt();
        int vehicleNumber = query.value(5).toInt();
        int custNumber = query.value(6).toInt();
        QString returnNote = query.value(7).toString();
        transactions.push_back(Transaction(id, rentalStartDate, rentalEndDate, chargeAmount, numberOfDays, vehicleNumber, custNumber, returnNote));
    }

    return transactions;
};

QVector<Transaction> Repository::getCompletedTransactionsByCustId(int custId){
    QSqlQuery query;
    QVector<Transaction> transactions;
    query.prepare("SELECT id, rentalStartDate, rentalEndDate, chargeAmount, numberOfDays, vehicleNumber, custNumber, returnNote FROM transactions WHERE custNumber = :id AND rentalEndDate NOT NULL");
    query.bindValue(":id", custId);
    query.exec();

    while(query.next()){
        int id = query.value(0).toInt();
        QDateTime rentalStartDate = query.value(1).toDateTime();
        QDateTime rentalEndDate = query.value(2).toDateTime();
        double chargeAmount = query.value(3).toDouble();
        int numberOfDays = query.value(4).toInt();
        int vehicleNumber = query.value(5).toInt();
        int custNumber = query.value(6).toInt();
        QString returnNote = query.value(7).toString();
        transactions.push_back(Transaction(id, rentalStartDate, rentalEndDate, chargeAmount, numberOfDays, vehicleNumber, custNumber, returnNote));
    }

    return transactions;
};

Transaction Repository::getTransactionById(int transId){
    QSqlQuery query;
    query.prepare("SELECT id, rentalStartDate, rentalEndDate, chargeAmount, numberOfDays, vehicleNumber, custNumber, returnNote FROM transactions WHERE id = :transId");
    query.bindValue(":transId", transId);
    query.exec();
    query.first();
    int id = query.value(0).toInt();
    QDateTime rentalStartDate = query.value(1).toDateTime();
    QDateTime rentalEndDate = query.value(2).toDateTime();
    double chargeAmount = query.value(3).toDouble();
    int numberOfDays = query.value(4).toInt();
    int vehicleNumber = query.value(5).toInt();
    int custNumber = query.value(6).toInt();
    QString returnNote = query.value(7).toString();
    Transaction temp = Transaction(id, rentalStartDate, rentalEndDate, chargeAmount, numberOfDays, vehicleNumber, custNumber, returnNote);
    return temp;
};

Transaction Repository::getTransactionByRentedVehicleId(int vehicleId){
    QSqlQuery query;
    query.prepare("SELECT id, rentalStartDate, rentalEndDate, chargeAmount, numberOfDays, vehicleNumber, custNumber, returnNote FROM transactions WHERE vehicleNumber = :vehicleNumber");
    query.bindValue(":vehicleNumber", vehicleId);
    query.exec();
    query.last();
    int id = query.value(0).toInt();
    QDateTime rentalStartDate = query.value(1).toDateTime();
    QDateTime rentalEndDate = query.value(2).toDateTime();
    double chargeAmount = query.value(3).toDouble();
    int numberOfDays = query.value(4).toInt();
    int vehicleNumber = query.value(5).toInt();
    int custNumber = query.value(6).toInt();
    QString returnNote = query.value(7).toString();
    Transaction temp = Transaction(id, rentalStartDate, rentalEndDate, chargeAmount, numberOfDays, vehicleNumber, custNumber, returnNote);
    return temp;
};

void Repository::addTransaction(Transaction transaction){
    QSqlQuery query;
    query.prepare("INSERT INTO transactions(rentalStartDate, chargeAmount, numberOfDays, vehicleNumber, custNumber) VALUES (:rentalStartDate, :chargeAmount, :numberOfDays, :vehicleNumber, :custNumber)");
    query.bindValue(":rentalStartDate", transaction.getStartDate());
    query.bindValue(":chargeAmount", transaction.getChargeAmount());
    query.bindValue(":numberOfDays", transaction.getNumberOfDays());
    query.bindValue(":vehicleNumber", transaction.getVehicleId());
    query.bindValue(":custNumber", transaction.getCustNumber());
    query.exec();
};

void Repository::updateTransaction(Transaction transaction){
    QSqlQuery query;
    query.prepare("UPDATE transactions SET rentalStartDate = :rentalStartDate, rentalEndDate = :rentalEndDate, chargeAmount = :chargeAmount, numberOfDays = :numberOfDays, vehicleNumber = :vehicleNumber, custNumber = :custNumber, returnNote = :returnNote WHERE id = :id");
    query.bindValue(":id", transaction.getId());
    query.bindValue(":rentalStartDate", transaction.getStartDate());
    query.bindValue(":rentalEndDate", transaction.getEndDate());
    query.bindValue(":chargeAmount", transaction.getChargeAmount());
    query.bindValue(":numberOfDays", transaction.getNumberOfDays());
    query.bindValue(":vehicleNumber", transaction.getVehicleId());
    query.bindValue(":custNumber", transaction.getCustNumber());
    query.bindValue(":returnNote", transaction.getReturnNote());
    query.exec();

};

void Repository::deleteTransactionById(int id){
    QSqlQuery query;
    query.prepare("DELETE FROM transactions WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();
};

void Repository::setRentalPrice(QString catagory, double price){
    rentalPrices.insert(catagory, price);
};
void Repository::setDefaultRentalPrices(){
    rentalPrices.insert("economy", 20.);
    rentalPrices.insert("compact", 25.5);
    rentalPrices.insert("standard", 31.4);
    rentalPrices.insert("premium", 40.0);
};
void Repository::updateRentalPrice(QString catagory, double price){
    rentalPrices.value(catagory, price);
}
double Repository::getRentalPrice(QString catagory){
    return rentalPrices.value(catagory);
};


void Repository::getHistoryModel(QSqlQueryModel *model){
    QSqlQuery query;
    query.prepare("SELECT rentalStartDate, rentalEndDate, numberOfDays, chargeAmount, vehicleNumber, custNumber, returnNote FROM Transactions WHERE rentalEndDate NOT NULL");
    query.exec();
    model->setQuery(std::move(query));
}

void Repository::sortTransactionByDate(QVector<Transaction>& transactions){// From Inventory class deleted commit
        // Insersion sort
        Transaction temp;
        int earliestDateIndex = 0;
        int currentIndex = 0;
        while(currentIndex < transactions.size()){
            //searching unsorted section for earliest date
            for(int i = currentIndex; i < transactions.size(); ++ i){
                if(transactions[i].getEndDate() < transactions[earliestDateIndex].getEndDate()){
                    earliestDateIndex = i;
                }
            }
            // Swapping current index with earilest
            if(currentIndex != earliestDateIndex){
                temp = transactions[earliestDateIndex];
                transactions[earliestDateIndex] = transactions[currentIndex];
                transactions[currentIndex] = temp;
            }

            currentIndex++;
            earliestDateIndex = currentIndex;
        }
};

void Repository::updateCustTransMap(QMap<int, QVector<Transaction>>& map){
    map.clear();
    for(auto cust : getCustomers()){
        QVector<Transaction> trans = getCompletedTransactionsByCustId(cust.getCustNumber());
        sortTransactionByDate(trans);
        map.insert(cust.getCustNumber(), trans);
    }
};


// Create testing data in db
void Repository::createTables(){
    QSqlQuery query;
    query.exec("DROP TABLE IF EXISTS customers");
    query.exec("DROP TABLE IF EXISTS rentalVehicles");
    query.exec("DROP TABLE IF EXISTS transactions");

    query.exec("CREATE TABLE customers(custNumber INTEGER PRIMARY KEY AUTOINCREMENT, firstName TEXT, lastName TEXT, address TEXT, city TEXT, state TEXT, zip TEXT, phoneNumber TEXT, DLNumber TEXT, CCNumber TEXT)");
    query.exec("CREATE TABLE rentalVehicles(vehicleNumber INTEGER PRIMARY KEY AUTOINCREMENT, catagory TEXT, make TEXT, model TEXT, year INTEGER, milage INTEGER, isRented INTEGER, custNumber INTEGER, FOREIGN KEY (custNumber) REFERENCES customers (custNumber))");
    query.exec("CREATE TABLE transactions(id INTEGER PRIMARY KEY AUTOINCREMENT, rentalStartDate DATETIME, rentalEndDate DATETIME, chargeAmount REAL, numberOfDays INTEGER, vehicleNumber INTEGER, custNumber INTEGER, returnNote TEXT, FOREIGN KEY (vehicleNumber) REFERENCES rentalVehicles (vehicleNumber), FOREIGN KEY (custNumber) REFERENCES customers (custNumber))");

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


    addVehicle(RentalVehicle("premium", "Lexus", "400", 2023, 23, 1, 3));// vehicle 1
    addVehicle(RentalVehicle("compact", "Focus", "Focus", 2021, 8892, 0));// vehicle 2
    addVehicle(RentalVehicle("compact", "Ford", "Focus", 2022, 192, 0));// vehicle 3
    addVehicle(RentalVehicle("compact", "Ford", "Focus", 2018, 218892, 0));// will change
    addVehicle(RentalVehicle("economy", "Ford", "Fiesta", 2020, 78922, 1, 1));// vehicle 5
    addVehicle(RentalVehicle("standard", "Ford", "Fusion", 2020, 58892, 1, 4));// vehicle 6

    RentalVehicle tempVehicle = getVehicleById(6);
    tempVehicle.setMilage(tempVehicle.getMilage() + 1000);
    tempVehicle.setIsRented(true);
    tempVehicle.setCustNumber(2);
    updateVehicle(tempVehicle);

    deleteVehicleById(4);

    addVehicle(RentalVehicle("compact", "Ford", "Focus", 2018, 218892, 0));// vehicle 7


    QDateTime current = QDateTime::currentDateTime();
    addTransaction(Transaction(current, 157.00, 3, 6, 3));
    addTransaction(Transaction(current, 200.00, 5, 1, 3));// Trans 2
    addTransaction(Transaction(current, 102.00, 4, 2, 2));// Trans 3
    addTransaction(Transaction(current, 100.00, 5, 5, 1));// Trans 4

    Transaction tempTrans = getTransactionById(3);
    QDateTime end;
    end = current.addDays(4);
    tempTrans.setEndDate(end);
    tempTrans.setReturnNote("No damage. Clean. Full tank");
    updateTransaction(tempTrans);

    deleteTransactionById(1);

    addTransaction(Transaction(current, 99.99, 5, 6, 2));// Trans 4
};
