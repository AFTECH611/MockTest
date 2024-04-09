#include <iostream>
#include "Hotel.h"

Room::Room() {
	type = "None";
}

Room::Room(std::string _type, int _available, int _price) {
	type = _type;
	available = _available;
	price = _price;
}

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

bool Room::fromString(std::string s) {
	std::vector<std::string> vec = Utility::stringToVector(s, ',');

	try {
		std::string _type;
		int _available, _price;
		_type = vec.at(0);
		_available = std::stoi(vec.at(1));
		_price = std::stoi(vec.at(2));
		*this = Room(_type, _available, _price);
	}
	catch(const std::exception& e) {
		std::cout << "Can't read room from string." << std::endl;
		return false;
	}

	return true;
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

	try {
		std::string _address, _name;
		_address = vec.at(0);
		_name = vec.at(1);
		address = _address;
		name = _name;
		roomTypeList.clear();
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