#include <string>
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