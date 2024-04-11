#ifndef ADMIN_H
#define ADMIN_H

#include "Utility.h"
#include "Account.h"
#include "Hotel.h"

class Admin: public Account {
public:
    Admin();
    Admin(std::string _username, std::string _password);
    std::vector<std::string> getCommandsList() override;
    std::vector<std::string> getCmdListsUserManagement();
    std::vector<std::string> getCmdListsFlightManagement();
    std::vector<std::string> getCmdListsHotelManagement();
    std::vector<std::string> getCmdListsFlightDisplay();
    std::string toString() override;
    void executeCommand(int command) override;
    void executeCmdAfterLogin(int cmd);
    void executeCmdAfterUser();
    void executeCmdAfterHotel();
    void executeCmdAfterFlight();
    void executeCmdAfterFlightDisplay();
    bool fromString(std::string s) override;
    bool isViewAllUser();
    void editUser(std::string username);
    void removeUser(std::string username);
    void addHotel();
    void editHotel();
    void removeHotel();
    void addTransportation();
    void editTransportation();
    void removeTransportation();
    void display() override;
};

#endif