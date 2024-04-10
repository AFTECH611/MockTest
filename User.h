#ifndef USER_H
#define USER_H

#include "Utility.h"
#include "Account.h"
#include "Trip.h"

class User: public Account {
private:
    std::string name;
    std::string address;
    int age;
    std::vector<Trip> bookedTrips;

public:
    User();
    User(std::string _username, std::string _password, std::string _name, std::string _address, int _age, std::vector<Trip> _bookedTrips);
    const int& getAge();
    void setAge(int age);
    void setName(std::string name);
    const std::string& getAddress();
    void setAddress(std::string address);
    const std::vector<Trip>& getBookedTrips();
    const std::string& getName();
    
    std::vector<std::string> getCommandsList() override;
    void executeCommand(int command) override;
    std::string toString() override; 
    bool fromString(std::string s) override; 
    void editTrip();
    void cancelTrip();
    void editUserInfo();

    void display() override;

};

#endif