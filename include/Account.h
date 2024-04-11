#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Utility.h"

class Account {
protected:
    std::string username;
    std::string password;
    std::string type;

public:
    virtual const std::string& getUsername() final;
    virtual void setUsername(std::string usr) final;
    virtual const std::string& getPassword() final;
    virtual void setPassword(std::string pwd) final;
    virtual const std::string& getType() final;
    virtual void setType(std::string type) final;
    virtual const std::vector<std::string> getCommandsList()=0;
    virtual void executeCommand(int command)=0;
    // virtual void changePassword() final;
    virtual std::string toString()=0;
    virtual bool fromString(std::string s)=0;
    virtual void display()=0;
};

#endif



