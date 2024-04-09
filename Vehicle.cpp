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

void Vehicle::setData(std::string _type, std::string _brand, std::string _departure,
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

void Vehicle::display() {
	std::cout << std::setw(10) << std::left << type << "|"
		<< std::setw(10) << std::left << brand << "|"
		<< std::setw(15) << std::left << departure << "|"
		<< std::setw(15) << std::left << destination << "|"
		<< std::setw(10) << std::left << startDate << "|"
		<< std::setw(10) << std::left << endDate << "|"
		<< std::setw(10) << std::left << price << "|" << std::endl;
}