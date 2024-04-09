#ifndef ACCOUNT_MANAGER_H
#define ACCOUNT_MANAGER_H

#include <string>
#include <unordered_set>
#include <memory>
#include "Account.h"

class AccountManager {
public:
    static bool logInAccount(std::unique_ptr<Account>& account, std::string username, std::string password);
    static void logOutAccount(std::unique_ptr<Account>& account);
    static bool registerUser(std::unique_ptr<Account>& account, std::string username, std::string password);
    static bool checkUsernameUnique(std::string username);
    static Account* getAccountFromVector(std::vector<std::string>);
    static std::string setAccountToString(Account* account);
};


#endif