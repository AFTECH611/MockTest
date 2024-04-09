#ifndef USER_H
#define USER_H

#include <vector>
#include "Account.h"
#include "Hotel.h"

class Admin: public Account {
private:

public:
    void printCommandsList() override;
    void executeCommand(int command) override;
    void editUser(std::string username);
    void removeUser(std::string username);
    void addHotel();
    void editHotel();
    void removeHotel();
    void addTransportation();
    void editTransportation();
    void removeTransporation();
};

#endif