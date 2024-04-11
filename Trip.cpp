#include <iostream>
#include <iomanip>
#include "Trip.h"

Trip::Trip() {
	price = 0;
	member = 0;
	departure = "None";
	destination = "None";
	startDate = "None";
}

Trip::Trip(std::string _departure, std::string _destination, std::string _startDate, std::string _endDate, int _price, int _member) {
	member = _member;
	departure = _departure;
	destination = _destination;
	startDate = _startDate;
	endDate = _endDate;
	price = _price;
	member = _member;
	price = 0;
}

void Trip::setVehicle(Vehicle _vehicle) {
	vehicle = _vehicle;
}

void Trip::setHotel(Hotel _hotel) {
	hotel = _hotel;
}

void Trip::setPrice(int _price) {
	price = _price;
}

void Trip::setMember(int _member) {
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

void Trip::setData(std::string _departure, std::string _destination, std::string _startDate, std::string _endDate, Vehicle _vehicle, Hotel _hotel, int _price, int _member, int _bookedRoomIndex) {
	member = _member;
	departure = _departure;
	destination = _destination;
	startDate = _startDate;
	endDate = _endDate;
	price = _price;
	vehicle.setData(_vehicle.getType(), _vehicle.getBrand(), _vehicle.getDeparture(), _vehicle.getDestination(), _vehicle.getStartDate(), _vehicle.getEndDate(), _vehicle.getPrice());
	hotel.setData(_hotel.getAddress(), _hotel.getName(), _hotel.getNumbOfRoomType(), _hotel.getRoomTypeList());
}

std::string Trip::toString() {
	std::string s = departure + Utility::strCommaD() + destination + Utility::strCommaD() + startDate + Utility::strCommaD() + endDate + Utility::strCommaD() + std::to_string(price);

	if(hotel.getName() != "") {
		s+= Utility::strCommaD() + Utility::strOpenBracketD() + hotel.toString() + Utility::strCloseBracketD();
	}

	if(vehicle.getType() != "") {
		s+= Utility::strCommaD() + Utility::strOpenBracketD() + vehicle.toString() + Utility::strCloseBracketD();
	}

	return s;
}

bool Trip::fromString(std::string s) {
	std::vector<std::string> vec = Utility::stringToVector(s, 31);
	
	try {
		std::string _departure, _destination, _startDate, _endDate;
		int _price;
		departure = vec.at(0);
		destination = vec.at(1);
		startDate = vec.at(2);
		endDate = vec.at(3);
		price = std::stoi(vec.at(4));

		Hotel tempHotel;
		if(tempHotel.fromString(Utility::stripBrackets(vec.at(5))) && tempHotel.getName() != "None") {
			hotel = tempHotel;
		}

		Vehicle tempVehicle;

		if(tempVehicle.fromString(Utility::stripBrackets(vec.at(6))) && tempVehicle.getType() != "None") {
			vehicle = tempVehicle;
		}
	}
	catch(const std::exception& e) {
		std::cout << "Can't read trip from string." << std::endl;
		return false;
	}

	return true;
}

int Trip::getTotalPrice() {
	int ret = price * Utility::dateDiff(startDate, endDate) + vehicle.getPrice() * member;
	ret += hotel.getRoomTypeList()[bookedRoomIndex].price * Utility::dateDiff(startDate, endDate) * member;
	return ret;
}

void Trip::display() {
	std::cout << std::setw(15) << std::left << departure << "|"
		<< std::setw(15) << std::left << destination << "|"
		<< std::setw(10) << std::left << startDate << "|"
		<< std::setw(10) << std::left << endDate << "|"
		<< std::setw(10) << std::left << vehicle.getType() << "|"
		<< std::setw(15) << std::left << hotel.getName() << "|"
		<< std::setw(5) << std::left << member << "|"
		<< std::setw(10) << std::left << price << "|" << std::endl;
}

int Trip::getBookedRoomIndex() {
	return bookedRoomIndex;
}

int Trip::getMember() {
	return member;
}