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
    static bool load(std::string tripsPath, std::string hotelsPath, std::string vehiclesPath);

    static void sortTrips();
    static void sortHotels();
    static void sortVehicles();

    static std::vector<Trip> searchTrips();
    static std::vector<Hotel> searchHotels();
    static std::vector<Vehicle> searchVehicles();
};

#endif