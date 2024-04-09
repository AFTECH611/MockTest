#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <string>
#include <vector>
#include <memory>

class DatabaseManager final {
public:
    static void readFile(std::string path, std::vector<std::string>& vec);
    static void writeFile(std::string path, const std::vector<std::string>& vec);
    static void appendFile(std::string path, const std::string s);
};

#endif