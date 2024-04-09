#ifndef UTILITY_H
#define UTILITY_H

#include <string>
#include "DatabaseManager.h"
#include "AccountManager.h"
#include "TourManager.h"

class Utility final{
public:
    static bool isValidInt(std::string s);
    static std::string encrypt(std::string s);

};

#endif