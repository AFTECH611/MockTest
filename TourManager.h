#ifndef TOUR_MANAGER_H
#define TOUR_MANAGER_H

#include <vector>
#include "Hotel.h"
#include "Vehicle.h"

class TourManager {
private:
    static std::vector<Hotel> allHotels;
    static std::vector<Vehicle> allVehicles;

public:
    static void loadAllHotels();
    static void loadAllVehicles();
    static void printHotel();
    static void printVehicle();
    static void printAllHotels();
    static void printAllVehicles();
    static void sortHotels();
    static void sortVehicles();
    static std::vector<Hotel> searchHotels();
    static std::vector<Vehicle> searchVehicles();
    static Hotel hotelFromString(std::string s);
    static Vehicle transporationFromString(std::string s);
    static std::string hotelToString(Hotel r);
    static std::string transporationToString(Vehicle v);

};

#endif