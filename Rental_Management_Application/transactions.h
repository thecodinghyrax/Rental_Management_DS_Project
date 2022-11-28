#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include <chrono>
#include <QString>
#include <QDateTime>

class Transactions
{
private:
    QDateTime rentalStartDate;
    QDateTime rentalEndDate;
    double chargeAmount;
    int vehicleId;
    int custNumber;
    QString returnNote;
public:
    Transactions(QDateTime, double, int, int);
    ~Transactions();

    void setStartDate(QDateTime);
    void setEndDate(QDateTime);
    void setChargeAmount(double);
    void setVehicleId(int);
    void setCustNumber(int);
    void setReturnNote(QString);

    QDateTime getStartDate();
    QDateTime getEndDate();
    double getChargeAmount();
    int getVehicleId();
    int getCustNumber();
    QString getReturnNote();

    QString printTransaction();



};

#endif // TRANSACTIONS_H
