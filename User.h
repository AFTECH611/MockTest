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
    std::vector<Trip> bookedTrips;

public:
    const int& getAge();
    void setAge(int age);
    const std::string& getName();
    void setName(std::string name);
    const std::string& getAddress();
    void setAddress(std::string address);
    
    std::vector<std::string> getCommandsList() override;
    void executeCommand(int command) override;
    void toString() override; 
    std::vector<Trip>& getBookedTrips();
    void editTrip();
    void cancelTrip();
    void editUserInfo();
    

    void display() override;

};

#endif