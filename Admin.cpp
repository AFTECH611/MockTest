#include <iostream>
#include "Admin.h"

Admin::Admin() {
    username = password = "None";
}

Admin::Admin(std::string _username, std::string _password) {
    username = _username;
    password =_password; 
}

std::string Admin::toString() {
    return "1," + username + "," + password;
}

std::vector<std::string> Admin::getCommandsList() {
    std::cout << "Admin commands list" << std::endl;
    return std::vector<std::string>{};
}

void Admin::executeCommand(int command) {

}
bool Admin::fromString(std::string s) {
    std::vector<std::string> vec = Utility::stringToVector(s, ',');
    
    try {
        if(vec.at(0) != "1") return false;
        username = vec.at(1);
        password = vec.at(2);
    }
    catch(const std::exception& e) {
        return false;
    }

    return true;
}
void Admin::editUser(std::string username) {

}
void Admin::removeUser(std::string username) {

}
void Admin::addHotel() {

}
void Admin::editHotel() {
    
}
void Admin::removeHotel() {

}
void Admin::addTransportation() {

}
void Admin::editTransportation() {

}
void Admin::removeTransporation() {

}
void Admin::display() {

}


