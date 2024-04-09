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

    std::vector<std::string> getAppCommandsList();
    void executeAppCommand(int command);
};


#endif