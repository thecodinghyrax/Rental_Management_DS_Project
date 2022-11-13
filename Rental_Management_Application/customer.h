#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <sstream>

class Customer
{
private:
    std::string firstName;
    std::string lastName;
    std::string address;
    std::string city;
    std::string state;
    std::string zip;
    std::string phoneNumber;
public:
    Customer();
    Customer(std::string, std::string, std::string, std::string,
             std::string, std::string, std::string);
    ~Customer();
    void setFirstName(std::string);
    void setLastName(std::string);
    void setAddress(std::string);
    void setCity(std::string);
    void setState(std::string);
    void setZip(std::string);
    void setPhoneNumber(std::string);

    std::string getFirstName();
    std::string getLastName();
    std::string getAddress();
    std::string getCity();
    std::string getState();
    std::string getZip();
    std::string getPhoneNumber();

    std::string printCustomer();

};

#endif // CUSTOMER_H
