#ifndef ADMIN_H
#define ADMIN_H

#include "Utility.h"
#include "Account.h"
#include "Hotel.h"

class Admin: public Account {
public:
    Admin();
    Admin(std::string _username, std::string _password);
    const std::vector<std::string> getCommandsList() override;
    const std::vector<std::string> getCmdListsUserManagement();
    const std::vector<std::string> getCmdListsFlightManagement();
    const std::vector<std::string> getCmdListsHotelManagement();

    // execute a specific command based on the admin's input
    void executeCommand(int command) override;

    // execute command based on different scenarios
    void executeCmdAfterLogin(int cmd);
    void executeCmdAfterUser();
    void executeCmdAfterHotel();
    void executeCmdAfterFlight();
    
    // different commands that the admin can execute
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
    
    // read the admin from string and write the admin to string
    // helps with read and write database
    std::string toString() override;
    bool fromString(std::string s) override;
};

#endif