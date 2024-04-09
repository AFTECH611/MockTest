#ifndef TOUR_MANAGER_H
#define TOUR_MANAGER_H

#include <vector>
#include "Hotel.h"
#include "Transportation.h"

class TourManager {
private:
    static std::vector<Hotel> allHotels;
    static std::vector<Transportation> allTransportations;

public:
    static void loadAllHotels();
    static void loadAllTransportations();
    static void printHotel();
    static void printTransportation();
    static void printAllHotels();
    static void printAllTransportations();
    static void sortHotels();
    static void sortTransportations();
    static std::vector<Hotel> searchHotels();
    static std::vector<Transportation> searchTransportations();
    static Hotel hotelFromString(std::string s);
    static Transportation transporationFromString(std::string s);
    static std::string hotelToString(Hotel r);
    static std::string transporationToString(Transportation v);

};

#endif