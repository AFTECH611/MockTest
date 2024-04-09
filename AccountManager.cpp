#include "DatabaseManager.h"
#include "AccountManager.h"

std::vector<std::unique_ptr<Account>> accounts;
std::unique_ptr<Account> AccountManager::currentAccount = nullptr;

// bool AccountManager::load(std::string accountsPath) {
//     std::vector<std::string> strAccounts;
//     DatabaseManager::readFile(accountsPath, strAccounts);
//     try {
//         for() {

//         }
//         // Utility::stringToVector(accountsPath, ',');

//     }
//     catch(const std::exception& e) {
//         std::cout << "TripManager failed to load" << std::endl;
//         return false;
//     }

//     return true;

// }

const std::unique_ptr<Account>& AccountManager::getCurrentAccount() {
    return currentAccount;
}

bool AccountManager::exists(std::string username){
    for (int i = 0; i < accounts.size(); i++) {
        if(accounts[i]->getUsername() == username) {
            std::cout << accounts[i]->getUsername();
            return true;
        }
    }
    return false;
}

std::string AccountManager::inputRegAccount(){
    std::cout << "Input User information!\n";
    std::cout << "Enter Account: " << std::endl;
    std::string _Acc;
    std::cin.ignore();
    getline(std::cin, _Acc);
    while (!Utility::isValidAcc(_Acc)) {
        std::cout << "Username must not have special character or space. Please enter again: \n";
        getline(std::cin, _Acc);
    }
    std::string lwacc = Utility::toLower(_Acc);
    while (exists(lwacc)) {
        std::cout << "Username existed! Please choose another username: \n";
        getline(std::cin, lwacc);
    }
    lwacc = Utility::toLower(_Acc);
    return lwacc;
}

std::string AccountManager::inputLogAccountUser(){
    std::cout << "Enter Account: " << std::endl;
    std::string _Acc;
    std::cin.ignore();
    getline(std::cin, _Acc);
    while (!Utility::isValidAcc(_Acc)) {
        std::cout << "Username must not have special character or space. Please enter again: \n";
        getline(std::cin, _Acc);
    }
    std::string lwacc = Utility::toLower(_Acc);
    return lwacc;
}

std::string AccountManager::inputRegPassword(){
    std::cout << "Enter your password: ";
    std::string pass;
    getline(std::cin, pass);
    while (!Utility::isValidPassword(pass)) {
        std::cout << "Please choose another password, enter password: \n";
        getline(std::cin, pass);
    }
    return pass;
}

std::string AccountManager::inputLogPassword(){
    std::cout << "Enter your password: ";
    std::string pass;
    getline(std::cin, pass);
    return pass;
}

std::string AccountManager::inputFullName(){
    std::cout << "Enter your full name: ";
    std::string _name;
    getline(std::cin, _name);
    while (!Utility::isValidName(_name)) {
        std::cout << "Please enter again: \n";
        getline(std::cin, _name);
    }
    std::string lwname = Utility::toLower(_name);
    return lwname;
}

int AccountManager::inputAge(){
    int age;
    std::cout << "Enter age: ";
    std::cin >> age;
    while (age < 0 || std::cin.fail()) {
        std::cout << "Age is must non-negative number. Please enter again: \n";
        std::cin.clear();
        std::cin.ignore();
        std::cin >> age;
    }
    return age;
}

void AccountManager::registerUser(){
    std::unique_ptr<Account> newUser(new User());
    std::string acc = inputRegAccount();
    std::string name = inputFullName();
    std::string pass = inputRegPassword();
    int age = inputAge();
    newUser->setUsername(acc);
    dynamic_cast<User*>(newUser.get())->setName(name); 
    dynamic_cast<User*>(newUser.get())->setAge(age);
    dynamic_cast<User*>(newUser.get())->setPassword(pass);
    accounts.push_back(newUser);
    std::cout << "User account registered successfully." << std::endl;
}

bool AccountManager::login() {
    std::string username = inputLogAccountUser(); 
    std::string pass = inputLogPassword();
    for (std::unique_ptr<Account>& acc : accounts) {
        if (acc->getUsername() == username && acc->getPassword() == pass) {
            currentAccount = std::make_unique<Account>(*acc);
            std::cout << "Logged in successfully." << std::endl;
            return true;
        }
    }
    std::cout << "Invalid username or password." << std::endl;
    return false;
}


void AccountManager::logout() {
    currentAccount = nullptr;
    std::cout << "Logged out successfully." << std::endl;
}

void AccountManager::changeUserInfo(std::string name, std::string address, int age) {
    if(dynamic_cast<User*>(currentAccount.get())) {
        dynamic_cast<User*>(currentAccount.get())->setName(name);
        dynamic_cast<User*>(currentAccount.get())->setAddress(address);
        dynamic_cast<User*>(currentAccount.get())->setAge(age);
        std::cout << "User information updated successfully." << std::endl;
    }
    else {
        std::cout << "Invalid command." << std::endl;
    }
}