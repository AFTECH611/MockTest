#include "Utility.h"
#include "Trip.h"
#include "Vehicle.h"
#include "Hotel.h"
#include <fstream>

int main() {
    std::vector<Hotel> hotelList;
    std::ifstream file("testinput.txt");
    while (1) {
        std::string hotelName, address;
        int numbOfType;
        std::vector<room> roomTypeList;
        for (int i = 0; i < roomTypeList.size(); i++) {
            roomTypeList.pop_back();
        }
        getline(file, hotelName);
        getline(file, address);
        file >> numbOfType;
        file.ignore();
        for (int i = 0; i < numbOfType; i++) {
            std::string _type;
            int _price, _available;
            getline(file, _type);
            file >> _available;
            file >> _price;
            file.ignore();
            room newType;
            newType.type = _type;
            newType.price = _price;
            newType.available = _available;
            roomTypeList.push_back(newType);
        }
        Hotel newHotel;
        newHotel.setData(address, hotelName, numbOfType, roomTypeList);
        hotelList.push_back(newHotel);
        if (file.eof()) {
            file.close();
            break;
        }
    }
    std::cout << "Hotel list" << std::endl;
    for (int i = 0; i < hotelList.size(); i++) {
        hotelList[i].display();
    }
    std::cout << "Type list" << std::endl;
    for (int i = 0; i < hotelList.size(); i++) {
        std::cout << "HOTEL " << i + 1 << std::endl;
        hotelList[i].showRoomType();
    }
    return 0;
}
