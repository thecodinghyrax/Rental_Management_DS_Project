#include "inventory.h"

Inventory::Inventory()
{
    loadVehicles();
}

Inventory::~Inventory(){

};

bool Inventory::isAvailable(QStack<RentalVehicle>& vec){
    for(int i = 0; i < vec.size(); ++i){
        if(vec[i].getIsRented() == false){
            return true;
        }
    }
    return false;
};

RentalVehicle Inventory::getNextVehicle(QStack<RentalVehicle>& vec){
    for(int i = 0; i < vec.size(); ++i){
        if(vec[i].getIsRented() == false){
            return vec[i];
        }
    }
    throw "No vehicle of that catagory is available";
};

RentalVehicle Inventory::peekReturns(){
    return returns.top();
};

void Inventory::addVehicle(RentalVehicle vehicle, QVector<RentalVehicle>& vec){
    vec.push_back(vehicle);
    sortVehiclesByAge(vec);
};

bool Inventory::removeVehicleById(int id, QVector<RentalVehicle>& vec){
    for(int i = 0; i < vec.size(); ++i){
        if(vec[i].getVehicleNumber() == id){
            vec.remove(i);
            return true;
        }
    }
    return false;
};

bool Inventory::removeNextReturn(){
    if(returns.size() == 0){
        return false;
    }
    returns.pop();
    return true;
};

void Inventory::sortVehiclesByAge(QVector<RentalVehicle>& vec){
    // Insersion sort
    RentalVehicle temp;
    int smallestYearIndex = 0;
    int currentIndex = 0;
    while(currentIndex < vec.size()){
        //searching unsorted section for smallest value
        for(int i = currentIndex; i < vec.size(); ++ i){
            if(vec[i].getYear() < vec[smallestYearIndex].getYear()){
                smallestYearIndex = i;
            }
        }
        // Swapping current index with smallest
        if(currentIndex != smallestYearIndex){
            temp = vec[smallestYearIndex];
            vec[smallestYearIndex] = vec[currentIndex];
            vec[currentIndex] = temp;
        }

        currentIndex++;
        smallestYearIndex = currentIndex;
    }

};

bool Inventory::loadVehicles(){
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
            if(tempVehicle.getCatagory() == "economy"){
                addVehicle(tempVehicle, economy);
            } else if(tempVehicle.getCatagory() == "compact"){
                addVehicle(tempVehicle, compact);
            } else if(tempVehicle.getCatagory() == "standard"){
                addVehicle(tempVehicle, standard);
            } else if(tempVehicle.getCatagory() == "premium"){
                addVehicle(tempVehicle, premium);
            }
            line = in.readLine();
        }
        switch(count){
        case 0:
            tempVehicle.setVehicleNumber(line.toInt());
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
            tempVehicle.setCustNumber(line.toInt());
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

bool Inventory::saveVehilces(){
    //TODO
    return true;
}
