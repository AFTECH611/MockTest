#ifndef ACCOUNT_MANAGER_H
#define ACCOUNT_MANAGER_H

#include <iostream>
#include <string>
#include <vector>

#include "Utility.h"
#include "Account.h"
#include "User.h"
#include "Admin.h"

using namespace std;

class AccountManager {
private:
    static vector<Account*> accounts;
    static Account* currentUser;

public:
    // AccountManager() : currentUser(nullptr) {}

    // ~AccountManager() {
    //     for (Account* acc : accounts) {
    //         delete acc;
    //     }
    // }

    static bool exists(string username){
        for (int i = 0; i < accounts.size(); i++) {
            if(accounts[i]->getUsername() == username) {
                cout << accounts[i]->getUsername();
                return true;
            }
        }
        return false;
    }

    static string inputRegAccount(){
        cout << "Input User information!\n";
        cout << "Enter Account: " << endl;
        string _Acc;
        cin.ignore();
        getline(cin, _Acc);
        while (!Utility::isValidAcc(_Acc)) {
            cout << "Username must not have special character or space. Please enter again: \n";
            getline(cin, _Acc);
        }
        string lwacc = Utility::toLower(_Acc);
        while (exists(lwacc)) {
            cout << "Username existed! Please choose another username: \n";
            getline(cin, lwacc);
        }
        lwacc = Utility::toLower(_Acc);
        return lwacc;
    }

    static string inputLogAccountUser(){
        cout << "Enter Account: " << endl;
        string _Acc;
        cin.ignore();
        getline(cin, _Acc);
        while (!Utility::isValidAcc(_Acc)) {
            cout << "Username must not have special character or space. Please enter again: \n";
            getline(cin, _Acc);
        }
        string lwacc = Utility::toLower(_Acc);
        return lwacc;
    }

    static string inputRegPassword(){
        cout << "Enter your password: ";
        string pass;
        getline(cin, pass);
        while (!Utility::isValidPassword(pass)) {
            cout << "Please choose another password, enter password: \n";
            getline(cin, pass);
        }
        return pass;
    }

    static string inputLogPassword(){
        cout << "Enter your password: ";
        string pass;
        getline(cin, pass);
        return pass;
    }

    static string inputFullName(){
        cout << "Enter your full name: ";
        string _name;
        getline(cin, _name);
        while (!Utility::isValidName(_name)) {
            cout << "Please enter again: \n";
            getline(cin, _name);
        }
        string lwname = Utility::toLower(_name);
        return lwname;
    }

    static int inputAge(){
        int age;
        cout << "Enter age: ";
        cin >> age;
        while (age < 0 || cin.fail()) {
            cout << "Age is must non-negative number. Please enter again: \n";
            cin.clear();
            cin.ignore();
            cin >> age;
        }
        return age;
    }

    // chi moi user can register
    
    // static void registerAdmin(){
    //     Account* newAdmin = new Admin();
    //     string acc = inputRegAccount();
    //     string pass = inputRegPassword();
    //     newAdmin->setUsername(acc);
    //     newAdmin->setPassword(pass);
    //     accounts.push_back(newAdmin);
    //     cout << "Administrator account registered successfully." << endl;
    // }

    static void registerUser(){
        Account* newUser = new User();
        string acc = inputRegAccount();
        string name = inputFullName();
        string pass = inputRegPassword();
        int age = inputAge();
        newUser->setUsername(acc);
        dynamic_cast<User*>(newUser)->setName(name); 
        dynamic_cast<User*>(newUser)->setAge(age);
        dynamic_cast<User*>(newUser)->setPassword(pass);
        accounts.push_back(newUser);
        cout << "User account registered successfully." << endl;
    }

    static bool login() {
        string username = inputLogAccountUser(); 
        string pass = inputLogPassword();
        for (Account* acc : accounts) {
            if (acc->getUsername() == username && acc->getPassword() == pass) {
                currentUser = acc;
                cout << "Logged in successfully." << endl;
                return true;
            }
        }
        cout << "Invalid username or password." << endl;
        return false;
    }

    static void logout() {
        currentUser = nullptr;
        cout << "Logged out successfully." << endl;
    }

    // kiem tra xem account la user hay admin
    // chi moi user co name, address va age

    // static void changeUserInfo(string name, string address, int age) {
    //     if (currentUser != nullptr) {
    //         currentUser->setName(name);
    //         currentUser->setAddress(address);
    //         currentUser->setAge(age);
    //         cout << "User information updated successfully." << endl;
    //     } else {
    //         cout << "Please login first." << endl;
    //     }
    // }
};

vector<Account*> AccountManager::accounts;
Account* AccountManager::currentUser;

#endif