/**************************************************************
* Name        : Project Name (Change)
* Author      : Drew Crawford
* Created     : 12/9/22
* Course      : CIS 152 – Data Structures
* Version     : 1.0
* OS          : Windows 11
* IDE         : Visual Studio 2022
* Copyright   : This is my own original work based on
*               specifications issued by our instructor
* Description : This program demonstrates the use of several
*               data structures in a larger project. This application
*               is for use in a fictional car rental agency. The user
*               can add customers, and then rent differnet types of
*               vehicles to them. The rented cars can be returned and
*               the condition will be recorded. Once the vehicle is
*               returned, it gets placed in a stack that represents
*               a returned car being blocked in by another returned
*               car. The cars are then removed (to the lot) in a last
*               in first out fashion. When cars are returned, a transaction
*               is recorded and all transaction can be viewed. Within
*               the transaction view, customers can be clicked on to
*               show all transactions for that customer (pulled from
*               a map structure).
*               Input:  Users can enter all data for a customer.
*                       Users can pick a vehicle and a customer to rent out.
*                       Users can return a rented a rented vehicle.
*                       Users can remove the next returned vehicle (to the lot)
*               Output: Users can view all customers that have been entered
*                       Users can view all vehicle catagories
*                       Users can view all rented vehicles
*                       Users can view the next available returned vehicle
*                       Users can view all completed transactions.
* Academic Honesty: I attest that this is my original work.
* I have not used unauthorized source code, either modified or
* unmodified. I have not given other fellow student(s) access to
* my program.
***************************************************************/
#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile styleSheetFile("../SpyBot.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);
    MainWindow w;
    w.show();
    return a.exec();
}
