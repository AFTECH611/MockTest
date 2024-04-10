#ifndef ACCOUNT_MANAGER_H
#define ACCOUNT_MANAGER_H

#include "Utility.h"
#include "Account.h"
#include "User.h"
#include "Admin.h"

class AccountManager {
private:
    static std::vector<std::shared_ptr<Account>> accounts;
    static std::shared_ptr<Account> currentAccount;

public:
    static bool load(std::string accountsPath);
    static const std::shared_ptr<Account>& getCurrentAccount();
    static bool exists(std::string username);
    static std::string inputRegAccount();
    static std::string inputLogAccountUser();
    static std::string inputRegPassword();
    static std::string inputLogPassword();
    static std::string inputFullName();
    static int inputAge();
    static void registerUser();
    static bool login();
    static void logout();
    static void updateDatabase(std::string accountsPath);
};

#endif