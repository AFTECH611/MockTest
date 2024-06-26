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
	bool operator>(const Vehicle& other);
	bool operator<(const Vehicle& other);
	void setStartDate(std::string date);
	void setPrice(int _price);
	void setEndDate(std::string date);
	void setType(std::string _type);
	void setBrand(std::string _brand);
	void setDeparture(std::string _departure);
	void setDestination(std::string _destination);
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
	// read the vehicle from string and write the vehicle to string
	// helps reading and writing database 
	std::string toString();
	bool fromString(std::string s);
};