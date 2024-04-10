#include <iostream>
#include <fstream>
#include <vector>

#include "DatabaseManager.h"

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

void DatabaseManager::appendFile(std::string path, const std::string s) {
    std::ofstream file(path, std::ios_base::app);
    if(file.is_open()) {
        file << s;
    }
}

void DatabaseManager::clearFile(std::string path) {
    std::ofstream file("filename.txt");
}

