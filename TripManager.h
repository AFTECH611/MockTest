#ifndef TOUR_MANAGER_H
#define TOUR_MANAGER_H

#include "Utility.h"
#include "Trip.h"

class TripManager {
public:
    static std::vector<Hotel> hotels;
    static std::vector<Vehicle> vehicles;

    // load all hotels and vehicles in the system from the database
    static bool load(std::string hotelsPath, std::string vehiclesPath);

    // update database based on the hotels and vehicles vector
    static void updateDatabase(std::string hotelsPath, std::string vehiclesPath);

    // different commands that can be executed by the admin on the hotels and vehicles vector
    static bool compareDateV(Vehicle &a, Vehicle &b);
    static bool comparePriceV(Vehicle &a, Vehicle &b);
    static void sortHotelByDate();
    static void sortVehicleByDate();
    static void sortHotelByPrice();
    static void sortVehicleByPrice();
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