#ifndef TOUR_MANAGER_H
#define TOUR_MANAGER_H

#include <vector>
#include <memory>
#include "Trip.h"

class TripManager {
private:
    static std::vector<Trip> trips;
    static std::vector<Hotel> hotels;
    static std::vector<Vehicle> vehicles;

public:
    static void loadTrips();
    static void loadHotels();
    static void loadVehicles();
    static void printAllHotels();
    static void printAllVehicles();
    static void sortHotels();
    static void sortVehicles();
    static std::vector<Hotel> searchHotels();
    static std::vector<Vehicle> searchVehicles();
    static std::unique_ptr<Hotel> getHotelFromVector(std::vector<std::string> vec);
    static std::unique_ptr<Vehicle> getVehicleFromVector(std::vector<std::string> vec);

};

#endif