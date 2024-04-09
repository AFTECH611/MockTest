#include "User.h"
#include <iostream>

const int& User::getAge()  {
    return age;
}
void User::setAge(int a) {
    age = a;
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

void User::printCommandsList() {

}

void User::executeCommand(int command) {

}

void User::toString() {

}

void User::display() {
    std:: cout << "USER ACCOUNT" << std::endl;
    std::cout << "Username: " << username << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Age: " << age << std::endl;
}
