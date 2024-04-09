#pragma once
#include <iostream>

class Vehicle {
private:
	std::string type, brand, departure, destination, startDate, endDate;
	int price;
public:
	Vehicle();
	Vehicle(std::string type, std::string brand, std::string departure, 
		std::string destination, std::string startDate, 
		std::string endDate, int price);
	void get();
	void set();
};