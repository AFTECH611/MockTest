#include <iostream>
#include <vector>
#include "Vehicle.h"

Vehicle::Vehicle() {
	type = brand = departure = destination = startDate = endDate = "None";
	price = 0;
}

Vehicle::Vehicle(std::string _type, std::string _brand, std::string _departure,
	std::string _destination, std::string _startDate,
	std::string _endDate, int _price) {
	type = _type;
	brand = _brand;
	departure = _departure;
	destination = _destination;
	startDate = _startDate;
	endDate = _endDate;
	price = _price;
}

std::string Vehicle::getStartDate() {
	return startDate;
}

std::string Vehicle::getEndDate() {
	return endDate;
}

std::string Vehicle::getType() {
	return type;
}

std::string Vehicle::getBrand() {
	return brand;
}

std::string Vehicle::getDeparture() {
	return departure;
}

std::string Vehicle::getDestination() {
	return destination;
}

int Vehicle::getPrice() {
	return price;
}

std::string Vehicle::toString() {
	return type + "," + brand + "," + departure + "," + destination + "," + startDate + "," + endDate + "," + std::to_string(price);
}

bool Vehicle::fromString(std::string s) {
	std::vector<std::string> vec = Utility::stringToVector(s, ',');

	try {
		std::string _type, _brand, _departure, _destination, _startDate, _endDate;
		int _price;
		_type = vec.at(0);
		_brand = vec.at(1);
		_departure = vec.at(2);
		_destination = vec.at(3);
		_startDate = vec.at(4);
		_endDate = vec.at(5);
		_price = stoi(vec.at(6));

		*this = Vehicle(_type, _brand, _departure, _destination, _startDate, _endDate, _price);
	}
	catch(const std::exception& e) {
		std::cout << "Can't read vehicle from string" << std::endl;
		return false;
	}

	return true;
}
