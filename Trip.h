#pragma once
#include <iostream>

class Trip {
private:
	int price;
	std::string departure, destination, startDate, endDate;
public:
	Trip();
	Trip(std::string _departure, std::string _destination, std::string _startDate, std::string _endDate, int _price);
	void get();
	void set();
};