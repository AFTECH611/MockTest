#pragma once
#include <vector>
#include "Utility.h"
#include "Vehicle.h"
#include "Hotel.h"

class Trip {
private:
	int price;
	std::string departure, destination, startDate, endDate;
	std::vector<Vehicle> vehicleList;
	std::vector<Hotel> hotelList;

public:
	Trip();
	Trip(std::string _departure, std::string _destination, std::string _startDate, std::string _endDate, int _price);
	int getPrice();
	std::string getDeparture();
	std::string getDestination();
	std::string getStartDate();
	std::string getEndDate();
	std::vector<Vehicle> getVehicleList();
	std::vector<Hotel> getHotelList();
	void setData(std::string _departure, std::string _destination, std::string _startDate, std::string _endDate, int _price);
};