#pragma once
#include <vector>
#include "Utility.h"
#include "Vehicle.h"
#include "Hotel.h"

class Trip {
private:
	std::string departure, destination, startDate, endDate;
	int price;
	Hotel hotel;
	Vehicle vehicle;

public:
	Trip();
	Trip(std::string _departure, std::string _destination, std::string _startDate, std::string _endDate, int _price, Hotel _hotel, Vehicle _vehicle);
	int getPrice();
	std::string getDeparture();
	std::string getDestination();
	std::string getStartDate();
	std::string getEndDate();
	Hotel getHotel();
	Vehicle getVehicle();
	void setData(std::string _departure, std::string _destination, std::string _startDate, std::string _endDate, int _price, Hotel _hotel, Vehicle _vehicle);
	std::string toString();
	bool fromString(std::string s);
};