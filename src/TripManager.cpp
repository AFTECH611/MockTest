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

bool TripManager::compareDateV(Vehicle &a, Vehicle &b){
    return a>b;
}

bool TripManager::comparePriceV(Vehicle &a, Vehicle &b){
    return a.getPrice()<b.getPrice();
}

bool TripManager::comparePriceH(Hotel &a, Hotel &b){
    return a.getMinPrice() < b.getMinPrice();
}

bool TripManager::compareAddressH(Hotel &a, Hotel &b){
    return a.getAddress() < b.getAddress();
}

void TripManager::sortHotelByPrice(){
    std::sort(hotels.begin(), hotels.end(), comparePriceH);
}

void TripManager::sortHotelByAddress(){
    std::sort(hotels.begin(), hotels.end(), compareAddressH);
}

void TripManager::sortVehicleByPrice(){
    std::sort(vehicles.begin(), vehicles.end(), comparePriceV);
}


void TripManager::sortVehicleByDate(){
    std::sort(vehicles.begin(), vehicles.end(), compareDateV);
}

void TripManager::searchHotels(){
    std::string address;
    std::cout << "Input Hotel's Address: ";
    std::cin >> address;
    std::string name;
    std::cout << "Input Hotel's Name: ";
    std::cin >> name;
    bool found = false;
    std::cout << "|========================+Search HOTELS+=====================|" << std::endl;
    std::cout << "|____________________________________________________________|" << std::endl;
    std::cout << "|     Hotel     |     Address     |  Room type |    Price    |" << std::endl;
    std::cout << "|_______________|_________________|____________|_____________|" << std::endl;
    for(auto ht = hotels.begin(); ht != hotels.end(); ++ht){
        if(ht->getAddress() == address && ht->getName() == name){
            found = true;
            ht->display();
        }
    }
    if(!found) std::cout << "|......System cannot find your Hotel! Please try another!....|" << std::endl;
    std::cout << "|_______________|_________________|____________|_____________|" << std::endl;
}

void TripManager::searchVehicles(){
    displayVehicles();
    std::string type;
    std::cout << "Type (Car/Flight): ";
    std::cin >> type;
    std::string fromDate;
    std::cout << "Input Start date: ";
    std::cin>>fromDate;
    while(!Utility::isValidDate(fromDate)){
        std::cout << "Invalid date input!Try again: ";
        std::cin >> fromDate;
    }
    bool found = false;
    std::cout << "|===========================================+Search VEHICLES+===================================================|" << std::endl;
    std::cout << "|_______________________________________________________________________________________________________________|" << std::endl;
    std::cout << "| Vehicle Type  |     Brand     |    Departure    |   Destination    | Departure Date |  Arrival Date  |  Cost  |" << std::endl;
    std::cout << "|_______________|_______________|_________________|__________________|________________|________________|________|" << std::endl;
    for(auto vc = vehicles.begin(); vc != vehicles.end(); ++vc){
        if(vc->getType() == type && vc->getStartDate() == fromDate){
            vc->display();
            found = true;
        }
    }
    if(!found) std::cout << "|.............................System cannot find your transport! Please try another!............................|" << std::endl;
    std::cout << "|_______________|_______________|_________________|__________________|________________|________________|________|" << std::endl;
}

void TripManager::deleteVehicle(){
    displayVehicles();
    std::string command;
    std::cout << "Choose a vehicle that you want to delete (from 1 - " << vehicles.size() << ").\n";
    std::cin >> command;
    while(Utility::isValidInt(command) && std::stoi(command) > vehicles.size()){
        std::cout << "Vehicle " << command << " is not in the Vehicle list, please pick again: ";
        std::cin >> command;
    } 
    int cmd = std::stoi(command)-1;
    std::cout << "|============================================+Edit VEHICLES+====================================================|" << std::endl;
    std::cout << "|_______________________________________________________________________________________________________________|" << std::endl;
    std::cout << "| Vehicle Type  |     Brand     |    Departure    |   Destination    | Departure Date |  Arrival Date  |  Cost  |" << std::endl;
    std::cout << "|_______________|_______________|_________________|__________________|________________|________________|________|" << std::endl;
    vehicles.at(cmd).display();
    std::cout << "|_______________|_______________|_________________|__________________|________________|________________|________|" << std::endl;
    std::cout << "Do you sure want to delete this vehicle from list?\n";
    std::cout << "1.Yes   2.No\n";
    std::cout << "Take an action(1-2):\n";
    int action = Utility::getCommandFromCLI();
    switch (action) {
        case(1): 
        {
            vehicles.erase(vehicles.begin()+cmd);
            std::cout << "Delete vehicle success!\n";
            Utility::delay();
            system("cls");
            break;
        }
        case(2): 
        {
            std::cout << "Returning to previous page!\n";
            Utility::delay();
            system("cls");
            break;
        }
        default:
            std::cout << "Invalid option! Returning..." << std::endl;
            Utility::delay();
            system("cls");
            break;
    }
}

void TripManager::deleteHotel(){
    displayHotels();
    std::string command;
    std::cout << "Choose a Hotel that you want to delete (from 1 - " << hotels.size() << ").\n";
    std::cin >> command;
    while(Utility::isValidInt(command) && std::stoi(command) > hotels.size()){
        std::cout << "Hotel " << command << " is not in the Hotel list, please pick again: ";
        std::cin >> command;
    } 
    int cmd = std::stoi(command)-1;
    std::cout << "|========================+Search HOTELS+=====================|" << std::endl;
    std::cout << "|____________________________________________________________|" << std::endl;
    std::cout << "|     Hotel     |     Address     |  Room type |    Price    |" << std::endl;
    std::cout << "|_______________|_________________|____________|_____________|" << std::endl;
    hotels.at(cmd).display();
    std::cout << "|_______________|_________________|____________|_____________|" << std::endl;
    std::cout << "Do you sure want to delete this hotel from list?\n";
    std::cout << "1.Yes   2.No\n";
    std::cout << "Take an action(1-2):\n";
    int action = Utility::getCommandFromCLI();
    switch (action) {
        case(1): 
        {
            hotels.erase(hotels.begin()+cmd);
            std::cout << "Delete hotel success!\n";
            Utility::delay();
            system("cls");
            break;
        }
        case(2): 
        {
            std::cout << "Returning to previous page!\n";
            Utility::delay();
            system("cls");
            break;
        }
        default:
            std::cout << "Invalid option! Returning..." << std::endl;
            Utility::delay();
            system("cls");
            break;
    }
}

void TripManager::addHotel(){
    std::string name, address;
    int numbOfType; std::cin.ignore();
    std::vector<Room> roomList;
    std::cout << "Hotel name: " ;
    getline(std::cin, name);
    while (!Utility::isValidName(name)){
        std::cout << "Invalid name, try: "; getline(std::cin, name);
    }
    std::cout << "Hotel address: ";
    getline(std::cin, address);
    while (!Utility::isValidName(address)){
        std::cout << "Invalid address, try: "; getline(std::cin, address);
    }
    std::cout << "Input number of room's type: ";
    std::cin >> numbOfType;
    while (!Utility::isValidInt(std::to_string(numbOfType))){

    }
    for (int i = 0; i < numbOfType; i ++){
        std::cout << "Room type " << i + 1 << ": " << std::endl; 
        std::string type;
        int available, price;
        std::cout << "Room type: ";
        std::cin.ignore();
        getline(std::cin, type);
        while (!Utility::isValidPlace(type)){
            std::cout << "Invalid type, try: "; getline(std::cin, type);
        }
        std::cout << "Available: ";
        available = Utility::getCommandFromCLI();
        std::cout << "Price: "; 
        price = Utility::getCommandFromCLI();
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
    std::string type, brand, from, to, fromDate, toDate, price;
    std::cout << "Input type (Car/Flight): ";
    std::cin >> type;
    while(type != "Car" && type != "Flight"){
        std::cout << "Only Car or Flight: ";
        std::cin >> type;
    }
    std::cout << "Input brand: ";
    std::cin.ignore();
    getline(std::cin, brand);
    while (!Utility::isValidName(brand))
    {
        getline(std::cin, brand);
    }
    std::cout << "From: ";
    getline(std::cin, from);
    while(!Utility::isValidPlace(from)){
        std::cout << "Input again: ";
        getline(std::cin, from);
    }
    std::cout << "To: ";
    getline(std::cin, to);
    while(!Utility::isValidPlace(to)){
        std::cout << "Input again: ";
        getline(std::cin, to);
    }
    std::cout << "Input Start Date: ";
     getline(std::cin, fromDate);
    while(!Utility::isValidDate(fromDate)){
        std::cout << "Invalid date input!Try again: ";
        getline(std::cin, fromDate);
    }
    std::cout << "Input End Date: ";
    getline(std::cin, toDate);
    //std::cout << "test valid date: "<< Utility::dateDiff1(fromDate, toDate) << std::endl;
    while(!Utility::isValidDate(toDate) || Utility::dateDiff1(fromDate, toDate) < 0){
        std::cout << "Invalid end date!Try again: ";
        getline(std::cin, toDate);
    }
    std::cout << "Input Price: ";
    std::cin >> price;
    while(!Utility::isValidPrice(price)){
        std::cout << "Invalid price input!Try again: ";
        std::cin >> price;
    }
    Vehicle newVehicle(type, brand, from, to, fromDate, toDate, std::stoi(price));
    vehicles.push_back(newVehicle);
    std::cout << "New " << type << " has been created successfully!" << std::endl;
}

void TripManager::displayHotels(){
    std::cout << " |=======================+LIST HOTELS+========================|" << std::endl;
    std::cout << " |____________________________________________________________|" << std::endl;
    std::cout << "#|     Hotel     |     Address     |  Room type |    Price    |" << std::endl;
    std::cout << " |_______________|_________________|____________|_____________|" << std::endl;
    int i = 0;
    for(Hotel h : hotels){
        std::cout << ++i;
        h.display();
    }
    std::cout << "  |_______________|_________________|____________|_____________|" << std::endl;
}
void TripManager::displayVehicles(){
    std::cout << " |============================================+LIST VEHICLES+====================================================|" << std::endl;
    std::cout << " |_______________________________________________________________________________________________________________|" << std::endl;
    std::cout << "#| Vehicle Type  |     Brand     |    Departure    |   Destination    | Departure Date |  Arrival Date  |  Cost  |" << std::endl;
    std::cout << " |_______________|_______________|_________________|__________________|________________|________________|________|" << std::endl;
    int i = 0;
    for(Vehicle v : vehicles){
        std::cout << ++i;
        v.display();
    }
    std::cout << "  |_______________|_______________|_________________|__________________|________________|________________|________|" << std::endl;
}

void TripManager::editVehicle(){
    displayVehicles();
    std::string command;
    std::cout << "Choose a vehicle that you want to edit (from 1 - " << vehicles.size() << ").\n";
    std::cin >> command;
    while(Utility::isValidInt(command) && std::stoi(command) > vehicles.size()){
        std::cout << "Vehicle " << command << " is not in the Vehicle list, please pick again: ";
        std::cin >> command;
    } 
    int cmd = std::stoi(command)-1;
    std::cout << "|============================================+Edit VEHICLES+====================================================|" << std::endl;
    std::cout << "|_______________________________________________________________________________________________________________|" << std::endl;
    std::cout << "| Vehicle Type  |     Brand     |    Departure    |   Destination    | Departure Date |  Arrival Date  |  Cost  |" << std::endl;
    std::cout << "|_______________|_______________|_________________|__________________|________________|________________|________|" << std::endl;
    vehicles.at(cmd).display();
    std::cout << "|_______________|_______________|_________________|__________________|________________|________________|________|" << std::endl;
    std::cout << "1.Edit brand   2.Edit Start date and End date   3.Edit Departure    4.Edit Destination   5.Edit price   6.Back\n";
    std::cout << "Take an action(1-7)\n";
    int action = Utility::getCommandFromCLI();
    switch (action) {
        case(1): {
            std::string _name;
            std::cout << "New brand: ";
            std::cin.ignore(); getline(std::cin, _name);
            while (!Utility::isValidName(_name)) {
                std::cout << "New brand: ";
                getline(std::cin, _name);
            }
            vehicles.at(cmd).setBrand(_name);
            std::cout << "Edit brand success!\n";
            Utility::delay();
            system("cls");
            break;
        }
        case(2): {
            std::string sdate;
            std::string edate;
            std::cout << "New start date: ";
            std::cin >> sdate;
            while (!Utility::isValidDate(sdate)) {
                std::cout << "New start date: ";
                std::cin >> sdate;
            }
            std::cout << "New end date: ";
            std::cin >> edate;
            while (!Utility::isValidDate(edate) || Utility::dateDiff1(sdate, edate) < 0) {
                std::cout << "Invalid End date! Input end date: ";
                std::cin >> edate;
            }
            vehicles.at(cmd).setStartDate(sdate);
            vehicles.at(cmd).setEndDate(edate);
            std::cout << "Edit Start date and Arrival date success!\n";
            Utility::delay();
            system("cls");
            break;
        }
        case(3): {
            std::string _name;
            std::cout << "New departure: ";
            std::cin.ignore(); getline(std::cin, _name);
            while (!Utility::isValidName(_name)) {
                std::cout << "New departure: ";
                getline(std::cin, _name);
            }
            vehicles.at(cmd).setDeparture(_name);
            std::cout << "Edit departure success!\n";
            Utility::delay();
            system("cls");
            break;
        }
        case(4): {
            std::string _name;
            std::cout << "New destination: ";
            std::cin.ignore(); getline(std::cin, _name);
            while (!Utility::isValidName(_name)) {
                std::cout << "New destination: ";
                getline(std::cin, _name);
            }
            vehicles.at(cmd).setDeparture(_name);
            std::cout << "Edit destination success!\n";
            Utility::delay();
            system("cls");
            break;
        }
        case(5): {
            std::string price;
            std::cout << "New price: ";
            std::cin >> price;
            while (!Utility::isValidInt(price)) {
                std::cout << "New brand: ";
                std::cin >> price;
            }
            vehicles.at(cmd).setPrice(std::stoi(price));
            std::cout << "Edit price success!\n";
            Utility::delay();
            system("cls");
            break;
        }
        default: {
            std::cout << "Invalid option! Returning..." << std::endl;
            Utility::delay();
            system("cls");
            break;
        }
    }
}

void TripManager::editHotel(){
    displayHotels();
    std::string command;
    std::cout << "Choose a Hotel that you want to edit (from 1 - " << hotels.size() << ").\n";
    std::cin >> command;
    while(Utility::isValidInt(command) && std::stoi(command) > hotels.size()){
        std::cout << "Hotel " << command << " is not in the Hotel list, please pick again: ";
        std::cin >> command;
    } 
    int cmd = std::stoi(command)-1;
    std::cout << "|========================+Edit HOTELS+=======================|" << std::endl;
    std::cout << "|____________________________________________________________|" << std::endl;
    std::cout << "|     Hotel     |     Address     |  Room type |    Price    |" << std::endl;
    std::cout << "|_______________|_________________|____________|_____________|" << std::endl;
    hotels.at(cmd).display();
    std::cout << "|_______________|_________________|____________|_____________|" << std::endl;
    std::cout << "1.Edit name   2.Edit address\n";
    std::cout << "Take an action(1-2)\n";
    int action = Utility::getCommandFromCLI();
    switch (action) {
        case(1): {
            std::string _name;
            std::cout << "New Hotel's name: ";
            std::cin.ignore(); getline(std::cin, _name);
            while (!Utility::isValidName(_name)) {
                std::cout << "New Hotel's name: ";
                getline(std::cin, _name);
            }
            hotels.at(cmd).setName(_name);
            std::cout << "Edit Hotel's name success!\n";
            Utility::delay();
            system("cls");
            break;
        }
        case(2): {

            std::string address;
            std::cout << "New Hotel's address: ";
            std::cin >> address;
            while (!Utility::isValidPlace(address)) {
                std::cout << "New Hotel's address: ";
                std::cin >> address;
            }
            hotels.at(cmd).setAddress(address);
            std::cout << "Edit Hotel's address success!\n";
            Utility::delay();
            system("cls");
            break;
        }
        default: {
            std::cout << "Invalid option! Returning..." << std::endl;
            Utility::delay();
            system("cls");
            break;
        }
    }
}
