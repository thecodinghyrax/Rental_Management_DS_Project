﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clearAllInput();

    QMessageBox box;
   if(!loadCustomers()){
       box.setWindowTitle("Error");
       box.setText("Customers file could not be loaded!");
       box.exec();
   }
   if(!loadVehicles()){
       box.setWindowTitle("Error");
       box.setText("Vehicles file could not be loaded!");
       box.exec();
   }
}

MainWindow::~MainWindow()
{
    delete ui;
}

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

bool MainWindow::loadCustomers(){
    QFile file("customers.txt");
    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }

    QTextStream in(&file);
    int count = 0;
    Customer tempCust;
    QString line;

    while(!in.atEnd()){
        qCritical() << "Starting loadCustomers while loop";
        line = in.readLine();
        qCritical() << "first line: " << line;
        if(line == "+++"){
            count = 0;
            tempCust.setCustNumber();
            customers.push_back(tempCust);
            line = in.readLine();
        }

        switch(count){
        case 0:
            tempCust.setFirstName(line);
            break;
        case 1:
            tempCust.setLastName(line);
            break;
        case 2:
            tempCust.setAddress(line);
            break;
        case 3:
            tempCust.setCity(line);
            break;
        case 4:
            tempCust.setState(line);
            break;
        case 5:
            tempCust.setZip(line);
            break;
        case 6:
            tempCust.setPhoneNumber(line);
            break;
        case 7:
            tempCust.setDLNumber(line);
            break;
        case 8:
            tempCust.setCCNumber(line);
            break;
        default:
            file.close();
            return false;
            break;
        }
        count++;
    }

    file.close();
    return true;
};

bool MainWindow::loadVehicles(){
    QFile file("vehicles.txt");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return false;
    }

    QTextStream in(&file);
    int count = 0;
    RentalVehicle tempVehicle;
    QString line;
    while(!in.atEnd()){
        line = in.readLine();
        if(line == "+++"){
            count = 0;
            rentals.push_back(tempVehicle);
            line = in.readLine();
        }
        switch(count){
        case 0:
            tempVehicle.setId(line.toInt());
            break;
        case 1:
            tempVehicle.setCatagory(line);
            break;
        case 2:
            tempVehicle.setMake(line);
            break;
        case 3:
            tempVehicle.setModel(line);
            break;
        case 4:
            tempVehicle.setYear(line.toInt());
            break;
        case 5:
            tempVehicle.setMilage(line.toInt());
            break;
        case 6:
            if(line == "true"){
                tempVehicle.setIsRented(true);
            }
            else{
                tempVehicle.setIsRented(false);
            }
            break;
        case 7:
            tempVehicle.setRenterId(line.toInt());
            break;
        default:
            file.close();
            return false;
            break;
        }
        count++;
    }

    file.close();
    return true;
}

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

bool MainWindow::saveVehilces()
{
    return true;
};

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
                                ui->CCInput->text()
                                ));

        clearAllInput();
        ui->validateLable->setText(first + " has been added!");
    }

}


void MainWindow::on_loadCustList_clicked()
{
    ui->listWidget->clear();
    for(auto customer : customers){
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
    int customerIndex = getCustomerIndexById(custNumber);
    if(customerIndex > -1){
        Customer temp = customers[customerIndex];
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

        int custNumber = ui->custNumberLabel->text().toInt();
        for(int i = 0; i < customers.size(); ++i){
            if(customers[i].getCustNumber() == custNumber){
                customers[i].setFirstName(ui->firstNameInput->text());
                customers[i].setLastName(ui->lastNameInput->text());
                customers[i].setAddress(ui->addressInput->text());
                customers[i].setCity(ui->cityInput->text());
                customers[i].setState(ui->stateInput->text());
                customers[i].setZip(ui->zipInput->text());
                customers[i].setPhoneNumber(ui->phoneNumberInput->text());
                customers[i].setDLNumber(ui->DLInput->text());
                customers[i].setCCNumber(ui->CCInput->text());

                clearAllInput();
                ui->validateLable->setText("Recored has been updated!");

            }
        }
    }

saveCustomers();
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


void MainWindow::on_customerSearchBox_textChanged(const QString &arg1)
{
    std::set<Customer> results;
    QString temp;
    for(auto& customer : customers){
        if(customer.getLastName().contains(arg1)){
            results.insert(customer);
        }
        if(customer.getFirstName().contains(arg1)){
            results.insert(customer);
        }
    }
    for(auto& result : results){
        QString temp2 = result.getFirstName().toStdString.c_str();
        temp.append(result.getFirstName() + " ");
    }
    std::set<Customer>::iterator itr;
    for(itr = results.begin(); itr != results.end(); ++itr){
        temp.append(itr->getFirstName() + " ");
        temp.append((itr->getLastName() + " "));
        temp.append((QString::number(itr->getCustNumber())));
        ui->customerSearchResultsList->addItem(temp);
    }
}

