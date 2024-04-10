#pragma once
#include "Utility.h"

struct Room {
	std::string type;
	int available;
	int price;
};

class Hotel {
private:
	std::string address;
	std::string name;
	int numbOfTypeRoom;
	std::vector<Room> roomTypeList;

public:
	Hotel();
	Hotel(std::string _address, std::string _name, int _numbOfTypeRoom, std::vector<Room> _roomTypeList);
	std::string getAddress();
	std::string getName();
	std::vector<Room> getRoomTypeList();
	void minusRoom(int member, std::string type);
	void setData(std::string _address, std::string _name, int _numbOfTypeRoom, std::vector<Room> _roomTypeList);
	void display();
	void showRoomType();
	std::vector<Room> searchRoom(std::string type, int available, int price);
	std::string toString();
	bool fromString(std::string s);
};