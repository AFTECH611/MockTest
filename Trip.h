#pragma once
#include <vector>
#include "Utility.h"
#include "Vehicle.h"
#include "Hotel.h"

class Trip {
private:
	int price;
	string departure, destination, startDate, endDate;
	vector<Vehicle> vehicleList;
	vector<Hotel> hotelList;

public:
	Trip();
	Trip(string _departure, string _destination, string _startDate, string _endDate, int _price);
	int getPrice();
	string getDeparture();
	string getDestination();
	string getStartDate();
	string getEndDate();
	vector<Vehicle> getVehicleList();
	vector<Hotel> getHotelList();
	void setData(string _departure, string _destination, string _startDate, string _endDate, int _price);
};