#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_welcomeNavBtn_clicked();

    void on_addCustomerNavBtn_clicked();

    void on_rentNavBtn_clicked();

    void on_returnNavBtn_clicked();

    void on_viewTransactionsNavBtn_clicked();

    void on_returnQueueNavBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
