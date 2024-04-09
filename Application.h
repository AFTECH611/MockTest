#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include "Account.h"

class Application final {
private:
    static std::unique_ptr<Application> app;
    Application();

public:
    static Application& getApplication();
    
    void run();

    void printAppCommandsList();
    void executeAppCommand(int command);
    int getCommandFromCLI();
};


#endif