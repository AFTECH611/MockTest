#include <iostream>
#include "TripManager.h"
#include "DatabaseManager.h"

std::vector<Hotel> TripManager::hotels;
std::vector<Vehicle> TripManager::vehicles;

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

bool TripManager::load(std::string hotelsPath, std::string vehiclesPath) {
    return loadVector<Hotel>(hotelsPath, hotels) && loadVector<Vehicle>(vehiclesPath, vehicles);
}

void TripManager::updateDatabase(std::string hotelsPath, std::string vehiclesPath) {
    DatabaseManager::clearFile(hotelsPath);
    DatabaseManager::clearFile(vehiclesPath);
    
    for(Hotel hotel: hotels) {
        DatabaseManager::appendFile(hotelsPath, hotel.toString());
    }
    
    for(Vehicle vehicle: vehicles) {
        DatabaseManager::appendFile(vehiclesPath, vehicle.toString());
    }
}
