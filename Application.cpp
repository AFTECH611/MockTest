#include <iostream>

#include "Application.h"
#include "Utility.h"
#include "AccountManager.h"

Application::Application() {}

std::unique_ptr<Application> Application::app = nullptr;
Application& Application::getApplication() {
    if(!app) {
        app = std::unique_ptr<Application>(new Application);
    }

    return *(app.get());
}

void Application::run() {
    while(true) {
        // log in while
        while(!AccountManager::getCurrentAccount()) {
            printAppCommandsList();

            int command = getCommandFromCLI();

            executeAppCommand(command);
        }

        // while user is logged in
        while(AccountManager::getCurrentAccount()) {
            AccountManager::getCurrentAccount()->printCommandsList();
            
            int command = getCommandFromCLI();

            AccountManager::getCurrentAccount()->executeCommand(command);
        }

        // AccountManager::logOutAccount(currentAccount);
    }

}

void Application::printAppCommandsList() {
    std::cout << "1 - Login account" << std::endl;
    std::cout << "2 - Register account" << std::endl;
    std::cout << "3 - Exit program" << std::endl;
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

int Application::getCommandFromCLI() {
    std::string command;

    while(true) {
        std::cout << "Insert command: "; std::cin >> command;

        if(Utility::isValidInt(command)) {
            return stoi(command);
        }
        else {
            std::cout << "Invalid command" << std::endl;
        }
    }
}