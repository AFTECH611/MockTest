#pragma once
#include "Utility.h"
#include <vector>

struct room {
	std::string type;
	int available;
	int price;
};

class Hotel {
private:
	std::string address;
	std::string name;
	int numbOfTypeRoom;
	std::vector<room> roomTypeList;

public:

	Hotel();
	Hotel(std::string _address, std::string _name, int _numbOfTypeRoom, std::vector<room> _roomTypeList);
	std::string getAddress();
	std::string getName();
	std::vector<room> getRoomTypeList();
	void minusRoom(int member, std::string type);
	void setData(std::string _address, std::string _name, int _numbOfTypeRoom, std::vector<room> _roomTypeList);
	void display();
	void showRoomType();
	std::string toString();
	bool fromString(std::string s);
};