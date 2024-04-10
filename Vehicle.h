#pragma once
#include "Utility.h"

class Vehicle {
private:
	string type, brand, departure, destination, startDate, endDate;
	int price;
public:
	Vehicle();
	Vehicle(string _type, string _brand, string _departure,
		string _destination, string _startDate,
		string _endDate, int _price);
	string getStartDate();
	string getEndDate();
	string getType();
	string getBrand();
	string getDeparture();
	string getDestination();
	int getPrice();
	//void set();
};