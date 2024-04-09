#pragma once
#include "util.h"

struct room{
	std::string type;
	int available;
	int price;
};

class Hotel {
private:
	std::string address;
	std::string name;
	room roomTypeList;
public:
	void get();
	void set();
};