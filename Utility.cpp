#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

#include "Utility.h"

bool Utility::isValidInt(std::string s) {
    try {
        stoi(s);
        return true;   
    }
    catch(const std::exception& e) {
        return false;
    }
}

std::string Utility::encrypt(std::string s) {
    std::hash<std::string> hasher;
    size_t hash = hasher(s);
    return std::to_string(hash);
}

std::string Utility::toLower(std::string input){
    std::string res = "";
    for (int i = 0; i < input.length(); i++) {
        res += tolower(input[i]);
    }
    return res;
}

bool lengthValidAcc(std::string acc){
    return acc.length() < 12;
}

bool lengthValidPwd(std::string pwd){
    return pwd.length() >= 6;
}

bool lengthValidName(std::string name){
    return name.length() < 24;
}

bool isNumeric(char c) {
    return isdigit(static_cast<unsigned char>(c)) != 0;
}

bool isUpperLetter(char c) {
    return (c >= 'a' && c <= 'z');
}

bool isLowerLetter(char c) {
    return (c >= 'A' && c <= 'Z');
}

bool Utility::isValidAcc(std::string acc){
    if (!lengthValidAcc(acc)) {
        std::cout << "User account length must not greater than 16!\n";
        return false;
    }
    for (int i = 0; i < acc.length(); i++) {
        char c = acc[i];
        if(c == ' ') {
            std::cout << "Account user must not contain space character!\n";
            return false;
        }
    }
    return true;
}

bool Utility::isValidPassword(std::string pass){
    bool f1, f2, f3;
    f1 = f2 = f3 = false;
    if(!lengthValidPwd(pass)) {
        std::cout << "Password must contain at least 6 character!\n";
        return false;
    }

    for (char c:pass){
        if (isLowerLetter(c)){
            f1 = true;
        }
        if (isUpperLetter(c)){
            f2 = true;
        }
        if (isNumeric(c)){
            f3 = true;
        }
    }
    if(f1 && f2 && f3) return true;
    if(!f1){
        std::cout << "Password must have at least 1 lowercase letter!\n";
    }
    if(!f2){
        std::cout << "Password must have at least 1 uppercase letter!\n";
    }
    if(!f3){
        std::cout << "Password must have at least 1 number letter!\n";
    }
    return false;
}

bool Utility::isValidName(std::string name) {
    if (!lengthValidName(name)) {
        std::cout << "Name length must not greater than 24!\n";
        return false;
    }
    for (int i = 0; i < name.length(); i++) {
        char c = name[i];
        if(c != ' '){
            if (!isLowerLetter(c) && !isUpperLetter(c)) {
                std::cout << "User full name must not have special character or number!\n";
                return false;
            }   
        }
    }
    return true;
}

void Utility::printVector(std::vector<std::string> vec) {
    for(const std::string& s: vec) {
        std::cout << s << std::endl;
    }
}