#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clearAllInput();

    QMessageBox box;
//   if(!loadCustomers()){
//       box.setWindowTitle("Error");
//       box.setText("Customers file could not be loaded!");
//       box.exec();
//   }
   repo.testThings();

//   if(!loadVehicles()){
//       box.setWindowTitle("Error");
//       box.setText("Vehicles file could not be loaded!");
//       box.exec();
//   }
   /*
Note on file finding issues:
Your current working folder is set by Qt Creator. Go to Projects >> Your selected build >> Press the 'Run' button (next to 'Build) and you will see what it is on this page which of course you can change as well.
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

Customer MainWindow::getCustById(int id){
    for(auto& customer : customers){
        if(customer.getCustNumber() == id){
            return customer;
        }
    }
    return Customer();
};

bool MainWindow::validate(QString userInput, QString msg, int minLength, int maxLength){
    ui->validateLable->setText("");
    if(userInput.length() < minLength || userInput.length() > maxLength){
        ui->validateLable->setText(msg + " must be bwtween " +
                                   QString::number(minLength) + " and " +
                                   QString::number(maxLength));
        return false;
    } else {
        ui->validateLable->setText("");
        return true;
    }
}

//bool MainWindow::loadCustomers(){
//    QFile file("customers.txt");
//    if(!file.open(QIODevice::ReadOnly)){
//        return false;
//    }

//    QTextStream in(&file);
//    int count = 0;
//    Customer tempCust;
//    QString line;

//    while(!in.atEnd()){
//        line = in.readLine();
//        if(line == "+++"){
//            count = 0;
//            tempCust.setCustNumber();
//            customers.push_back(tempCust);
//            line = in.readLine();
//        }

//        switch(count){
//        case 0:
//            tempCust.setFirstName(line);
//            break;
//        case 1:
//            tempCust.setLastName(line);
//            break;
//        case 2:
//            tempCust.setAddress(line);
//            break;
//        case 3:
//            tempCust.setCity(line);
//            break;
//        case 4:
//            tempCust.setState(line);
//            break;
//        case 5:
//            tempCust.setZip(line);
//            break;
//        case 6:
//            tempCust.setPhoneNumber(line);
//            break;
//        case 7:
//            tempCust.setDLNumber(line);
//            break;
//        case 8:
//            tempCust.setCCNumber(line);
//            break;
//        default:
//            file.close();
//            return false;
//            break;
//        }
//        count++;
//    }

//    file.close();
//    return true;
//};


bool MainWindow::saveCustomers()
{
    QFile file("customers.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        return false;
    }

    QTextStream stream(&file);

    for(auto& customer : customers){
        stream << customer.getFirstName() << "\n";
        stream << customer.getLastName() << "\n";
        stream << customer.getAddress() << "\n";
        stream << customer.getCity() << "\n";
        stream << customer.getState() << "\n";
        stream << customer.getZip() << "\n";
        stream << customer.getPhoneNumber() << "\n";
        stream << customer.getDLNumber() << "\n";
        stream << customer.getCCNumber() << "\n";
        stream << "+++\n";
    }
    file.close();
    return true;
}

bool MainWindow::loadInventory(){
    //TODO
    return true;
}

bool MainWindow::saveInventory()
{
    //TODO
    return true;
};

bool MainWindow::loadTransactions(){
    //TODO
    return true;
}

bool MainWindow::saveTransactions(){
    //TODO
    return true;
}

// Navigation
void MainWindow::on_welcomeNavBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_addCustomerNavBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->editCustSubmitBtn->hide();
    ui->addCustSubmitBtn->show();
}


void MainWindow::on_rentNavBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_returnNavBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::on_returnQueueNavBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_viewTransactionsNavBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


// Customer form

void MainWindow::on_firstNameInput_textChanged(const QString &arg1)
{
    validate(arg1, "First Name", 2, 20);
}


void MainWindow::on_lastNameInput_textChanged(const QString &arg1)
{
    validate(arg1, "Last Name", 2, 20);
}


void MainWindow::on_addressInput_textChanged(const QString &arg1)
{
    validate(arg1, "Address", 6, 30);
}


void MainWindow::on_cityInput_textChanged(const QString &arg1)
{
    validate(arg1, "City", 2, 25);
}


void MainWindow::on_stateInput_textChanged(const QString &arg1)
{
    validate(arg1, "State", 2, 12);
}


void MainWindow::on_zipInput_textChanged(const QString &arg1)
{
    validate(arg1, "Zip Code", 5, 10);
}


void MainWindow::on_phoneNumberInput_textChanged(const QString &arg1)
{
    validate(arg1, "Phone Number", 7, 31);
}


void MainWindow::on_DLInput_textChanged(const QString &arg1)
{
    validate(arg1, "Drivers license number", 9, 11);
}


void MainWindow::on_CCInput_textChanged(const QString &arg1)
{
    validate(arg1, "Credit card number ", 16, 19);
}


void MainWindow::on_addCustSubmitBtn_clicked()
{
    QString first = ui->firstNameInput->text();
    if(ui->validateLable->text().length() == 0 && first.length() != 0){
        customers.push_back(Customer(
                                ui->firstNameInput->text(),
                                ui->lastNameInput->text(),
                                ui->addressInput->text(),
                                ui->cityInput->text(),
                                ui->stateInput->text(),
                                ui->zipInput->text(),
                                ui->phoneNumberInput->text(),
                                ui->DLInput->text(),
                                ui->CCInput->text(),
                                repo.getNextCustNumber()
                                ));

        clearAllInput();
        ui->validateLable->setText(first + " has been added!");
    }

}


void MainWindow::on_loadCustList_clicked()
{
    ui->listWidget->clear();
    for(auto customer : repo.getCustomers()){
        ui->listWidget->addItem(new QListWidgetItem(QString::number(customer.getCustNumber()) + " " +
                                                    customer.getFirstName() + " " +
                                                    customer.getLastName()
                                                    ));
        }
}


void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    ui->addCustSubmitBtn->hide();
    ui->editCustSubmitBtn->show();
    ui->deleteCustSubmitBtn->show();
    QString cust = item->text();
    int custNumber = cust.split(" ").at(0).toInt();
    if(custNumber > -1){
        Customer temp = repo.getCustomerById(custNumber);
        ui->firstNameInput->setText(temp.getFirstName());
        ui->lastNameInput->setText(temp.getLastName());
        ui->addressInput->setText(temp.getAddress());
        ui->cityInput->setText(temp.getCity());
        ui->stateInput->setText(temp.getState());
        ui->zipInput->setText(temp.getZip());
        ui->phoneNumberInput->setText(temp.getPhoneNumber());
        ui->DLInput->setText(temp.getDLNumber());
        ui->CCInput->setText(temp.getCCNumber());
        ui->custNumberLabel->setText(QString::number(temp.getCustNumber()));
        ui->listWidget->clear();
    }
}

int MainWindow::getCustomerIndexById(int id){
    for(int i = 0; i < customers.size(); ++i){
        if(customers[i].getCustNumber() == id){
            return i;
        }
    }
    return -1;
};


void MainWindow::on_editCustSubmitBtn_clicked()
{
    if(ui->validateLable->text().length() < 1){

        //int custNumber = ui->custNumberLabel->text().toInt();
//        for(int i = 0; i < customers.size(); ++i){
//            if(customers[i].getCustNumber() == custNumber){
//                customers[i].setFirstName(ui->firstNameInput->text());
//                customers[i].setLastName(ui->lastNameInput->text());
//                customers[i].setAddress(ui->addressInput->text());
//                customers[i].setCity(ui->cityInput->text());
//                customers[i].setState(ui->stateInput->text());
//                customers[i].setZip(ui->zipInput->text());
//                customers[i].setPhoneNumber(ui->phoneNumberInput->text());
//                customers[i].setDLNumber(ui->DLInput->text());
//                customers[i].setCCNumber(ui->CCInput->text());

//                clearAllInput();
//                ui->validateLable->setText("Recored has been updated!");

//            }
        Customer temp = Customer(ui->firstNameInput->text(), ui->lastNameInput->text(), ui->addressInput->text(), \
                                 ui->cityInput->text(), ui->stateInput->text(), ui->zipInput->text(), \
                                 ui->phoneNumberInput->text(), ui->DLInput->text(), ui->CCInput->text(), ui->custNumberLabel->text().toInt());
        repo.updateCustomer(temp);
        clearAllInput();
        ui->validateLable->setText("Recored has been updated!");
        //}
    }

//saveCustomers();
}

void MainWindow::clearAllInput(){
    ui->firstNameInput->clear();
    ui->lastNameInput->clear();
    ui->addressInput->clear();
    ui->cityInput->clear();
    ui->stateInput->clear();
    ui->zipInput->clear();
    ui->phoneNumberInput->clear();
    ui->DLInput->clear();
    ui->CCInput->clear();
    ui->editCustSubmitBtn->hide();
    ui->deleteCustSubmitBtn->hide();
    ui->addCustSubmitBtn->show();
};


void MainWindow::on_deleteCustSubmitBtn_clicked()
{
    int custNumber = ui->custNumberLabel->text().toInt();
    for(int i = 0; i < customers.size(); ++i){
        if(customers[i].getCustNumber() == custNumber){
            customers.erase(customers.begin() + i);
            clearAllInput();
            ui->validateLable->setText("Recored has been deleted!");
            }
        }
    saveCustomers();
}


void MainWindow::on_selectEconomyBtn_clicked()
{
    ui->selectEconomyBtn->setStyleSheet("outline:5px solid green;");
    ui->selectCompactBtn->setStyleSheet("outline:0px solid green;");
    ui->selectStandardBtn->setStyleSheet("outline:0px solid green;");
    ui->selectPremiumBtn->setStyleSheet("outline:0px solid green;");
    ui->catSelectedLabel->setText("Economy");
}


void MainWindow::on_selectCompactBtn_clicked()
{
    ui->selectEconomyBtn->setStyleSheet("outline:0px solid green;");
    ui->selectCompactBtn->setStyleSheet("outline:5px solid green;");
    ui->selectStandardBtn->setStyleSheet("outline:0px solid green;");
    ui->selectPremiumBtn->setStyleSheet("outline:0px solid green;");
    ui->catSelectedLabel->setText("Compact");
}


void MainWindow::on_selectStandardBtn_clicked()
{
    ui->selectEconomyBtn->setStyleSheet("outline:0px solid green;");
    ui->selectCompactBtn->setStyleSheet("outline:0px solid green;");
    ui->selectStandardBtn->setStyleSheet("outline:5px solid green;");
    ui->selectPremiumBtn->setStyleSheet("outline:0px solid green;");
    ui->catSelectedLabel->setText("Standard");
}


void MainWindow::on_selectPremiumBtn_clicked()
{
    ui->selectEconomyBtn->setStyleSheet("outline:0px solid green;");
    ui->selectCompactBtn->setStyleSheet("outline:0px solid green;");
    ui->selectStandardBtn->setStyleSheet("outline:0px solid green;");
    ui->selectPremiumBtn->setStyleSheet("outline:5px solid green;");
    ui->catSelectedLabel->setText("Premium");
}


void MainWindow::on_customerSearchBox_textEdited(const QString &arg1)
{
    ui->customerSearchResultsList->clear();
    QSet<int> results;
    QString temp;
    for(auto& customer : customers){
        if(customer.getLastName().contains(arg1)){
            results.insert(customer.getCustNumber());
        }
        if(customer.getFirstName().contains(arg1)){
            results.insert(customer.getCustNumber());
        }
    }
    for(auto result : results){
        temp.clear();
        Customer tempCust = getCustById(result);
        temp.append(tempCust.getFirstName() + " ");
        temp.append(tempCust.getLastName() + " ");
        temp.append(QString::number(tempCust.getCustNumber()) + " ");
        ui->customerSearchResultsList->addItem(temp);
    }
}

