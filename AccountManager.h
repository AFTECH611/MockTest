#ifndef ACCOUNT_MANAGER_H
#define ACCOUNT_MANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Utility.h"
#include "Account.h"
#include "User.h"
#include "Admin.h"

class AccountManager {
private:
    static std::vector<std::unique_ptr<Account>> accounts;
    static std::unique_ptr<Account> currentAccount;

public:
    static const std::unique_ptr<Account>& getCurrentAccount();
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
    static void changeUserInfo(std::string name, std::string address, int age);
};

std::vector<std::unique_ptr<Account>> AccountManager::accounts;
std::unique_ptr<Account> AccountManager::currentAccount;

#endif