#ifndef HOTEL_H
#define HOTEL_H

#include <string>

struct Hotel {
    std::string hotelName;
    std::string location;
    std::string roomType;
    int availableRooms;
    int pricePerNight;
};

#endif