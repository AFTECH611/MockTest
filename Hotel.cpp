#include "Hotel.h"

Hotel::Hotel() {
	address = name = "None";
}

Hotel::Hotel(std::string _address, std::string _name, std::vector<room> _roomTypeList) {
	address = _address;
	name = _name;
	for (int i = 0; i < _roomTypeList.size(); i++) {
		roomTypeList[i].available = _roomTypeList[i].available;
		roomTypeList[i].type = _roomTypeList[i].type;
		roomTypeList[i].price = _roomTypeList[i].price;
	}
}

std::string Hotel::getAddress() {
	return address;
}

std::string Hotel::getName() {
	return name;
}

std::vector<room> Hotel::getRoomTypeList() {
	return roomTypeList;
}