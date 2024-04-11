#pragma once
#include "Utility.h"

class Vehicle {
private:
	std::string type, brand, departure, destination, startDate, endDate;
	int price;
public:
	Vehicle();
	Vehicle(std::string _type, std::string _brand, std::string _departure,
		std::string _destination, std::string _startDate,
		std::string _endDate, int _price);
	std::string getStartDate();
	std::string getEndDate();
	std::string getType();
	std::string getBrand();
	std::string getDeparture();
	std::string getDestination();
	int getPrice();
	void setData(std::string _type, std::string _brand, std::string _departure,
		std::string _destination, std::string _startDate,
		std::string _endDate, int _price);
	void display();
	std::string toString();
	bool fromString(std::string s);
};