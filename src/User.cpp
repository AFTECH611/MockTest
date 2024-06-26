#include "User.h"

User::User() {
    username = password = name = address = "None";
    age = 0;
}

User::User(std::string _username, std::string _password, std::string _name, std::string _address, int _age, std::vector<Trip> _bookedTrips) {
    username = _username;
    password = _password;
    name = _name;
    address = _address;
    age = _age;
    bookedTrips = _bookedTrips;
}

const std::string& User::getName()  {
    return name;
}

void User::setName(std::string _name) {
    name = _name;
}

const std::string& User::getAddress()  {
    return address;
}

void User::setAddress(std::string addr) {
    address = addr;
}

const int& User::getAge()  {
    return age;
}

void User::setAge(int a) {
    age = a;
}

const std::vector<Trip>& User::getBookedTrips() {
    return bookedTrips;
}

std::string User::toString() {
    // format: 0,username,password,name,address,age,[bookedTrips[0]],[bookedTrips[1]],...
    std::string s = "0" + Utility::strCommaD() + username + Utility::strCommaD() + password + Utility::strCommaD() + 
                    name + Utility::strCommaD() + address + Utility::strCommaD() + std::to_string(age);
    for(Trip t: bookedTrips) {
        s+=Utility::strCommaD() + Utility::strOpenBracketD() + t.toString() + Utility::strCloseBracketD();
    }
    return s;
}

bool User::fromString(std::string s) {
    std::vector<std::string> vec = Utility::stringToVector(s, 31);
    try {
        if(vec.at(0) != "0") return false;
        type = "user";
        username = vec.at(1);
        password = vec.at(2);
        name = vec.at(3);
        address = vec.at(4);
        age = stoi(vec.at(5));
        for(int i = 6; i < vec.size(); i++) {
            Trip tempTrip;

            if(tempTrip.fromString(Utility::stripBrackets(vec.at(i)))) {
                std::string strRoom = vec[i];
                bookedTrips.push_back(tempTrip);
            }
        }
    }
    catch(const std::exception& e) {
        std::cout << "Can't read user from string" << std::endl;
        return false;
    }

    return true;
}

void User::addNewItinerary(Trip newTrip) {
    bookedTrips.push_back(newTrip);
}

const std::vector<std::string> User::getCommandsList() {
    //system("cls");
    return std::vector<std::string>{"1 - View profile",
        "2 - View Trip available",
        "3 - Make itinerary", 
        "4 - List my itinerary",
        "5 - Cancel itinerary",
        "6 - Logout"};
}

std::vector<std::string> User::getCommandListAfterViewProfile() {
    return std::vector<std::string>{"1 - Edit profile", 
        "2 - Edit account", 
        "3 - Return"};
}

std::vector<std::string> User::getCommandListAfterMakeItinerary() {
    return std::vector<std::string>{"1 - Choose vehicle",
        "2 - Choose hotel",
        "3 - Done",
        "4 - Return"};
}

std::vector<std::string> User::getCommandListEditProfile() {
    return std::vector<std::string>{"1 - Name",
        "2 - Address",
        "3 - Age",
        "4 - Return"};
}

std::vector<std::string> User::getCommandListEditAccount() {
    return std::vector<std::string>{"1 - Password",
        "2 - Return"};
}

void User::executeCommand(int command) {
    switch (command) {
    case(1): {
        viewProfile();
        break;
    }
    case(2): {
        viewTrip();
        break;
    }
    case(3): {
        makeItinerary();
        break;
    }
    case(4): {
        showItinerary();
        break;
    }
    case(5): {
        cancelItinerary();
        break;
    }
    case(6): {
        AccountManager::setCurrentAccount();
        break;
    }
    default: {
        std::cout << "Invalid option" << std::endl;
    }
    }
}
void User::viewTrip() {
    std::cout << "|================+LIST All TRIPs+=================|" << std::endl;
    std::cout << "|_________________________________________________|" << std::endl;
    std::cout << "|   Departure   |  Destination | Departure Date   |" << std::endl;
    std::cout << "|_______________|______________|__________________|" << std::endl;
    for(Vehicle v : TripManager::vehicles){
            std::cout << "|" << std::setw(15) << std::left << v.getDeparture() << "|"
		<< std::setw(15) << std::left << v.getDestination() << "|"
		<< std::setw(17) << std::left << v.getStartDate() << "|" << std::endl;
    }
    std::cout << "|_______________|______________|__________________|" << std::endl;
}
void User::viewProfile() {
    std::cout << ".___________________________________________________________________________________." << std::endl;
    std::cout << "|      Account       |   Full Name         |  Address              |  Age           |" << std::endl;
    std::cout << "|____________________|_____________________|_______________________|________________|" << std::endl;
    this->display();
    std::cout << "|____________________|_____________________|_______________________|________________|" << std::endl;
    Utility::printVector(getCommandListAfterViewProfile());
    int command; command = Utility::getCommandFromCLI();
    switch (command) {
    case(1): {
        Utility::printVector(getCommandListEditProfile());
        command = Utility::getCommandFromCLI();
        editProfile(command);
        break;
    }
    case(2): {
        Utility::printVector(getCommandListEditAccount());
        command = Utility::getCommandFromCLI();
        editAccount(command);
        break;
    }
    case(3): {
        system("cls");
        break;
    }
    default: {
        std::cout << "Invalid option" << std::endl;
    }
    }
}

void User::display() {
    std::cout << "|" << std::setw(20) << std::left << username << "| " << std::setw(20) << std::left << name << "| "  << std::setw(22) << std::left << address << "| " << std::setw(15) << std::right << age << "|" << std::endl;
}

void User::editProfile(int command) {
    switch (command) {
    case(1): {
        std::string _name;
        std::cout << "New name: ";
        std::cin.ignore(); getline(std::cin, _name);
        while (!Utility::isValidName(_name)) {
            std::cout << "New name: ";
            getline(std::cin, _name);
        }
        name = _name;
        system("cls");
        break;
    }
    case(2): {
        std::string _address;
        std::cout << "Address: ";
        std::cin.ignore(); getline(std::cin, _address);
        address = _address;
        system("cls");
        break;
    }
    case(3): {
        age = Utility::inputAge();
        system("cls");
        break;
    }
    case(4): {
        system("cls");
        Utility::printVector(getCommandListAfterViewProfile());
        int command; command = Utility::getCommandFromCLI();
        break;
    }
    default: {
        std::cout << "Invalid option" << std::endl;
        Utility::delay();
        system("cls");
        break;
    }
    }
}

void User::editAccount(int command) {
    switch (command) {
    case(1): {
        std::string _password; std::cin.ignore();
        std::cout << "New password: ";
        getline(std::cin, _password);
        while (!Utility::isValidPassword(_password)) {
            std::cout << "New password: ";
            getline(std::cin, _password);
        }
        password = _password;
    }
    case(2): {
        break;
    }
    default: {
        std::cout << "Invalid option" << std::endl;
        Utility::delay();
        system("cls");
        break;
    }
    }
}

void User::ItineraryDetail(Vehicle choosedVehicle, Hotel choosedHotel, std::string from, std::string to, std::string sDate, int member) {
    Utility::printVector(getCommandListAfterMakeItinerary());
    Trip trip;
    int roomIdx = 0;
    int command = Utility::getCommandFromCLI();
    switch (command) {
    case(1): {
        system("cls");
        displayBasicItineraryInfo(from, to, sDate);
        choosedVehicle = chooseVehicle(from, to, sDate);
        ItineraryDetail(choosedVehicle, choosedHotel, from, to, sDate, member);
        break;
    }
    case(2): {
        system("cls");
        displayBasicItineraryInfo(from, to, sDate);
        choosedHotel = chooseHotel(to, member);
        if (choosedHotel.getName() != "None") {
            choosedHotel.showRoomType();
            int option = Utility::getCommandFromCLI();
            while (option <= 0 || option > choosedHotel.getNumbOfRoomType()) {
                std::cout << "Invalid option, try: "; option = Utility::getCommandFromCLI();
            }
            while (choosedHotel.getRoomTypeList()[option - 1].available < member){
                std::cout << "This room type doesn't have enough room available for your all member" << std::endl;
                std::cout << "Please choose another room type or 0 to choose another hotel";
                option = Utility::getCommandFromCLI();
                if (option == 0) {
                    break;
                }
            }
            if (option != 0) {
                roomIdx = option - 1;
                for (int i = 0; i < TripManager::hotels.size(); i++) {
                    if (TripManager::hotels[i].getName() == choosedHotel.getName()) {
                        TripManager::hotels[i].minusRoom(member, TripManager::hotels[i].getRoomTypeList()[option - 1].type);
                        int a = 0;
                    }
                }
                std::cout << "Book completed, you can check your booked itinerary in option 3" << std::endl;
                Utility::delay();
                Utility::delay();
                system("cls");
            }
        }
        ItineraryDetail(choosedVehicle, choosedHotel, from, to, sDate, member);
        break;
    }
    case(3): {
        if (choosedHotel.getName() == "None") {
            std::cout << "No hotel selected" << std::endl;
            break;
        }
        else if (choosedVehicle.getBrand() == "None") {
            std::cout << "No vehicle selected" << std::endl;
        }
        else {
            trip.setData(choosedVehicle.getDeparture(), choosedVehicle.getDestination(), choosedVehicle.getStartDate(), choosedVehicle.getEndDate(),
                choosedVehicle, choosedHotel, 0, member, roomIdx);
            int totalPrice = trip.getTotalPrice();
            bookedTrips.push_back(trip);
        }
        break;
    }
    case(4): {
        system("cls");
        break;
    }
    default: {
        std::cout << "Invalid option, try: "; command = Utility::getCommandFromCLI();
    }
    }
}

void User::cancelItinerary() {
    if (bookedTrips.size() != 0) {
        std::cout << std::setw(5) << std::left << "ID" << "|"
            << std::setw(10) << std::left << "From" << "|"
            << std::setw(10) << std::left << "To" << "|"
            << std::setw(10) << std::left << "Start" << "|"
            << std::setw(10) << std::left << "End" << "|"
            << std::setw(15) << std::left << "Vehicle type" << "|"
            << std::setw(15) << std::left << "Hotel" << "|"
            << std::setw(10) << std::left << "Total price" << "|" << std::endl;
        for (int i = 0; i < bookedTrips.size(); i++) {
            std::cout << std::setw(5) << std::left << i + 1 << "|"
                << std::setw(10) << std::left << bookedTrips[i].getDeparture() << "|"
                << std::setw(10) << std::left << bookedTrips[i].getDestination() << "|"
                << std::setw(10) << std::left << bookedTrips[i].getStartDate() << "|"
                << std::setw(10) << std::left << bookedTrips[i].getEndDate() << "|"
                << std::setw(15) << std::left << bookedTrips[i].getVehicle().getType() << "|"
                << std::setw(15) << std::left << bookedTrips[i].getHotel().getName() << "|"
                << std::setw(10) << std::left << bookedTrips[i].getTotalPrice() << "|" << std::endl;
        }
        std::cout << "Choose itinerary to cancel. ";
        int option = Utility::getCommandFromCLI();
        while (option <= 0 || option > bookedTrips.size()) {
            std::cout << "Invalid option, try: "; option = Utility::getCommandFromCLI();
        }
        std::string hotelName = bookedTrips[option - 1].getHotel().getName();
        int roomIdx = bookedTrips[option - 1].getBookedRoomIndex();
        for (int i = 0; i < TripManager::hotels.size(); i++) {
            if (TripManager::hotels[i].getName() == hotelName) {
                TripManager::hotels[i].returnRoom(roomIdx, bookedTrips[option - 1].getMember());
            }
        }
        bookedTrips.erase(bookedTrips.begin() + (option - 1));
        std::cout << "Itinerary cancelled" << std::endl;
        Utility::delay();
        system("cls");
    }
    else {
        std::cout << "You have no itinerary booked to cancel" << std::endl;
    }
}

void User::makeItinerary() {
    std::string from, to, sDate, sMember;
    Vehicle choosedVehicle;
    Hotel choosedHotel;
    system("cls");
    std::cout << "Enter your itinerary information" << std::endl;
    std::cin.ignore();
    std::cout << "From: "; getline(std::cin, from);
    while (!Utility::isValidPlace(from)) {
        std::cout << "Invalid place type, try: "; getline(std::cin, from);
    }
    std::cout << "To: "; getline(std::cin, to);
    while (!Utility::isValidPlace(to)) {
        std::cout << "Invalid place type, try: "; getline(std::cin, to);
    }
    std::cout << "From date: "; getline(std::cin, sDate);
    while (!Utility::isValidDate(sDate)) {
        std::cout << "Invalid date, try: "; getline(std::cin, sDate);
    }
    std::cout << "Member: "; getline(std::cin, sMember);
    while (!Utility::isValidInt(sMember)) {
        std::cout << "Inlvaid type, try: ", getline(std::cin, sMember);
    }
    int member = std::stoi(sMember);
    ItineraryDetail(choosedVehicle, choosedHotel, from, to, sDate, member);
}

Vehicle User::chooseVehicle(std::string from, std::string to, std::string sDate) {
    TripManager tripManager;
    std::vector<Vehicle> availableVehicle;
    for (int i = 0; i < tripManager.vehicles.size(); i++) {
        if (tripManager.vehicles[i].getEndDate() == sDate && 
            tripManager.vehicles[i].getDeparture() == from &&
            tripManager.vehicles[i].getDestination() == to) {
            availableVehicle.push_back(tripManager.vehicles[i]);
        }
    }
    Utility::printVector(std::vector<std::string>{"1 - Flight", "2 - Car", "3 - Return"});
    Vehicle temp;
    temp.setData("None", "None", "None", "None", "NN/NN/NNNN", "NN/NN/NNNN", 0);
    int command = Utility::getCommandFromCLI();
    switch (command) {
    case(1): {
        std::vector<Vehicle> flight;
        for (int i = 0; i < availableVehicle.size(); i++) {
            if (availableVehicle[i].getType() == "Flight") {
                flight.push_back(availableVehicle[i]);
            }
        }
        if (flight.size() != 0) {
            std::cout << "Available flight: " << std::endl;
            std::cout << std::setw(2) << std::left << "ID" << "|"
                << std::setw(10) << std::left << "Type" << "|"
                << std::setw(10) << std::left << "Brand" << "|"
                << std::setw(15) << std::left << "Departure" << "|"
                << std::setw(15) << std::left << "Destination" << "|"
                << std::setw(10) << std::left << "Start Date" << "|"
                << std::setw(10) << std::left << "End Date" << "|"
                << std::setw(10) << std::left << "Price" << "|" << std::endl;
            for (int i = 0; i < flight.size(); i++) {
                std::cout << std::setw(2) << std::left << i + 1 << "|";
                flight[i].display();
            }
        }
        else {
            std::cout << "No flight available for this departure and destination!" << std::endl;
            Utility::delay();
            return temp;
        }
        int option = Utility::getCommandFromCLI();
        while (option <= 0 || option > flight.size()) {
            std::cout << "Invalid option, try: "; option = Utility::getCommandFromCLI();
        }
        return flight[option - 1];
        break;
    }
    case(2): {
        std::vector<Vehicle> car;
        for (int i = 0; i < availableVehicle.size(); i++) {
            if (availableVehicle[i].getType() == "Car") {
                car.push_back(availableVehicle[i]);
            }
        }
        if (car.size() != 0) {
            std::cout << "Available car: " << std::endl;
            std::cout << std::setw(2) << std::left << "ID" << "|"
                << std::setw(10) << std::left << "Type" << "|"
                << std::setw(10) << std::left << "Brand" << "|"
                << std::setw(15) << std::left << "Departure" << "|"
                << std::setw(15) << std::left << "Destination" << "|"
                << std::setw(10) << std::left << "Start Date" << "|"
                << std::setw(10) << std::left << "End Date" << "|"
                << std::setw(10) << std::left << "Price" << "|" << std::endl;
            for (int i = 0; i < car.size(); i++) {
                std::cout << std::setw(2) << std::left << i + 1 << "|";
                car[i].display();
            }
        }
        else {
            std::cout << "No car available for this departure and destination!" << std::endl;
            return temp;
        }
        int option = Utility::getCommandFromCLI();
        while (option <= 0 || option > car.size()) {
            std::cout << "Invalid option, try: "; option = Utility::getCommandFromCLI();
            
        }
        return car[option - 1];
        break;
    }
    case(3): {
        return temp;
        break;
    }
    default: {
        std::cout << "Invalid option, try: "; command = Utility::getCommandFromCLI();
        break;
    }
    }
    return Vehicle();
}

Hotel User::chooseHotel(std::string to, int member) {
    std::vector<Hotel> availableHotel;
    for (Hotel i : TripManager::hotels) {
        if (i.getAddress() == to && i.getOverallRoom() > 0) {
            availableHotel.push_back(i);
        }
    }
    if (availableHotel.size() != 0) {
        std::cout << std::setw(5) << std::left << "ID" << "|"
            << std::setw(15) << std::left << "Name" << "|"
            << std::setw(5) << std::left << "Available" << "|"
            << std::setw(5) << std::left << "Min Price" << std::endl;
        for (int i = 0; i < availableHotel.size(); i++) {
            std::cout << std::setw(5) << std::left << i + 1 << "|"
                << std::setw(15) << std::left << availableHotel[i].getName() << "|"
                << std::setw(5) << std::left << availableHotel[i].getOverallRoom() << "|"
                << std::setw(5) << std::left << availableHotel[i].getMinPrice() << std::endl;
        }
        int option = Utility::getCommandFromCLI();
        while (option <= 0 || option > availableHotel.size()) {
            std::cout << "Invalid option, try: "; option = Utility::getCommandFromCLI();
        }
        return availableHotel[option - 1];
    }
    else {
        std::cout << "No hotel available for this destination" << std::endl;
        return Hotel();
    }
}

void User::showItinerary() {
    std::cout << "Booked trip of " << name << ":" << std::endl;
    if (bookedTrips.size() != 0) {
        std::cout << std::setw(5) << std::left << "ID" << "|"
            << std::setw(10) << std::left << "From" << "|"
            << std::setw(10) << std::left << "To" << "|"
            << std::setw(10) << std::left <<  "Start" << "|"
            << std::setw(10) << std::left << "End" << "|"
            << std::setw(15) << std::left << "Vehicle type" << "|"
            << std::setw(15) << std::left << "Hotel" << "|"
            << std::setw(10) << std::left << "Total price" << "|" << std::endl;
        for (int i = 0; i < bookedTrips.size(); i++) {
            std::cout << std::setw(5) << std::left << i + 1 << "|"
                << std::setw(10) << std::left << bookedTrips[i].getDeparture() << "|"
                << std::setw(10) << std::left << bookedTrips[i].getDestination() << "|"
                << std::setw(10) << std::left << bookedTrips[i].getStartDate() << "|"
                << std::setw(10) << std::left << bookedTrips[i].getEndDate() << "|"
                << std::setw(15) << std::left << bookedTrips[i].getVehicle().getType() << "|"
                << std::setw(15) << std::left << bookedTrips[i].getHotel().getName() << "|"
                << std::setw(10) << std::left << bookedTrips[i].getTotalPrice() << "|" << std::endl;
        }
    }
    else {
        std::cout << "You have no itinerary booked to show" << std::endl;
    }
}

void User::displayBasicItineraryInfo(std::string from, std::string to, std::string date) {
    std::cout << "Dep - Des: " << from << " -> " << to << " | Date: " << date << std::endl;
}