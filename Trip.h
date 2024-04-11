#pragma once
#include "Utility.h"
#include "Vehicle.h"
#include "Hotel.h"

class Trip {
private:
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
	void setVehicle(Vehicle _vehicle);
	void setHotel(Hotel _hotel);
	void setPrice(int price);
	void setMember(int _member);
	void setData(std::string _departure, std::string _destination, std::string _startDate, std::string _endDate, Vehicle _vehicle, Hotel _hotel, int _price, int _member, int _bookedRoomIndex);
	void display();
	int getTotalPrice();
	std::string toString();
	bool fromString(std::string s);
	int getBookedRoomIndex();
	int getMember();
};