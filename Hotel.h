#pragma once
#include "Utility.h"
#include <vector>

struct room {
	std::string type;
	int available;
	int price;
};

class Hotel {
private:
	std::string address;
	std::string name;
	std::vector<room> roomTypeList;
public:
	Hotel();
	Hotel(std::string _address, std::string _name, std::vector<room> _roomTypeList);
	std::string getAddress();
	std::string getName();
	std::vector<room> getRoomTypeList();
};