#include <iostream>

#include "Application.h"
#include "Utility.h"
#include "User.h"

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

        while(!currentAccount) {
            printAppCommandsList();

            int command = getCommandFromCLI();

            executeAppCommand(command);
        }

        while(currentAccount) {
            currentAccount->printCommandsList();
            
            int command = getCommandFromCLI();

            currentAccount->executeCommand(command);
        }

        AccountManager::logOutAccount(currentAccount);
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
            std::string username, password;
            std::cout << "Enter username:"; std::cin >> username;
            std::cout << "Enter password:"; std::cin >> password;
            AccountManager::logInAccount(currentAccount, username,password);
            if(currentAccount) {
                std::cout << "Logged in successful" << std::endl;
            }
            else {
                std::cout << "Logged in unsuccessful" << std::endl;
            }

            break;
        }
        case 2:
        {
            while(true) {
                std::string username, password;
                std::cout << "Enter username:"; std::cin >> username;
                std::cout << "Enter password:"; std::cin >> password;
                if(AccountManager::registerUser(currentAccount, username, password)) break;
            }
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