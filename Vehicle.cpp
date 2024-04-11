#include <iostream>
#include <iomanip>
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


bool Vehicle::operator<(const Vehicle& other) {
	if(Utility::dateDiff1(this->getStartDate(), other.startDate) < 0) return true;
	return false;
}


bool Vehicle::operator>(const Vehicle& other) {
	if(Utility::dateDiff1(this->getStartDate(), other.startDate) > 0) return true;
	return false;
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
	std::cout << "|" << std::setw(15) << std::left  << type << "|"
		<< std::setw(15) << std::left << brand << "|"
		<< std::setw(17) << std::left << departure << "|"
		<< std::setw(18) << std::left << destination << "|"
		<< std::setw(16) << std::left << startDate << "|"
		<< std::setw(16) << std::left << endDate << "|"
		<< std::setw(8) << std::left << price << "|" << std::endl;
}

std::string Vehicle::toString() {
	// format: type,brand,departure,destination,startDate,endDate,price
	return type + Utility::strCommaD() + brand + Utility::strCommaD() + departure + Utility::strCommaD() + 
		   destination + Utility::strCommaD() + startDate + Utility::strCommaD() + endDate + Utility::strCommaD() + std::to_string(price);
}

bool Vehicle::fromString(std::string s) {
	std::vector<std::string> vec = Utility::stringToVector(s, 31);
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
		std::cout << "Can't read vehicle from string." << std::endl;
		return false;
	}

	return true;
}
