#include "TripManager.h"

std::unique_ptr<Hotel> TripManager::getHotelFromVector(std::vector<std::string> vec) {
    try {
        return std::unique_ptr<Hotel> (new Hotel(vec[0], vec[1], ));
    }
    catch(const std::exception& e) {
        return nullptr;
    }
}