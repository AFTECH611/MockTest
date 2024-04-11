#include "DatabaseManager.h"
#include "AccountManager.h"


std::vector<std::shared_ptr<Account>> AccountManager::accounts;
std::shared_ptr<Account> AccountManager::currentAccount;
bool AccountManager::load(std::string accountsPath) {
    std::vector<std::string> strAccounts;
    DatabaseManager::readFile(accountsPath, strAccounts);
    try {
        for(std::string acc: strAccounts) {
            if(acc.at(0) == '0') {
                std::shared_ptr<Account> userPtr(new User());
                if(userPtr->fromString(acc)) {
                    accounts.push_back(userPtr);
                }
            }
            else if(acc.at(0) == '1') {
                std::shared_ptr<Account> adminPtr(new Admin());
                if(adminPtr->fromString(acc)) {
                    accounts.push_back(adminPtr);
                }
            }
        }
    }
    catch(const std::exception& e) {
        std::cout << "TripManager failed to load" << std::endl;
        return false;
    }
    return true;
}

void AccountManager::setCurrentAccount() {
    currentAccount = nullptr;
}

const std::shared_ptr<Account>& AccountManager::getCurrentAccount() {
    return currentAccount;
}

bool AccountManager::exists(std::string username){
    for (int i = 0; i < accounts.size(); i++) {
        if(accounts[i]->getUsername() == username) {
            //std::cout << accounts[i]->getUsername();
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
        //std::cout << "Username must not have special character or space. Please enter again: \n";
        getline(std::cin, _Acc);
    }
    std::string lwacc = Utility::toLower(_Acc);
    while (exists(lwacc)) {
        std::cout << "Username existed! Please choose another username: \n";
        getline(std::cin, lwacc);
    }
    lwacc = Utility::toLower(lwacc);
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
    std::shared_ptr<Account> newUser(new User());
    std::string acc = inputRegAccount();
    std::string name = inputFullName();
    std::string pass = inputRegPassword();
    // pass = Utility::encrypt(pass);
    int age = inputAge();
    newUser->setUsername(acc);
    newUser->setPassword(pass);
    newUser->setType("user");
    dynamic_cast<User*>(newUser.get())->setName(name); 
    dynamic_cast<User*>(newUser.get())->setAge(age);
    accounts.push_back(move(newUser));
    std::cout << "User account registered successfully." << std::endl;
    updateDatabase("./Database/Accounts.txt");
    Utility::delay();
    system("cls");
}

void AccountManager::greeting() {
    std::cout << "Loggin successfully! \n\n";
    std::cout << "***   Hello, ";
    if(currentAccount->getType() == "admin"){
        std::cout << "Administrator!   ***\n";
    }
    else{
        std::cout << dynamic_cast<User*>(currentAccount.get())->getName() << "!   ***" << std::endl;
    }
}

bool AccountManager::login() {
    std::string username = inputLogAccountUser(); 
    std::string pass = inputLogPassword();
    // pass = Utility::encrypt(pass);
    for (std::shared_ptr<Account>& acc : accounts) {
        if (acc->getUsername() == username && acc->getPassword() == pass) {
            currentAccount = acc;
            greeting();
            Utility::delay();
            system("cls");
            return true;
        }
    }
    std::cout << "Invalid username or password." << std::endl;
    return false;
}

void AccountManager::updateDatabase(std::string accountsPath) {
    DatabaseManager::clearFile(accountsPath);
    
    for(std::shared_ptr<Account> acc: accounts) {
        DatabaseManager::appendFile(accountsPath, acc->toString());
    }
}

void AccountManager::displayAllAccounts(){
    std::cout << ".___________________________________________________________________________________." << std::endl;
    std::cout << "|      Account       |   Full Name         |  Address              |  Age           |" << std::endl;
    std::cout << "|____________________|_____________________|_______________________|________________|" << std::endl;
    for(std::shared_ptr<Account>& acc : accounts){
        if(acc->getType() == "user"){
            acc->display();
        }
    }
    std::cout << "|___________________________________________________________________________________|" << std::endl;
}

void AccountManager::deleteUser(std::string username){
    bool found = false;
    for(auto ac = accounts.begin(); ac != accounts.end(); ++ac){
        if(ac->get()->getType() == "user"){
            if(ac->get()->getUsername() == username){
                found = true;
                accounts.erase(ac);
                std::cout << "Deleted user " << username << " done!\n";
                break;
            }
        }
    }
    if(!found) std::cout << "Can not find user with " << username << "!\n";
}

void AccountManager::searchUser(std::string username){
    bool found = false;
    std::cout << ".___________________________________________________________________________________." << std::endl;
    std::cout << "|      Account       |   Full Name         |  Address              |  Age           |" << std::endl;
    std::cout << "|____________________|_____________________|_______________________|________________|" << std::endl;
    for(std::shared_ptr<Account>& acc : accounts){
        if(acc->getType() == "user" && acc->getUsername() == username) {
            acc->display();
            found = true;
        } 
    }
    if(!found){
        std::cout << "|System can not found user:                                                  |" << username << std::endl;
    }
    std::cout << "|___________________________________________________________________________________|" << std::endl;
}

void AccountManager::editUser(std::string username){
    bool found = false;
    std::shared_ptr<Account> newUser(new User());
    std::cout << ".___________________________________________________________________________________." << std::endl;
    std::cout << "|      Account       |   Full Name         |  Address              |  Age           |" << std::endl;
    std::cout << "|____________________|_____________________|_______________________|________________|" << std::endl;
    for(std::shared_ptr<Account>& acc : accounts){
        if(acc->getType() == "user" && acc->getUsername() == username) {
            acc->display();
            newUser = acc;
            found = true;
        } 
    }
    if(!found){
        std::cout << "|System can not found user:                                                  |" << username << std::endl;
    }
    std::cout << "|____________________________________________________________________________________|" << std::endl;
    if(found){
        int command;
        std::cout << "Founded user with " << username << std::endl;
        std::cout << "1.Edit name   2.Edit address   3.Edit age\n";
        std::cout << "Take an action(1-4)\n";
        command = Utility::getCommandFromCLI();
        switch (command) {
            case(1): {
                std::string _name;
                std::cout << "New name: ";
                std::cin.ignore(); getline(std::cin, _name);
                while (!Utility::isValidName(_name)) {
                    std::cout << "New name: ";
                    getline(std::cin, _name);
                }
                _name = Utility::toLower(_name);
                dynamic_cast<User*>(newUser.get())->setName(_name);
                std::cout << "Edit name success!\n";
                Utility::delay();
                system("cls");
                break;
            }
            case(2): {
                std::string _address;
                std::cout << "Address: ";
                std::cin.ignore(); getline(std::cin, _address);
                dynamic_cast<User*>(newUser.get())->setAddress(_address); 
                std::cout << "Edit address success!\n";
                Utility::delay();
                system("cls");
                break;
            }
            case(3): {
                int age = Utility::inputAge();
                dynamic_cast<User*>(newUser.get())->setAge(age); 
                std::cout << "Edit age success!\n";
                Utility::delay();
                system("cls");
                break;
            }
            default: {
                std::cout << "Invalid option" << std::endl;
                Utility::delay();
                system("cls");
                break;
            }
        }
    }
}

bool AccountManager::compareName(Account &a, Account &b){
    return true;
}

void AccountManager::sortUserByName(){
}

void AccountManager::autoCreateAdmin(){
    std::shared_ptr<Account> newUser(new Admin());
    std::string username = "admin";
    std::string password = "admin";
    // password = Utility::encrypt(password);
    newUser->setUsername(username); 
    newUser->setPassword(password);
    newUser->setType("admin");
    accounts.push_back(move(newUser));
    std::cout << "Admin account registered successfully." << std::endl;
}

void AccountManager::logout() {
    currentAccount = nullptr;
    std::cout << "Logged out successfully." << std::endl;
    Utility::delay();
    system("cls");
}