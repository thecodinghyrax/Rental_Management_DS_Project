/***************************************************************
* Name        : MainWindow
* Author      : Drew Crawford
* Created     : 12/9/22
***************************************************************/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QVector>
#include <QFile>
#include <QStandardPaths>
#include <QTextStream>
#include <QSet>
#include <QMap>
#include <QStack>
#include <QVariant>
#include <QSqlTableModel>
#include "qlistwidget.h"
#include "rentalvehicle.h"
#include "repository.h"
#include "transaction.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**************************************************************
    * Constructors
    ***************************************************************/

    /**************************************************************
    * Name: Drew Crawford
    * Class Name: MainWindow
    * Description: Default no-arg constructor
    * Input parameters: none
    ***************************************************************/
    MainWindow(QWidget *parent = nullptr);

    /**************************************************************
    * Name: Drew Crawford
    * Class Name: ~MainWindow
    * Description: Destructor
    * Input parameters: none
    ***************************************************************/
    ~MainWindow();

private slots:
    /***************************************************************
    * Class Methods
    ***************************************************************/

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: validate
    * Description: Validates the length of the input from the user
    * Input: QString/userInput, QString/msg, int/minLength, int/maxLength
    * Output: bool/true if the input is valid else false
    ***************************************************************/
    bool validate(QString, QString, int, int);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_welcomeNavBtn_clicked
    * Description: Changes the stacked widget to the welcome page
    * Input: none
    * Output: none
    ***************************************************************/
    void on_welcomeNavBtn_clicked();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_addCustomerNavBtn_clicked
    * Description: Changes the stacked widget to the add customer page
    *               Also hides the edit button and shows the add button
    * Input: none
    * Output: none
    ***************************************************************/
    void on_addCustomerNavBtn_clicked();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_rentNavBtn_clicked
    * Description: Changes the stacked widget to the rental page
    * Input: none
    * Output: none
    ***************************************************************/
    void on_rentNavBtn_clicked();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_returnNavBtn_clicked
    * Description: Changes the stacked widget to the return rental page
    * Input: none
    * Output: none
    ***************************************************************/
    void on_returnNavBtn_clicked();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_returnQueueNavBtn_clicked
    * Description: Changes the stacked widget to the return queue page.
    *               Main lable is update to show the next vehicle waiting
    *               to be moved to the lot (if any)
    * Input: none
    * Output: none
    ***************************************************************/
    void on_returnQueueNavBtn_clicked();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_viewTransactionsNavBtn_clicked
    * Description: Changes the stacked widget to the view transactions page
    *               The tableview informtaion is populated with all
    *               transaction information.
    * Input: none
    * Output: none
    ***************************************************************/
    void on_viewTransactionsNavBtn_clicked();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_firstNameInput_textChanged
    * Description: Calles the validate function each time the input
    *               text is updated to update the validate label in the UI
    * Input: QString/&arg1
    * Output: none
    ***************************************************************/
    void on_firstNameInput_textChanged(const QString &arg1);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_lastNameInput_textChanged
    * Description: Calles the validate function each time the input
    *               text is updated to update the validate label in the UI
    * Input: QString/&arg1
    * Output: none
    ***************************************************************/
    void on_lastNameInput_textChanged(const QString &arg1);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_addressInput_textChanged
    * Description: Calles the validate function each time the input
    *               text is updated to update the validate label in the UI
    * Input: QString/&arg1
    * Output: none
    ***************************************************************/
    void on_addressInput_textChanged(const QString &arg1);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_cityInput_textChanged
    * Description: Calles the validate function each time the input
    *               text is updated to update the validate label in the UI
    * Input: QString/&arg1
    * Output: none
    ***************************************************************/
    void on_cityInput_textChanged(const QString &arg1);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_stateInput_textChanged
    * Description: Calles the validate function each time the input
    *               text is updated to update the validate label in the UI
    * Input: QString/&arg1
    * Output: none
    ***************************************************************/
    void on_stateInput_textChanged(const QString &arg1);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_zipInput_textChanged
    * Description: Calles the validate function each time the input
    *               text is updated to update the validate label in the UI
    * Input: QString/&arg1
    * Output: none
    ***************************************************************/
    void on_zipInput_textChanged(const QString &arg1);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_phoneNumberInput_textChanged
    * Description: Calles the validate function each time the input
    *               text is updated to update the validate label in the UI
    * Input: QString/&arg1
    * Output: none
    ***************************************************************/
    void on_phoneNumberInput_textChanged(const QString &arg1);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_DLInput_textChanged
    * Description: Calles the validate function each time the input
    *               text is updated to update the validate label in the UI
    * Input: QString/&arg1
    * Output: none
    ***************************************************************/
    void on_DLInput_textChanged(const QString &arg1);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_CCInput_textChanged
    * Description: Calles the validate function each time the input
    *               text is updated to update the validate label in the UI
    * Input: QString/&arg1
    * Output: none
    ***************************************************************/
    void on_CCInput_textChanged(const QString &arg1);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_addCustSubmitBtn_clicked
    * Description: If the validate label is blank (no validation errors)
    *               a new Customer is created, added to the db and to
    *               the customer transaction map.
    * Input: none
    * Output: none
    ***************************************************************/
    void on_addCustSubmitBtn_clicked();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_loadCustList_clicked
    * Description: Gets all the customers from the db and add them
    *               to the list widget.
    * Input: none
    * Output: none
    ***************************************************************/
    void on_loadCustList_clicked();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_listWidget_itemClicked
    * Description: Hide/shows proper ui buttons and adds the customer
    *               cliched on info to the input fields for updating.
    * Input: QListWidgetItem/ *item
    * Output: none
    ***************************************************************/
    void on_listWidget_itemClicked(QListWidgetItem *item);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_editCustSubmitBtn_clicked
    * Description: If the validate label is empty (no validation errors)
    *               updates the current Customer in the db and rebuilds
    *               the customer transaction map
    * Input: none
    * Output: none
    ***************************************************************/
    void on_editCustSubmitBtn_clicked();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: clearAllInput
    * Description: Clears all customer input fields
    * Input: none
    * Output: none
    ***************************************************************/
    void clearAllInput();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_deleteCustSubmitBtn_clicked
    * Description: Removes the currently selected customer from the db
    *               and rebuilds the customer transaction map
    * Input: none
    * Output: none
    ***************************************************************/
    void on_deleteCustSubmitBtn_clicked();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_selectEconomyBtn_clicked
    * Description: Updates the catagory selected label, adds a border
    *               to the selection and removes the border from the rest.
    * Input: none
    * Output: none
    ***************************************************************/
    void on_selectEconomyBtn_clicked();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_selectCompactBtn_clicked
    * Description: Updates the catagory selected label, adds a border
    *               to the selection and removes the border from the rest.
    * Input: none
    * Output: none
    ***************************************************************/
    void on_selectCompactBtn_clicked();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_selectStandardBtn_clicked
    * Description: Updates the catagory selected label, adds a border
    *               to the selection and removes the border from the rest.
    * Input: none
    * Output: none
    ***************************************************************/
    void on_selectStandardBtn_clicked();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_selectPremiumBtn_clicked
    * Description: Updates the catagory selected label, adds a border
    *               to the selection and removes the border from the rest.
    * Input: none
    * Output: none
    ***************************************************************/
    void on_selectPremiumBtn_clicked();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_selectPremiumBtn_clicked
    * Description: Checks the user input for a match to a customer first name,
    *               last name or customer number as the user is typing. This
    *               will populate the search result list box with any matching
    *               customer(s).
    * Input: QString/&arg1
    * Output: none
    ***************************************************************/
    void on_customerSearchBox_textEdited(const QString &arg1);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_completeRentalButton_clicked
    * Description: If a vehicle catagory is selected and a customer
    *               from the list is selected, a popup window shows
    *               the selected informtion and asks if the user if
    *               they want to complete the displayed rental. If
    *               confirmed, all db updates are done to the vehicle
    *               and transaction records. The customer transaction
    *               map is rebuilt and the list of rented vehicles is
    *               updated.
    * Input: none
    * Output: none
    ***************************************************************/
    void on_completeRentalButton_clicked();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_rentedVehicleList_itemClicked
    * Description: Updates the text of the rental selected label
    *               with the catagory selected
    * Input: QListWidgetItem *item
    * Output: none
    ***************************************************************/
    void on_rentedVehicleList_itemClicked(QListWidgetItem *item);

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: populateRentedVhicleList
    * Description: Gets all rented vehicles from the db and updates
    *               the rented vehicle list.
    * Input: none
    * Output: none
    ***************************************************************/
    void populateRentedVhicleList();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_returnVehicleBtn_clicked
    * Description: If text is entered in the return condition input and
    *               a rented vehicle is selected, the db is updated to
    *               return a rented vehicle, complete the matching
    *               transaction record and rebuilds the customer
    *               transaction map.
    * Input: none
    * Output: none
    ***************************************************************/
    void on_returnVehicleBtn_clicked();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_returnedToLotBtn_clicked
    * Description: If there is a returned vehicle waiting to be moved to the
    *               lot, the last recieved vehicle recieved is removed and the
    *               next in the stack is displayed.
    * Input: none
    * Output: none
    ***************************************************************/
    void on_returnedToLotBtn_clicked();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: populateHistoryTable
    * Description: Gets all completed transaction data from the db
    *               and populates the rental history table.
    * Input: none
    * Output: none
    ***************************************************************/
    void populateHistoryTable();

    /**************************************************************
    * Name: Drew Crawford
    * Method Name: on_rentalHistoryTable_clicked
    * Description: When the customer id colum is clicked, a popup
    *               displays all transaction from the selected customer
    *               from the customer transaction map sorted by date
    * Input: QModelIndex &index
    * Output: none
    ***************************************************************/
    void on_rentalHistoryTable_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QVector<Transaction> custTransactions;
    QMap<int, QVector<Transaction>> customerTransactionsMap;
    Repository repo = Repository(customerTransactionsMap);
    QStack<RentalVehicle> recentReturns;


};
#endif // MAINWINDOW_H
