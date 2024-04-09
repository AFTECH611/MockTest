#include <iostream>
#include "Hotel.h"


Hotel::Hotel() {
	address = name = "None";
}

Hotel::Hotel(std::string _address, std::string _name, std::vector<Room> _roomTypeList) {
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

std::vector<Room> Hotel::getRoomTypeList() {
	return roomTypeList;
}

std::string Room::toString() {
	return type + "," + std::to_string(available) + "," + std::to_string(price);
}

void Room::fromString(std::string s) {
	std::vector<std::string> vec = Utility::stringToVector(s, ',');

	try {
		type = vec.at(0);
		available = std::stoi(vec.at(1));
		price = std::stoi(vec.at(2));
	}
	catch(const std::exception& e) {
		std::cout << "Can't read room from string." << std::endl;
	}
}

std::string Hotel::toString() {
	std::string s = address + "," + name;
	for(Room r: roomTypeList) {
		s+= (",[" + r.toString() + "]"); 
	}
	return s;
}

bool Hotel::fromString(std::string s) {
	std::vector<std::string> vec = Utility::stringToVector(s, ',');
	roomTypeList.clear();

	try {
		address = vec.at(0);
		name = vec.at(1);
		for(int i = 2; i < vec.size(); i++) {
			std::string strRoom = vec[i];
			strRoom.pop_back();
			strRoom.erase(0,1);

			Room tempRoom;
			tempRoom.fromString(strRoom);

			roomTypeList.push_back(tempRoom);
		}

	}
	catch(const std::exception& e) {
		std::cout << "Can't read hotel from string." << std::endl;
		return false;
	}

	return true;
}