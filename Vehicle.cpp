#include "Vehicle.h"

Vehicle::Vehicle() {
	type = brand = departure = destination = startDate = endDate = "None";
	price = 0;
}

Vehicle::Vehicle(string _type, string _brand, string _departure,
	string _destination, string _startDate,
	string _endDate, int _price) {
	type = _type;
	brand = _brand;
	departure = _departure;
	destination = _destination;
	startDate = _startDate;
	endDate = _endDate;
	price = _price;
}

string Vehicle::getStartDate() {
	return startDate;
}

string Vehicle::getEndDate() {
	return endDate;
}

string Vehicle::getType() {
	return type;
}

string Vehicle::getBrand() {
	return brand;
}

string Vehicle::getDeparture() {
	return departure;
}

string Vehicle::getDestination() {
	return destination;
}

int Vehicle::getPrice() {
	return price;
}