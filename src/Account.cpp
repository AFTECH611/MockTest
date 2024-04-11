#include "Account.h"

const std::string& Account::getUsername() {
    return username;
}

const std::string& Account::getPassword() {
    return password;
}

const std::string& Account::getType() {
    return type;
}

void Account::setUsername(std::string usr) {
    username = usr;
}

void Account::setPassword(std::string pwd) {
    password = pwd;
}

void Account::setType(std::string _type) {
    type = _type;
}
