#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <chrono>
#include <QString>
#include <QDateTime>

class Transaction
{
private:
    int id;
    QDateTime rentalStartDate;
    QDateTime rentalEndDate;
    double chargeAmount;
    int vehicleId;
    int custNumber;
    QString returnNote;
public:
    Transaction(QDateTime, double, int, int);
    Transaction(QDateTime, QDateTime, double, int, int);
    Transaction(int, QDateTime, QDateTime, double, int, int);
    ~Transaction();

    void setId(int);
    void setStartDate(QDateTime);
    void setEndDate(QDateTime);
    void setChargeAmount(double);
    void setVehicleId(int);
    void setCustNumber(int);
    void setReturnNote(QString);

    int getId();
    QDateTime getStartDate();
    QDateTime getEndDate();
    double getChargeAmount();
    int getVehicleId();
    int getCustNumber();
    QString getReturnNote();

    QString printTransaction();



};

#endif // TRANSACTION_H
