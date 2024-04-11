#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include "Utility.h"

class DatabaseManager final {
public:
    // different functions that can be executed on a file
    static void readFile(std::string path, std::vector<std::string>& vec);
    static void writeFile(std::string path, const std::vector<std::string>& vec);
    static void appendFile(std::string path, const std::string s);
    static void clearFile(std::string path);
};

#endif