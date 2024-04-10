#include "Hotel.h"

Hotel::Hotel() {
	address = name = "None";
}

Hotel::Hotel(string _address, string _name, vector<room> _roomTypeList) {
	address = _address;
	name = _name;
	for (int i = 0; i < _roomTypeList.size(); i++) {
		roomTypeList[i].available = _roomTypeList[i].available;
		roomTypeList[i].type = _roomTypeList[i].type;
		roomTypeList[i].price = _roomTypeList[i].price;
	}
}

string Hotel::getAddress() {
	return address;
}

string Hotel::getName() {
	return name;
}

vector<room> Hotel::getRoomTypeList() {
	return roomTypeList;
}