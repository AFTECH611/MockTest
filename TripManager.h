#ifndef TOUR_MANAGER_H
#define TOUR_MANAGER_H

#include "Utility.h"
#include "Trip.h"

class TripManager {
private:
    static std::vector<Hotel> hotels;
    static std::vector<Vehicle> vehicles;

public:
    static bool load(std::string hotelsPath, std::string vehiclesPath);

    static void sortHotels();
    static void sortVehicles();

    static void updateDatabase(std::string hotelsPath, std::string vehiclesPath);
    static void searchHotels();
    static void searchVehicles();

    static void deleteHotel();
    static void deleteVehicle();

    static void addVehicle();
    static void addHotel();

    static void displayHotels();
    static void displayVehicles();
};

#endif