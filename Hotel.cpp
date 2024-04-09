#include "Hotel.h"

Hotel::Hotel() {
	address = name = "None";
	numbOfTypeRoom = 0;
}

Hotel::Hotel(std::string _address, std::string _name, int _numbOfTypeRoom, std::vector<room> _roomTypeList) {
	address = _address;
	name = _name;
	numbOfTypeRoom = _numbOfTypeRoom;
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

void Hotel::setData(std::string _address, std::string _name, int _numbOfTypeRoom, std::vector<room> _roomTypeList) {
	address = _address;
	name = _name;
	numbOfTypeRoom = _numbOfTypeRoom;
	for (int i = 0; i < _numbOfTypeRoom; i++) {
		roomTypeList[i].available = _roomTypeList[i].available;
		roomTypeList[i].type = _roomTypeList[i].type;
		roomTypeList[i].price = _roomTypeList[i].price;
	}
}

void Hotel::display() {
	std::cout << std::setw(15) << std::left << name << "|"
		<< std::setw(15) << std::left << address << "|"
		<< std::setw(5) << std::left << numbOfTypeRoom << std::endl;
}

void Hotel::showRoomType() {
	for (int i = 0; i < numbOfTypeRoom; i++) {
		std::cout << std::setw(10) << std::left << roomTypeList[i].type << "|"
			<< std::setw(5) << std::left << roomTypeList[i].available << "|"
			<< std::setw(10) << std::left << roomTypeList[i].price << std::endl;
	}
}