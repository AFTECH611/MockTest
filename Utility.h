#ifndef UTILITY_H
#define UTILITY_H

#include <string>

class Utility final{

public:
    static bool isValidInt(std::string s);
    static std::string encrypt(std::string s);
    static std::string toLower(std::string input);
    static bool isValidAcc(std::string acc);
    static bool isValidPassword(std::string pass);
    static bool isValidName(std::string name);  
};

#endif