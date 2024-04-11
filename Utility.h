#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>
#include <chrono>
#include <math.h>
#include <algorithm>


class Utility final{
public:
    // checks if an int is valid
    static bool isValidInt(std::string s);
    // static std::string encrypt(std::string s);
    static std::string toLower(std::string input);
    // print each element of a vector in separated lines 
    static void printVector(std::vector<std::string> vec);
    // checks each of an user's information to see if it's valid
    static bool isValidAcc(std::string acc);
    static bool isValidPassword(std::string pass);
    static bool isValidName(std::string name);  
    // asks the user to give an input until they give a valid int command
    static int getCommandFromCLI();
    // convert a comma separated string to vector
    // helps converting string to class
    static std::vector<std::string> stringToVector(std::string s, char delimiter);
    // this helps the function that converts string to a class
    // used to read each class from database 
    static std::string stripBrackets(std::string s);
    // check if date is valid from string
    static bool isValidDate(std::string date);
    // check if place is valid from string
    static bool isValidPlace(std::string s);
    // get age input with certain rules enforced (ex: age can't be negative)
    static int inputAge();
    static void delay();
    static int daysSince1900(int day,int month, int year);
    static int dateDiff(std::string date1, std::string date2);
    // returns delimiter for the database which are characters that can't be input by the user
    static std::string strOpenBracketD();
    static std::string strCloseBracketD();
    static std::string strCommaD();
};

#endif