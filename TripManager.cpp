#include <iostream>
#include "TripManager.h"
#include "DatabaseManager.h"

template<class T>
bool loadVector(std::string path, std::vector<T> vec) {
    std::vector<std::string> strVec;
    DatabaseManager::readFile(path, strVec);

    try {
        for(std::string s: strVec) {
            T t;
            t.fromString(s);
            vec.push_back(t);
        }
    }
    catch(const std::exception& e) {
        std::cout << "TripManager failed to load" << std::endl;
    }
    
    return true;
}

bool TripManager::load(std::string tripsPath, std::string hotelsPath, std::string vehiclesPath) {
    return loadVector<Trip>(tripsPath, trips) && loadVector<Hotel>(hotelsPath, hotels) && loadVector<Vehicle>(vehiclesPath, vehicles);
}