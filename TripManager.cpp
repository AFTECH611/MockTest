#include "TripManager.h"
#include "DatabaseManager.h"

std::vector<Hotel> TripManager::hotels;
std::vector<Vehicle> TripManager::vehicles;

template<class T>
bool loadVector(std::string path, std::vector<T>& vec) {
    std::vector<std::string> strVec;
    DatabaseManager::readFile(path, strVec);

    try {
        for(std::string s: strVec) {
            T t;
            t.fromString(s);
            vec.push_back(t);
        }
    }
    catch(const std::exception& e) {
        std::cout << "TripManager failed to load" << std::endl;
    }
    
    return true;
}

bool TripManager::load(std::string hotelsPath, std::string vehiclesPath) {
    return loadVector<Hotel>(hotelsPath, hotels) && loadVector<Vehicle>(vehiclesPath, vehicles);
}

void TripManager::updateDatabase(std::string hotelsPath, std::string vehiclesPath) {
    DatabaseManager::clearFile(hotelsPath);
    DatabaseManager::clearFile(vehiclesPath);
    
    for(Hotel hotel: hotels) {
        DatabaseManager::appendFile(hotelsPath, hotel.toString());
    }
    
    for(Vehicle vehicle: vehicles) {
        DatabaseManager::appendFile(vehiclesPath, vehicle.toString());
    }
}

void sortHotels(){

}
void sortVehicles(){

}

void TripManager::searchHotels(){
    std::string address;
    std::cout << "Input Hotel's Address: ";
    std::cin >> address;
    std::string name;
    std::cout << "Input Hotel's Name: ";
    std::cin >> name;
    for(auto ht = hotels.begin(); ht != hotels.end(); ++ht){
        if(ht->getAddress() == address && ht->getName() == name){
            ht->display();
        }
    }
}

void TripManager::searchVehicles(){
    std::string type, brand, from, to, fromDate;
    int price;
    std::cout << "From: ";
    std::cin >> from;
    std::cout << "To: ";
    std::cin >> to;
    std::cout << "Type: ";
    std::cin >> type;
    std::cout << "Brand: ";
    std::cin >> brand;
    std::cout << "Input Start Date: ";
    std::cin >> fromDate;
    std::cout << "Input Price: ";
    std::cin >> price;
    for(auto vc = vehicles.begin(); vc != vehicles.end(); ++vc){
        if(vc->getDeparture() == from && vc->getDestination() == to && vc->getType() == type && vc->getPrice() == price && vc->getBrand() == brand && vc->getStartDate() == fromDate){
            vc->display();
        }
    }
}

void TripManager::deleteHotel(){
    std::string address;
    std::string name;
    std::cout << "Input Hotel's Address: ";
    std::cin >> address;
    std::cout << "Input Hotel's name: ";
    std::cin >> name;
    for(auto ht = hotels.begin(); ht != hotels.end(); ++ht){
        if(ht->getAddress() == address && ht->getName() == name){
            hotels.erase(ht);
            break;
        }
    }
}

void TripManager::deleteVehicle(){
    std::string type;
    std::cout << "Input vehicle type: ";
    std::cin >> type;
    std::string from;
    std::cout << "From: ";
    std::cin >> from;
    std::string to;
    std::cout << "To: ";
    std::cin >> to;
    std::string brand;
    std::cout << "Input Vehicle's brand: ";
    std::cin >> brand;
    int price;
    std::cout << "Input price: ";
    std::cin >> price;
    std::string fromDate;
    std::cout << "Input start date: ";
    std::cin >> fromDate;
    std::string toDate;
    for(auto vc = vehicles.begin(); vc != vehicles.end(); ++vc){
        if(vc->getDeparture() == from && vc->getDestination() == to && vc->getBrand() == brand && vc->getPrice() == price && vc->getType() == type && vc->getStartDate() == fromDate){
            vehicles.erase(vc);
            break;
        }
    }
}

void TripManager::addHotel(){
    std::string name, address;
    int numbOfType;
    std::vector<Room> roomList;
    std::cout << "Hotel name: " ;
    std::cin >> name;
    std::cout << "Hotel address: ";
    std::cin >> address;
    std::cout << "Input number of room's type: ";
    std::cin >> numbOfType;
    for (int i = 0; i < numbOfType; i ++){
        std::cout << "Room type " << i + 1 << ": " << std::endl; 
        std::string type;
        int available, price;
        std::cout << "Room type: ";
        std::cin >> type;
        std::cout << "Available: ";
        std::cin >> available;
        std::cout << "Price: "; 
        std::cin >> price;
        Room newRoom;
        newRoom.type = type;
        newRoom.available = available;
        newRoom.price = price;
        roomList.push_back(newRoom);
    }
    Hotel newHotel(address, name, numbOfType, roomList);
    hotels.push_back(newHotel);
    std::cout << "New hotel has been created successfully!" << std::endl;
}

void TripManager::addVehicle(){
    std::string type, brand, from, to, fromDate, toDate;
    int price;
    std::cout << "Input type (Taxi/Airplane): ";
    std::cin >> type;
    std::cout << "Input brand: ";
    std::cin >> brand;
    std::cout << "From: ";
    std::cin >> from;
    std::cout << "To: ";
    std::cin >> to;
    std::cout << "Input Start Date: ";
    std::cin >> fromDate;
    std::cout << "Input End Date: ";
    std::cin >> toDate;
    std::cout << "Input Price: ";
    std::cin >> price;
    Vehicle newVehicle(type, brand, from, to, fromDate, toDate, price);
    vehicles.push_back(newVehicle);
    std::cout << "New " << type << "has been created successfully!" << std::endl;
}

void TripManager::displayHotels(){
    for(Hotel h : hotels){
        h.display();
    }
}
void TripManager::displayVehicles(){
    for(Vehicle v : vehicles){
        v.display();
    }
}
