#include <iostream>

#include "Application.h"
#include "Utility.h"
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
    AccountManager::load("./Database/Users.txt", "./Database/Admins.txt");
    TripManager::load("./Database/Trips.txt", "./Database/Hotels.txt", "./Database/Vehicles.txt");

    while(true) {

        // while the account is not logged in
        while(!AccountManager::getCurrentAccount()) {
            Utility::printVector(getAppCommandsList());

            int command = Utility::getCommandFromCLI();

            executeAppCommand(command);
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
    return std::vector<std::string>{"1 - Login account", "2 - Register account", "3 - Exit program"};
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
            exit(1);
            break;
        }
        default:
        {
            std::cout << "Unknown command" << std::endl;
        }
    }
}
