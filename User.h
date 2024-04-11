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
    std::vector<std::string> getCommandsList() override;
    std::vector<std::string> getCommandListAfterViewProfile();
    std::vector<std::string> getCommandListAfterMakeItinerary();
    std::vector<std::string> getCommandListEditProfile();
    std::vector<std::string> getCommandListEditAccount();
    void executeCommand(int command) override;
    std::string toString() override; 
    bool fromString(std::string s) override;
    void viewProfile();
    void editProfile(int command);
    void editAccount(int command);
    Vehicle chooseVehicle(std::string from, std::string to, std::string sDate);
    Hotel chooseHotel(std::string to, int member);
    void cancelItinerary();
    void makeItinerary();
    void showItinerary();
    void ItineraryDetail(Vehicle choosedVehicle, Hotel choosedHotel, std::string from, std::string to, std::string sDate, int member);
    void display() override;
};

#endif