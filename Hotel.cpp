#include <iostream>
#include <iomanip>
#include "Hotel.h"


Hotel::Hotel() {
	address = name = "None";
}

Hotel::Hotel(std::string _address, std::string _name, int _numbOfTypeRoom, std::vector<Room> _roomTypeList) {
	address = _address;
	name = _name;
	numbOfTypeRoom = _numbOfTypeRoom;
	for (int i = 0; i < _numbOfTypeRoom; i++) {
		std::string _type = _roomTypeList[i].type;
		int _available = _roomTypeList[i].available;
		int _price = _roomTypeList[i].price;
		Room newRoom;
		newRoom.available = _available;
		newRoom.price = _price;
		newRoom.type = _type;
		roomTypeList.push_back(newRoom);
	}
}


void Hotel::setData(std::string _address, std::string _name, int _numbOfTypeRoom, std::vector<Room> _roomTypeList) {
	address = _address;
	name = _name;
	numbOfTypeRoom = _numbOfTypeRoom;
	for (int i = 0; i < _numbOfTypeRoom; i++) {
		std::string _type = _roomTypeList[i].type;
		int _available = _roomTypeList[i].available;
		int _price = _roomTypeList[i].price;
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

int Hotel::getNumbOfRoomType() {
	return numbOfTypeRoom;
}

std::string roomToString(Room r) {
	return r.type + Utility::strCommaD() + std::to_string(r.available) + Utility::strCommaD() + std::to_string(r.price);
}

bool stringToRoom(std::string s, Room& r) {
	std::vector<std::string> vec = Utility::stringToVector(s, 31);
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
	// format: address,name,numOfTypeRoom,[room[0]],[room[1]],...
	std::string s = address + Utility::strCommaD() + name + Utility::strCommaD() + std::to_string(numbOfTypeRoom);

	for(Room r: roomTypeList) {
		s+= (Utility::strCommaD() + Utility::strOpenBracketD() + roomToString(r) + Utility::strCloseBracketD()); 
	}

	return s;
}

bool Hotel::fromString(std::string s) {
	std::vector<std::string> vec = Utility::stringToVector(s, 31);
	
	try {
		address = vec.at(0);
		name = vec.at(1);
		numbOfTypeRoom = std::stoi(vec.at(2));

		for(int i = 3; i < vec.size(); i++) {
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
	std::cout << "|" << std::setw(15) << std::left << name << "|"
		<< std::setw(17) << std::left << address << "|"
		<< std::setw(12) << std::left << numbOfTypeRoom << "|" << std::endl;
}

void Hotel::showRoomType() {
	for (int i = 0; i < numbOfTypeRoom; i++) {
		std::cout << std::setw(10) << std::left << roomTypeList[i].type << "|"
			<< std::setw(5) << std::left << roomTypeList[i].available << "|"
			<< std::setw(10) << std::left << roomTypeList[i].price << std::endl;
	}
}

std::vector<Room> Hotel::searchRoom(std::string type, int available, int price){
	std::vector<Room> result;
	for(Room myRoom : roomTypeList){
		if(myRoom.type == type && myRoom.available == price && myRoom.price == price){
			result.push_back(myRoom);
		}
	}
	return result;
}