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

