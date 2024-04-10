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
    return std::vector<std::string>{};
}

void Admin::executeCommand(int command) {

}
bool Admin::fromString(std::string s) {
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


