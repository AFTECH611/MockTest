#pragma once
#include "Utility.h"
#include <vector>

class Room {
public:
	std::string type;
	int available;
	int price;

	Room();
	Room(std::string _type, int _available, int _price);
	std::string toString();
	bool fromString(std::string s);
};

class Hotel {
private:
	std::string address;
	std::string name;
	std::vector<Room> roomTypeList;

public:
	Hotel();
	Hotel(std::string _address, std::string _name, std::vector<Room> _roomTypeList);
	std::string getAddress();
	std::string getName();
	std::vector<Room> getRoomTypeList();
	std::string toString();
	bool fromString(std::string s);
};