#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>
#include <chrono>
#include <math.h>

class Utility final{
public:
    static bool isValidInt(std::string s);
    static std::string encrypt(std::string s);
    static std::string toLower(std::string input);
    static void printVector(std::vector<std::string> vec);
    static bool isValidAcc(std::string acc);
    static bool isValidPassword(std::string pass);
    static bool isValidName(std::string name);  
    static int getCommandFromCLI();
    static std::vector<std::string> stringToVector(std::string s, char delimiter);
    static std::string stripBrackets(std::string s);
    static bool isValidDate(std::string date);
    static bool isValidPlace(std::string s);
    static int inputAge();
    static void delay();
    static int dateDiff(std::string date1, std::string date2);
};

#endif