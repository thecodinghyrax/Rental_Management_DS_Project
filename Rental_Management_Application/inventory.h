#ifndef INVENTORY_H
#define INVENTORY_H

#include <QStack>
#include <QVector>
#include "rentalvehicle.h"


class Inventory
{
private:
    QVector<RentalVehicle> economy;
    QVector<RentalVehicle> compact;
    QVector<RentalVehicle> standard;
    QVector<RentalVehicle> premium;
    QStack<RentalVehicle> returns;
public:
    Inventory();
    ~Inventory();
    RentalVehicle getEconomy();
    RentalVehicle getCompact();
    RentalVehicle getStandard();
    RentalVehicle getPremium();
    RentalVehicle peekReturns();

    void addEconomy();
    void addCompact();
    void addStandard();
    void addPremium();
    void addReturn();

    bool removeEconomyById(int);
    bool removeCompactById(int);
    bool removeStandardById(int);
    bool removePremiumById(int);
    bool removeNextReturn();

    void sortVehiclesByAge(QVector<RentalVehicle>&);

    void loadVehicles();

};

#endif // INVENTORY_H
