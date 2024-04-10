#ifndef ADMIN_H
#define ADMIN_H

#include <vector>
#include "Account.h"
#include "Hotel.h"

class Admin: public Account {
public:
    Admin();
    Admin(std::string _username, std::string _password);
    std::vector<std::string> getCommandsList() override;
    std::string toString() override;
    void executeCommand(int command) override;
    bool fromString(std::string s) override;
    void editUser(std::string username);
    void removeUser(std::string username);
    void addHotel();
    void editHotel();
    void removeHotel();
    void addTransportation();
    void editTransportation();
    void removeTransporation();
    void display() override;
};

#endif