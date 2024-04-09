#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
enum accountType{USER, ADMIN};
private:
    std::string type;
    std::string username;

public:
    virtual void printCommandsList()=0;
    virtual void executeCommand(int command)=0;
    virtual void changePassword() final;
    virtual void toString()=0;
};

#endif



