#include "Trip.h"

Trip::Trip() {
	id = 0;
	price = 0;
	member = 0;
	departure = "None";
	destination = "None";
	startDate = "None";
}

Trip::Trip(int _id, std::string _departure, std::string _destination, std::string _startDate, std::string _endDate, int _price, int _member) {
	id = _id;
	member = _member;
	departure = _departure;
	destination = _destination;
	startDate = _startDate;
	endDate = _endDate;
	price = _price;
	member = _member;
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

void Hotel::minusRoom(int member, std::string type) {
	for (int i = 0; i < roomTypeList.size(); i ++){
		if (roomTypeList[i].type == type) {
			roomTypeList[i].available -= member;
		}
	}
}

void Trip::setData(int _id, std::string _departure, std::string _destination, std::string _startDate, std::string _endDate, int _price, int _member) {
	id = _id;
	member = _member;
	departure = _departure;
	destination = _destination;
	startDate = _startDate;
	endDate = _endDate;
	price = _price;
}

void Trip::display() {
	std::cout << std::setw(5) << std::left << id << "|"
		<< std::setw(15) << std::left << departure << "|"
		<< std::setw(15) << std::left << destination << "|"
		<< std::setw(10) << std::left << startDate << "|"
		<< std::setw(10) << std::left << endDate << "|"
		<< std::setw(10) << std::left << vehicle.getType() << "|"
		<< std::setw(15) << std::left << hotel.getName() << "|"
		<< std::setw(5) << std::left << member << "|"
		<< std::setw(10) << std::left << price << "|" << std::endl;
}