#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    clearAllInput();
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
    populateRentedVhicleList();
    ui->rentalSelectedForReturn->clear();
}


void MainWindow::on_returnQueueNavBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    if(!recentReturns.isEmpty()){
        QString vehcileToPark = QString::number(recentReturns.top().getVehicleNumber());
        vehcileToPark.append(" - " + QString::number(recentReturns.top().getYear()));
        vehcileToPark.append(" " + recentReturns.top().getMake());
        vehcileToPark.append(" " + recentReturns.top().getModel());

        vehcileToPark.append(" current milage: " + QString::number(recentReturns.top().getMilage()));
        ui->nextCarLbl->setText(vehcileToPark);
    } else {
        ui->nextCarLbl->setText("No vehicles currently waiting");
    }

}


void MainWindow::on_viewTransactionsNavBtn_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    populateHistoryTable();
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
          repo.addCustomer(Customer(ui->firstNameInput->text(),
                                    ui->lastNameInput->text(),
                                    ui->addressInput->text(),
                                    ui->cityInput->text(),
                                    ui->stateInput->text(),
                                    ui->zipInput->text(),
                                    ui->phoneNumberInput->text(),
                                    ui->DLInput->text(),
                                    ui->CCInput->text(),
                                    repo.getNextCustNumber()));

        clearAllInput();
        ui->validateLable->setText(first + " has been added!");
        repo.updateCustTransMap(customerTransactionsMap);
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


void MainWindow::on_editCustSubmitBtn_clicked()
{
    if(ui->validateLable->text().length() < 1){
        Customer temp = Customer(ui->firstNameInput->text(), ui->lastNameInput->text(), ui->addressInput->text(), \
                                 ui->cityInput->text(), ui->stateInput->text(), ui->zipInput->text(), \
                                 ui->phoneNumberInput->text(), ui->DLInput->text(), ui->CCInput->text(), ui->custNumberLabel->text().toInt());
        repo.updateCustomer(temp);
        clearAllInput();
        ui->validateLable->setText("Recored has been updated!");
        repo.updateCustTransMap(customerTransactionsMap);
    }
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
    repo.deleteCustomerById(custNumber);
    clearAllInput();
    ui->validateLable->setText("Recored has been deleted!");
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
      for(auto& customer : repo.getCustomers()){
        if(customer.getLastName().toLower().contains(arg1.toLower())){
            results.insert(customer.getCustNumber());
        }
        if(customer.getFirstName().toLower().contains(arg1.toLower())){
            results.insert(customer.getCustNumber());
        }
        if(QString::number(customer.getCustNumber()).contains(arg1)){
            results.insert(customer.getCustNumber());
        }
    }
    for(auto result : results){
        temp.clear();
        Customer tempCust = repo.getCustomerById(result);
        temp.append(QString::number(tempCust.getCustNumber()) + " ");
        temp.append(tempCust.getFirstName() + " ");
        temp.append(tempCust.getLastName() + " ");
        ui->customerSearchResultsList->addItem(temp);
    }
}


void MainWindow::on_completeRentalButton_clicked()
{
    bool custSelected = false;
    bool vehicleSelected = false;
    if(ui->customerSearchResultsList->selectedItems().size() == 0){
        QMessageBox custBox;
        custBox.setText("Please use the search box and select a current customer.");
        custBox.exec();
    } else {
        custSelected = true;
    }
    if(ui->catSelectedLabel->text() == "None"){
        QMessageBox vehicleBox;
        vehicleBox.setText("Please select a vehicle catagory by clicking the proper image.");
        vehicleBox.exec();
    } else {
        vehicleSelected = true;
    }
    if(custSelected && vehicleSelected){
        QMessageBox::StandardButton confirm;
        QDateTime current = QDateTime::currentDateTime();
        int days = ui->daysSpinBox->value();
        double chargeAmount = repo.getRentalPrice(ui->catSelectedLabel->text().toLower()) * days;
        int custNumber = ui->customerSearchResultsList->selectedItems().at(0)->text().split(" ").value(0).toInt();
        int vehicleNumber = repo.getAvailableVehicleIdByCatagory(ui->catSelectedLabel->text().toLower());
        setStyleSheet("QMessageBox::question{color:white;background-color:black}");
        ui->centralwidget->setStyleSheet("background-color:black");
        ui->statusbar->setStyleSheet("background-color:black");
        QString selection = "Is this information correct?\nCustomer: ";
        selection.append(ui->customerSearchResultsList->selectedItems().at(0)->text() + "\n");
        selection.append("Days: " + QString::number(days) + "\n");
        selection.append("Charge Amount: $" + QString::number(chargeAmount) + "\n");
        selection.append("Catagory: " + ui->catSelectedLabel->text());
        confirm = QMessageBox::question(this, "Confirm", selection, QMessageBox::Yes | QMessageBox::No);


        if(confirm == QMessageBox::Yes){
            if(vehicleNumber == -1){
                QMessageBox none;
                none.setText("There are no " + ui->catSelectedLabel->text() + " vechiles available. \nPlease selecte a differnet vehicle catagory.");
                none.exec();
            }else {
                RentalVehicle rental = repo.getVehicleById(vehicleNumber);
                rental.setIsRented(true);
                rental.setCustNumber(custNumber);
                repo.updateVehicle(rental);
                repo.addTransaction(Transaction(current, chargeAmount, days, vehicleNumber, custNumber));
                ui->stackedWidget->setCurrentIndex(3);
                populateRentedVhicleList();
                repo.updateCustTransMap(customerTransactionsMap);
            }

        }
    }
}


void MainWindow::on_rentedVehicleList_itemClicked(QListWidgetItem *item)
{
    ui->rentalSelectedForReturn->setText(item->text());
}

void MainWindow::populateRentedVhicleList(){
    ui->rentedVehicleList->clear();
    for(auto vehicle : repo.getRentedVehicles()){
        ui->rentedVehicleList->addItem(new QListWidgetItem(QString::number(vehicle.getVehicleNumber()) + " " +
                                                    vehicle.getMake() + " " +
                                                    vehicle.getModel() + " " +
                                                    QString::number(vehicle.getYear()) + " " +
                                                    repo.getCustomerById(vehicle.getCustNumber()).getFirstName() + " " +
                                                    repo.getCustomerById(vehicle.getCustNumber()).getLastName()
                                                    ));
        }
}

void MainWindow::on_returnVehicleBtn_clicked()
{
    if(ui->rentedVehicleList->selectedItems().size() == 0){
        QMessageBox box;
        box.setText("There are no vehicles to return.");
        box.exec();
    }else if(ui->returnConditionInput->toPlainText() != ""){
        QDateTime current = QDateTime::currentDateTime();
        int id = ui->rentedVehicleList->currentItem()->text().split(" ").value(0).toInt();
        Transaction tempTrans = repo.getTransactionByRentedVehicleId(id);

        tempTrans.setEndDate(current);
        tempTrans.setReturnNote(ui->returnConditionInput->toPlainText());

        repo.updateTransaction(tempTrans);

        RentalVehicle tempVehicle = repo.getVehicleById(id);
        tempVehicle.setCustNumber(-1);
        tempVehicle.setIsRented(false);
        repo.updateVehicle(tempVehicle);

        recentReturns.push(tempVehicle);

        populateRentedVhicleList();
        ui->returnConditionInput->clear();
        ui->rentalSelectedForReturn->clear();
        repo.updateCustTransMap(customerTransactionsMap);
    } else {
        QMessageBox box;
        box.setText("Pleas enter a return condition comment.");
        box.exec();
    }

}


void MainWindow::on_returnedToLotBtn_clicked()
{

    if(recentReturns.size() > 1){
        recentReturns.pop();
        QString vehcileToPark = QString::number(recentReturns.top().getVehicleNumber());
        vehcileToPark.append(" - " + QString::number(recentReturns.top().getYear()));
        vehcileToPark.append(" " + recentReturns.top().getMake());
        vehcileToPark.append(" " + recentReturns.top().getModel());

        vehcileToPark.append(" current milage: " + QString::number(recentReturns.top().getMilage()));
        ui->nextCarLbl->setText(vehcileToPark);
    } else if(recentReturns.size() == 1) {
        recentReturns.pop();
        ui->nextCarLbl->setText("No vehicles currently waiting");
    }else {
        ui->nextCarLbl->setText("No vehicles currently waiting");
    }
}

void MainWindow::populateHistoryTable(){
    QSqlQueryModel * model = new QSqlQueryModel();
    repo.getHistoryModel(model);
    ui->rentalHistoryTable->setSortingEnabled(true);
    ui->rentalHistoryTable->setModel(model);

};

void MainWindow::on_rentalHistoryTable_clicked(const QModelIndex &index)
{
    if(index.column() == 5){
        int custNumber = ui->rentalHistoryTable->model()->data(index).toInt();
        QMessageBox box;
        QString message;
        message.append(repo.getCustomerById(custNumber).getFirstName() + " " +
                repo.getCustomerById(custNumber).getLastName() + "'s transactions\n\n");
        QVector<Transaction> transactions = customerTransactionsMap[custNumber];
        for(auto trans : transactions){
            message.append(trans.printTransaction());
        }
        box.setText(message);
        box.exec();
    }
}

