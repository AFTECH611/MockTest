#include "Account.h"

const std::string Account::getUsername() {
    return username;
}

const std::string Account::getPassword() {
    return password;
}

void Account::setUsername(std::string usr) {
    username = usr;
}

void Account::setPassword(std::string pwd) {
    password = pwd;
}