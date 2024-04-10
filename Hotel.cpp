#include "Hotel.h"

Hotel::Hotel() {
	address = name = "None";
	numbOfTypeRoom = 0;
}

Hotel::Hotel(std::string _address, std::string _name, int _numbOfTypeRoom, std::vector<room> _roomTypeList) {
	address = _address;
	name = _name;
	numbOfTypeRoom = _numbOfTypeRoom;
	for (int i = 0; i < _numbOfTypeRoom; i++) {
		std::string _type = _roomTypeList[i].type;
		int _available = _roomTypeList[i].available;
		int _price = _roomTypeList[i].price;
		room newRoom;
		newRoom.available = _available;
		newRoom.price = _price;
		newRoom.type = _type;
		roomTypeList.push_back(newRoom);
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
		std::string _type = _roomTypeList[i].type;
		int _available = _roomTypeList[i].available;
		int _price = _roomTypeList[i].price;
		room newRoom;
		newRoom.available = _available;
		newRoom.price = _price;
		newRoom.type = _type;
		roomTypeList.push_back(newRoom);
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
