#pragma once
#include "Utility.h"
#include "Vehicle.h"
#include "Hotel.h"

class Trip {
private:
	int id;
	int price;
	std::string departure, destination, startDate, endDate;
	Vehicle vehicle;
	Hotel hotel;
	int member;
	int bookedRoomIndex;

public:
	Trip();
	Trip(std::string _departure, std::string _destination, std::string _startDate, std::string _endDate, int _price, int _member);
	int getPrice();
	std::string getDeparture();
	std::string getDestination();
	std::string getStartDate();
	std::string getEndDate();
	Vehicle getVehicle();
	Hotel getHotel();
	void setData(int _id, std::string _departure, std::string _destination, std::string _startDate, std::string _endDate, Vehicle _vehicle, Hotel _hotel, int _price, int _member, int _bookedRoomIndex);
	void display();
	int getTotalPrice();
	std::string toString();
	bool fromString(std::string s);
};