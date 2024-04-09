#include <string>
#include "Trip.h"

Trip::Trip() {
	price = 0;
	departure = "None";
	destination = "None";
	startDate = "None";
}

Trip::Trip(std::string _departure, std::string _destination, std::string _startDate, std::string _endDate, int _price, Hotel _hotel, Vehicle _vehicle) {
	departure = _departure;
	destination = _destination;
	startDate = _startDate;
	endDate = _endDate;
	price = _price;
	hotel = _hotel;
	vehicle = _vehicle;
}

int Trip::getPrice() {
	return price;
}

std::string Trip::getDeparture() {
	return departure;
}

std::string Trip::getDestination() {
	return destination;
}

std::string Trip::getStartDate() {
	return startDate;
}

std::string Trip::getEndDate() {
	return endDate;
}

Vehicle Trip::getVehicle() {
	return vehicle;
}

Hotel Trip::getHotel() {
	return hotel;
}

void Trip::setData(std::string _departure, std::string _destination, std::string _startDate, std::string _endDate, int _price, Hotel _hotel, Vehicle _vehicle) {
	departure = _departure;
	destination = _destination;
	startDate = _startDate;
	endDate = _endDate;
	price = _price;
	hotel = _hotel;
	vehicle = _vehicle;
}

// std::string Trip::toString() {
// 	std::string s = departure + "," + destination + "," + startDate + "," + endDate + "," + std::to_string(price);

// 	if(hotel.getName() != "") {

// 	}

// 	s+=",";

// 	return s;
// }