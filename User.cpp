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
    std::string s = "0," + username + "," + password + "," + name + "," + address + "," + std::to_string(age);
    for(Trip t: bookedTrips) {
        s+=",[" + t.toString() + "]";
    }
    return s;
}

bool User::fromString(std::string s) {
    std::vector<std::string> vec = Utility::stringToVector(s, ',');
    
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
        return false;
    }

    return true;
}

void User::addNewItinerary(Trip newTrip) {
    bookedTrips.push_back(newTrip);
}

std::vector<std::string> User::getCommandsList() {
    //system("cls");
    return std::vector<std::string>{"1 - View profile", 
        "2 - Make itinerary", 
        "3 - List my itinerary",
        "4 - Logout"};
}

std::vector<std::string> User::getCommandListAfterViewProfile() {
    return std::vector<std::string>{"1 - Edit profile", 
        "2 - Edit account", 
        "3 - Return"};
}

std::vector<std::string> User::getCommandListAfterMakeItinerary() {
    return std::vector<std::string>{"1 - Choose vehicle"
        "2 - Choose hotel",
        "3 - Done"};
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
        makeItinerary();
        break;
    }
    case(3): {
        showItinerary();
        break;
    }
    case(4): {
        AccountManager::setCurrentAccount();
        break;
    }
    default: {
        std::cout << "Invalid option" << std::endl;
    }
    }
}

void User::viewProfile() {
    this->display();
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
    // std:: cout << "USER ACCOUNT" << std::endl;
    // std::cout << "Username: " << username << std::endl;
    // std::cout << "Name: " << name << std::endl;
    // std::cout << "Address: " << address << std::endl;
    // std::cout << "Age: " << age << std::endl;
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

void User::makeItinerary() {
    std::string from, to;
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
        std::cout << "You have ho itinerary booked to show" << std::endl;
    }
}