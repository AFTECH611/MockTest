#include <filesystem>

#include "Utility.h"
#include "User.h"

bool AccountManager::logInAccount(std::unique_ptr<Account>& account, std::string username, std::string password) {
    // std::string path = "Database/Accounts/" + Utility::encrypt(username);
    // if(std::filesystem::exists(path)) {

    // }    
    // return 0;
    return 
}

void AccountManager::logOutAccount(std::unique_ptr<Account>& account) {
    account = nullptr;
}

bool AccountManager::checkUsernameUnique(std::string username) {
    std::string path = "Database/Accounts/" + username;
    return !std::filesystem::exists(path);
}

std::unique_ptr<Account> AccountManager::getAccountFromVector(std::vector<std::string> vec) {
    std::unique_ptr<Account> acc;
    if(vec[1] == "0") {
        /*
            User accounts file layout:
            - password: str
            - type: str
            - age: int
            - name: str
            - address: str
            - bookedTrips: vector
        */
        if(vec.size() != 6 || !Utility::isValidInt(vec[2])) return nullptr; 
        acc = std::unique_ptr<User>(new User());



    }
    else if(vec[1] == "0") {
        /*
            Admin accounts file layout:
            - password
            - type
        */

        if(vec.size() != 2) return nullptr;
    }
    return nullptr;
}


