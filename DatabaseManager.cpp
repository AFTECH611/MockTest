#include <iostream>
#include <fstream>
#include <vector>

#include "DatabaseManager.h"

std::unique_ptr<DatabaseManager> DatabaseManager::dm = nullptr;
const DatabaseManager& DatabaseManager::getDatabaseManager() {
    if(!dm) {
        dm = std::unique_ptr<DatabaseManager>(new DatabaseManager);
    }

    return *(dm.get());
}

void DatabaseManager::readFile(std::string path, std::vector<std::string>& vec) {
    std::ifstream file(path);

    if(file.is_open()) {
        std::string line;
        while(std::getline(file,line)) {
            vec.push_back(line);
        }
    }
}

void DatabaseManager::writeFile(std::string path, const std::vector<std::string>& vec) {
    std::ofstream file(path);

    if(file.is_open()) {
        std::string line;
        for(const std::string& s: vec) {
            file << s << std::endl;
        }
    }
}

