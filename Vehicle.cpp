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
		type = vec.at(0);
		brand = vec.at(1);
		departure = vec.at(2);
		destination = vec.at(3);
		startDate = vec.at(4);
		endDate = vec.at(5);
		price = stoi(vec.at(6));
	}
	catch(const std::exception& e) {
		std::cout << "Can't read vehicle from string" << std::endl;
		return false;
	}

	return true;
}
