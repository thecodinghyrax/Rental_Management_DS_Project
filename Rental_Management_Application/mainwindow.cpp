#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    customers.push_back(Customer("Drew",
                                 "Crawford",
                                 "4407 SW Harmony Cir",
                                 "Ankeny",
                                 "Iowa",
                                 "50023",
                                 "515-868-9257",
                                 "7894KK5674",
                                 "1234-1234-1234-1234"));
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

        ui->firstNameInput->clear();
        ui->lastNameInput->clear();
        ui->addressInput->clear();
        ui->cityInput->clear();
        ui->stateInput->clear();
        ui->zipInput->clear();
        ui->phoneNumberInput->clear();
        ui->DLInput->clear();
        ui->CCInput->clear();

        ui->validateLable->setText(first + " has been added!");
    }

}


void MainWindow::on_loadCustList_clicked()
{
    for(auto customer : customers){
        ui->listWidget->addItem(new QListWidgetItem(customer.getFirstName() + " " +
                                                customer.getLastName() + " " +
                                                    customer.getPhoneNumber()));
}
}

