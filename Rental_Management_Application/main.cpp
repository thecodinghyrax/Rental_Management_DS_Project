/**************************************************************
* Name        : Project Name (Change)
* Author      : Drew Crawford
* Created     : 12/5/22
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
*               vehicles to them.
*               Input:  list and describe(Change)
*               Output: list and describe(Change)
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
