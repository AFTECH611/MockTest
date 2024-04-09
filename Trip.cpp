#include <iostream>
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

std::string Trip::toString() {
	std::string s = departure + "," + destination + "," + startDate + "," + endDate + "," + std::to_string(price);

	if(hotel.getName() != "") {
		s+= ",[" + hotel.toString() + "]";
	}

	s+=",";

	if(vehicle.getType() != "") {
		s+= ",[" + vehicle.toString() + "]";
	}

	return s;
}

bool Trip::fromString(std::string s) {
	std::vector<std::string> vec = Utility::stringToVector(s,',');

	try {
		std::string _departure, _destination, _startDate, _endDate;
		int _price;
		departure = vec.at(0);
		destination = vec.at(1);
		startDate = vec.at(2);
		endDate = vec.at(3);
		price = std::stoi(vec.at(4));
		Hotel tempHotel;
		if(tempHotel.fromString(vec.at(5)) && tempHotel.getName() != "None") {
			hotel = tempHotel;
		}
		Vehicle tempVehicle;
		if(tempVehicle.fromString(vec.at(6)) && tempVehicle.getType() != "None") {
			vehicle = tempVehicle;
		}
	}
	catch(const std::exception& e) {
		std::cout << "Can't read vehicle from string." << std::endl;
		return false;
	}

	return true;
}