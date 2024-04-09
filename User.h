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
    const std::vector<Trip>& getBookedTrips();
    
    std::vector<std::string> getCommandsList() override;
    void executeCommand(int command) override;
    std::string toString() override; 
    bool fromsTring(std::string s);
    void editTrip();
    void cancelTrip();
    void editUserInfo();

    void display() override;

};

#endif