#pragma once
#include "Utility.h"
#include <vector>

struct room{
	string type;
	int available;
	int price;
};

class Hotel {
private:
	string address;
	string name;
	vector<room> roomTypeList;
public:
	Hotel();
	Hotel(string _address, string _name, vector<room> _roomTypeList);
	string getAddress();
	string getName();
	vector<room> getRoomTypeList();
};