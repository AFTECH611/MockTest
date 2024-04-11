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

    static bool compareDateV(Vehicle &a, Vehicle &b);
    static bool comparePriceV(Vehicle &a, Vehicle &b);

    static void sortHotelByDate();
    static void sortVehicleByDate();

    static void sortHotelByPrice();
    static void sortVehicleByPrice();

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