#ifndef USER_H
#define USER_H

#include "Utility.h"
#include "Account.h"
#include "AccountManager.h"
#include "Trip.h"
#include "TripManager.h"

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

    // gets the user's list of commands based on different scenarios
    const std::vector<std::string> getCommandsList() override;
    std::vector<std::string> getCommandListAfterViewProfile();
    std::vector<std::string> getCommandListAfterMakeItinerary();
    std::vector<std::string> getCommandListEditProfile();
    std::vector<std::string> getCommandListEditAccount();

    // execute one of the commands executable by the user given the user's input
    void executeCommand(int command) override;

    // read the user from string and write the user to string
    // helps with read and write database
    std::string toString() override; 
    bool fromString(std::string s) override;

    // different actions that the user can make
    void viewProfile();
    void editTrip();
    void editProfile(int command);
    void editAccount(int command);
    Vehicle chooseVehicle(std::string from, std::string to, std::string sDate);
    //void chooseHotel();
    void cancelTrip();
    void makeItinerary();
    void showItinerary();
    void display() override;
};

#endif