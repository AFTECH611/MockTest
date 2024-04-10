#include <iostream>
#include <iomanip>
#include "Hotel.h"


Hotel::Hotel() {
	address = name = "None";
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

std::string Hotel::toString() {
	std::string s = address + "," + name;
	// for(room r: roomTypeList) {
	// 	s+= (",[" + r.toString() + "]"); 
	// }
	return s;
}

bool Hotel::fromString(std::string s) {
	// std::vector<std::string> vec = Utility::stringToVector(s, ',');

	// try {
	// 	std::string _address, _name;
	// 	_address = vec.at(0);
	// 	_name = vec.at(1);
	// 	address = _address;
	// 	name = _name;
	// 	roomTypeList.clear();
	// 	for(int i = 2; i < vec.size(); i++) {
	// 		std::string strRoom = vec[i];
	// 		strRoom.pop_back();
	// 		strRoom.erase(0,1);

	// 		Room tempRoom;
	// 		tempRoom.fromString(strRoom);
	// 		roomTypeList.push_back(tempRoom);
	// 	}
	// }
	// catch(const std::exception& e) {
	// 	std::cout << "Can't read hotel from string." << std::endl;
	// 	return false;
	// }

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
std::vector<room> Hotel::searchRoom(std::string type, int available, int price){
	std::vector<room> result;
	for(room myRoom : roomTypeList){
		if(myRoom.type == type && myRoom.available == price && myRoom.price == price){
			result.push_back(myRoom);
		}
	}
	return result;
}