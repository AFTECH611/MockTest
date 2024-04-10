#include <iostream>
#include <iomanip>
#include "Hotel.h"


Hotel::Hotel() {
	address = name = "None";
}

Hotel::Hotel(std::string _address, std::string _name, int _numbOfTypeRoom, std::vector<Room> _RoomTypeList) {
	address = _address;
	name = _name;
	numbOfTypeRoom = _numbOfTypeRoom;
	for (int i = 0; i < _numbOfTypeRoom; i++) {
		std::string _type = _RoomTypeList[i].type;
		int _available = _RoomTypeList[i].available;
		int _price = _RoomTypeList[i].price;
		Room newRoom;
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

std::vector<Room> Hotel::getRoomTypeList() {
	return roomTypeList;
}

std::string roomToString(Room r) {
	return r.type + "," + std::to_string(r.available) + "," + std::to_string(r.price);
}

bool stringToRoom(std::string s, Room& r) {
	std::vector<std::string> vec = Utility::stringToVector(s, ',');

	try {
		r.type = vec.at(0);
		r.available = std::stoi(vec.at(1));
		r.price = std::stoi(vec.at(2));;
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
		s+= (",[" + roomToString(r) + "]"); 
	}

	return s;
}

bool Hotel::fromString(std::string s) {
	std::vector<std::string> vec = Utility::stringToVector(s, ',');

	try {
		address = vec.at(0);
		name = vec.at(1);
		roomTypeList.clear();
		for(int i = 2; i < vec.size(); i++) {
			Room tempRoom;
			if(stringToRoom(Utility::stripBrackets(vec.at(i)), tempRoom)) {
				roomTypeList.push_back(tempRoom);
			}
		}
	}
	catch(const std::exception& e) {
		std::cout << "Can't read hotel from string." << std::endl;
		return false;
	}

	return true;
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