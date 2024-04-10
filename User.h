#ifndef USER_H
#define USER_H

#include <vector>
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
    void addNewItinerary(Trip newTrip);
    
    std::vector<std::string> getCommandsList() override;
    std::vector<std::string> getCommandListAfterViewProfile();
    std::vector<std::string> getCommandListAfterMakeItinerar();
    std::vector<std::string> getCommandListEditProfile();
    std::vector<std::string> getCommandListEditAccount();
    void executeCommand(int command) override;
    std::string toString() override; 
    bool fromString(std::string s) override;
    void viewProfile();
    void editProfile(int command);
    void editAccount(int command);
    void cancelTrip();
    void makeItinerary();
    void showItinerary();
    void display() override;
};

#endif