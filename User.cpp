#include <iostream>
#include "User.h"

User::User() {
    username = password = name = address = "None";
    age = 0;
}

User::User(std::string _username, std::string _password, std::string _name, std::string _address, int _age, std::vector<Trip> _bookedTrips) {
    username = _username;
    password = _password;
    name = _name;
    address = _address;
    age = _age;
    bookedTrips = _bookedTrips;
}

const std::string& User::getName()  {
    return name;
}
void User::setName(std::string _name) {
    name = _name;
}

const std::string& User::getAddress()  {
    return address;
}
void User::setAddress(std::string addr) {
    address = addr;
}

const int& User::getAge()  {
    return age;
}
void User::setAge(int a) {
    age = a;
}

const std::vector<Trip>& User::getBookedTrips() {
    return bookedTrips;
}

std::vector<std::string> User::getCommandsList() {
    std::cout << "User commands list" << std::endl;
    return std::vector<std::string>{};
}

void User::executeCommand(int command) {
    
}

std::string User::toString() {
    std::string s = "0," + username + "," + password + "," + name + "," + address + "," + std::to_string(age);
    for(Trip t: bookedTrips) {
        s+=",[" + t.toString() + "]";
    }
    return s;
}

bool User::fromString(std::string s) {
    std::vector<std::string> vec = Utility::stringToVector(s, ',');
    
    try {
        if(vec.at(0) != "0") return false;
        username = vec.at(1);
        password = vec.at(2);
        name = vec.at(3);
        address = vec.at(4);
        age = stoi(vec.at(5));
        for(int i = 6; i < vec.size(); i++) {
            Trip tempTrip;

            if(tempTrip.fromString(Utility::stripBrackets(vec.at(i)))) {
                std::string strRoom = vec[i];
                bookedTrips.push_back(tempTrip);
            }
        }
    }
    catch(const std::exception& e) {
        return false;
    }

    return true;
}

void User::display() {
    std:: cout << "USER ACCOUNT" << std::endl;
    std::cout << "Username: " << username << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Age: " << age << std::endl;
}
