#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include "Account.h"

class Application {
private:
    static std::unique_ptr<Application> app;
    std::unique_ptr<Account> currentAccount;

    Application();

public:
    static Application& getApplication();
    
    void run();

    void printAppCommandsList();
    void executeAppCommand(int command);
    int getCommandFromCLI();
};


#endif