#include <filesystem>

#include "Utility.h"

bool AccountManager::logInAccount(std::unique_ptr<Account>& account, std::string username, std::string password) {
    // std::string path = "Database/Accounts/" + Utility::encrypt(username);
    // if(std::filesystem::exists(path)) {

    // }    
    // return 0;
}

void AccountManager::logOutAccount(std::unique_ptr<Account>& account) {
    account = nullptr;
}

bool AccountManager::checkUsernameUnique(std::string username) {
    std::string path = "Database/Accounts/" + Utility::encrypt(username);
    return !std::filesystem::exists(path);
}

Account* AccountManager::getAccountFromVector(std::vector<std::string> vec) {
    Account* acc;
    if(vec[1] == "0") {
        
        int age;
        std::string name, address;


    }
    else if(vec[1] == "0") {

    }
    return nullptr;
}


