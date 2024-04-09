#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
protected:
    std::string username;
    std::string password;

public:
    virtual const std::string getUsername() final;
    virtual void setUsername(std::string usr) final;
    virtual const std::string getPassword() final;
    virtual void setPassword(std::string pwd) final;

    virtual std::vector<std::string> getCommandsList()=0;
    virtual void executeCommand(int command)=0;
    // virtual void changePassword() final;
    virtual std::string toString()=0;
    virtual bool fromString(std::string s)=0;
    virtual void display()=0;
};

#endif



