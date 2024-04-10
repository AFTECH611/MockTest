#include "Utility.h"
#include "Application.h"
#include "AccountManager.h"
#include "TripManager.h"

Application::Application() {}

std::unique_ptr<Application> Application::app = nullptr;
Application& Application::getApplication() {
    if(!app) {
        app = std::unique_ptr<Application>(new Application);
    }
    return *(app.get());
}

void Application::run() {
    AccountManager::load("./Database/Accounts.txt");
    TripManager::load("./Database/Hotels.txt", "./Database/Vehicles.txt");

    while(true) {
        // while the account is not logged in
        while(!AccountManager::getCurrentAccount()) {
            Utility::printVector(getAppCommandsList());

            int command = Utility::getCommandFromCLI();

            executeAppCommand(command);
            AccountManager::updateDatabase("./Database/Accounts.txt");
            TripManager::updateDatabase("./Database/Hotels.txt", "./Database/Vehicles.txt");
        }

        // while user is logged in
        while(AccountManager::getCurrentAccount()) {
            Utility::printVector(AccountManager::getCurrentAccount()->getCommandsList());
    
            int command = Utility::getCommandFromCLI();

            AccountManager::getCurrentAccount()->executeCommand(command);
        }

        AccountManager::logout();
    }
}

std::vector<std::string> Application::getAppCommandsList() {
    return std::vector<std::string>{"1 - Login account", "2 - Register account", "3 - Auto create admin", "4 - Exit"};
}

void Application::executeAppCommand(int command) {
    switch(command) {
        case 1:
        {
            AccountManager::login();
            break;
        }
        case 2:
        {
            AccountManager::registerUser();
            break;
        }
        case 3:
        {
            AccountManager::autoCreateAdmin();
            break;
        }
        case 4:
        {
            exit(1);
            break;
        }
        default:
        {
            std::cout << "Unknown command" << std::endl;
        }
    }
}
