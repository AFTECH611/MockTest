#include "Trip.h"

Trip::Trip() {
	price = 0;
	departure = "None";
	destination = "None";
	startDate = "None";
}

Trip::Trip(std::string _departure, std::string _destination, std::string _startDate, std::string _endDate, int _price) {
	departure = _departure;
	destination = _destination;
	startDate = _startDate;
	endDate = _endDate;
	price = _price;
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

std::vector<Vehicle> Trip::getVehicleList() {
	return vehicleList;
}

std::vector<Hotel> Trip::getHotelList() {
	return hotelList;
}

void Trip::setData(std::string _departure, std::string _destination, std::string _startDate, std::string _endDate, int _price) {
	departure = _departure;
	destination = _destination;
	startDate = _startDate;
	endDate = _endDate;
	price = _price;
}