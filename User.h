#ifndef USER_H
#define USER_H

#include <vector>
#include "Account.h"
#include "Trip.h"

class User: public Account {
private:
    int age;
    std::string name;
    std::string address;
    std::vector<Hotel> bookedHotels;
    std::vector<Vehicle> bookedTransportations;

public:
    const int& getAge();
    void setAge(int age);
    const std::string& getName();
    void setName(std::string name);
    const std::string& getAddress();
    void setAddress(std::string address);
    
    void printCommandsList() override;
    void executeCommand(int command) override;
    void toString() override; 
    std::vector<Hotel>& getBookedHotels();
    void bookHotel();
    void cancelHotel();
    std::vector<Vehicle>& getBookedTransportations();
    void bookTransportation();
    void cancelTransportation();

    void display() override;

};

#endif