#ifndef USER_H
#define USER_H

#include <vector>
#include "Account.h"
#include "Hotel.h"
#include "Transportation.h"

class User: public Account {
private:
    int age;
    std::string name;
    std::string address;
    std::vector<Hotel> bookedHotels;
    std::vector<Transportation> bookedTransportations;
public:
    void printCommandsList() override;
    void executeCommand(int command) override;
    std::vector<Hotel>& getBookedHotels();
    void bookHotel();
    void cancelHotel();
    std::vector<Transportation>& getBookedTransportations();
    void bookTransportation();
    void cancelTransportation();

};

#endif