#ifndef DATABASE_MANAGER_H
#define DATABASE_MANAGER_H

#include <string>
#include <vector>

class DatabaseManager final{
public:
    static bool exists(std::string path);
    static std::vector<std::string> readFileToVector(std::string path);
    static void writeFileFromVector(std::string path, std::vector<std::string>);

};

#endif