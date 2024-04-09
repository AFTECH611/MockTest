#include "Trip.h"

Trip::Trip() {
	price = 0;
	departure = "None";
	destination = "None";
	startDate = "None";
}

Trip::Trip(string _departure, string _destination, string _startDate, string _endDate, int _price) {
	departure = _departure;
	destination = _destination;
	startDate = _startDate;
	endDate = _endDate;
	price = _price;
}

int Trip::getPrice() {
	return price;
}

string Trip::getDeparture() {
	return departure;
}

string Trip::getDestination() {
	return destination;
}

string Trip::getStartDate() {
	return startDate;
}

string Trip::getEndDate() {
	return endDate;
}

vector<Vehicle> Trip::getVehicleList() {
	return vehicleList;
}

vector<Hotel> Trip::getHotelList() {
	return hotelList;
}

void Trip::setData(string _departure, string _destination, string _startDate, string _endDate, int _price) {
	departure = _departure;
	destination = _destination;
	startDate = _startDate;
	endDate = _endDate;
	price = _price;
}