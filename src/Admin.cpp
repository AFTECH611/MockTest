#include "Admin.h"
#include "AccountManager.h"
#include "TripManager.h"
#include "Utility.h"

Admin::Admin() {
    username = password = "None";
}

Admin::Admin(std::string _username, std::string _password) {
    username = _username;
    password =_password; 
}

std::string Admin::toString() {
    return "1" + Utility::strCommaD() + username + Utility::strCommaD() + password;
}

const std::vector<std::string> Admin::getCmdListsUserManagement() {
    return std::vector<std::string>{"1.Display all Users", "2.Searching user", "3.Delete user", "4.Edit user", "5.Back"};
}

const std::vector<std::string> Admin::getCmdListsHotelManagement() {
    return std::vector<std::string>{"1.Display all hotels", "2.Searching hotels", "3.Delete hotel", "4.Add new hotel", "5.Edit hotel", "6.Back"};
}

const std::vector<std::string> Admin::getCmdListsFlightManagement() {
    return std::vector<std::string>{"1.Display all vehicle", "2.Searching vehicle", "3.Delete vehicle", "4.Add new vehicle", "5.Edit vehicle", "6.Back"};
}

const std::vector<std::string> Admin::getCmdListsHotelDisplay() {
    return std::vector<std::string>{"1.Sort by price", "2.Sort by address", "3.Back"};
}

const std::vector<std::string> Admin::getCmdListsFlightDisplay() {
    return std::vector<std::string>{"1.Sort by price", "2.Sort by date", "3.Back"};
}

void Admin::executeCmdAfterUser(){
    int cmd;
    std::cin >> cmd;
    system("cls");
    switch (cmd)
    {
    case 1:
    {
        AccountManager::sortUserByName();
        AccountManager::displayAllAccounts();
        break;
    }
    case 2:
    {
        std::string username;
        username = AccountManager::inputLogAccountUser();
        AccountManager::searchUser(username);
        break;
    }      
    case 3:
    {
        std::string username;
        username = AccountManager::inputLogAccountUser();
        AccountManager::deleteUser(username);
        break;
    }
    case 4:
    {
        std::string username;
        username = AccountManager::inputLogAccountUser();
        AccountManager::editUser(username);
        break;
    }
    
    default:
        std::cout << "Invalid choice. Please try again!:";
        break;
    }
}

void Admin::executeCmdAfterHotel(){
    int cmd;
    std::cin >> cmd;
    system("cls");
    switch (cmd)
    {
    case 1:
    {
        Utility::printVector(getCmdListsHotelDisplay());
        executeCmdAfterHotelDisplay();
        break;
    }
    case 2:
    {
        TripManager::displayHotels();
        TripManager::searchHotels();
        break;
    }      
    case 3:
    {
        TripManager::displayHotels();
        TripManager::deleteHotel();
        break;
    }
    case 4:
    {
        TripManager::displayHotels();
        TripManager::addHotel();
        break;
    }
    case 5:
    {
        TripManager::editHotel();
        break;
    }
    default:
        std::cout << "Invalid choice. Please try again!:";
        break;
    }
}

void Admin::executeCmdAfterFlight(){
    int cmd;
    std::cin >> cmd;
    system("cls");
    switch (cmd)
    {
    case 1:
    {
        Utility::printVector(getCmdListsFlightDisplay());
        executeCmdAfterFlightDisplay();
        break;
    }
    case 2:
    {   
        TripManager::searchVehicles();
        break;
    }      
    case 3:
    {
        TripManager::deleteVehicle();
        break;
    }

    case 4:
    {   
        TripManager::addVehicle();
        break;
    }

    case 5:
    {   
        TripManager::editVehicle();
        break;
    }
    
    default:
        std::cout << "Invalid choice. Please try again!:";
        break;
    }
}

void Admin::executeCmdAfterFlightDisplay(){
    int cmd;
    std::cin >> cmd;
    system("cls");
    switch (cmd)
    {
    case 1:
    {
        TripManager::sortVehicleByPrice();
        TripManager::displayVehicles();
        break;
    }
    case 2:
    {   
        TripManager::sortVehicleByDate();
        TripManager::displayVehicles();
        break;
    }      
    default:
        std::cout << "Invalid choice. Please try again!:";
        break;
    }
}

void Admin::executeCmdAfterHotelDisplay(){
    int cmd;
    std::cin >> cmd;
    system("cls");
    switch (cmd)
    {
    case 1:
    {
        TripManager::sortHotelByPrice();
        TripManager::displayHotels();
        break;
    }
    case 2:
    {   
        TripManager::sortHotelByAddress();
        TripManager::displayHotels();
        break;
    }      
    default:
        std::cout << "Invalid choice. Please try again!:";
        break;
    }
}

void Admin::executeCmdAfterLogin(int cmd) {
    system("cls");
    switch (cmd)
    {
    case 1:
    {
        display();
        break;
    }
    case 2:
    {
        Utility::printVector(getCmdListsUserManagement());
        executeCmdAfterUser();
        break;
    } 
    case 3:
    {
        Utility::printVector(getCmdListsHotelManagement());
        executeCmdAfterHotel();
        break;
    }  

    case 4:
    {
        Utility::printVector(getCmdListsFlightManagement());
        executeCmdAfterFlight();
        break;
    }  

    case 5:
    {
        AccountManager::logout();
        break;
    } 
    
    default:
        std::cout << "Invalid choice. Please try again!:";
        break;
    }
}



const std::vector<std::string> Admin::getCommandsList() {
    return std::vector<std::string>{"1.My profile", "2.User management", "3.Hotels management", "4.Vehicles management", "5.Log out"};
}

void Admin::executeCommand(int command){
    executeCmdAfterLogin(command);
}

bool Admin::fromString(std::string s) {
    std::vector<std::string> vec = Utility::stringToVector(s, 31);
    
    try {
        if(vec.at(0) != "1") return false;
        type = "admin";
        username = vec.at(1);
        password = vec.at(2);
    }
    catch(const std::exception& e) {
        return false;
    }

    return true;
}

bool Admin::isViewAllUser() {
    return true;
}

void Admin::editUser(std::string username) {

}
void Admin::removeUser(std::string username) {

}
void Admin::addHotel() {

}
void Admin::editHotel() {
    
}
void Admin::removeHotel() {

}
void Admin::addTransportation() {

}
void Admin::editTransportation() {

}
void Admin::removeTransportation() {

}
void Admin::display() {
    std::cout << "_______________________________________________\n";
    std::cout << "|   Account   |    Password   |      Role      |\n";
    std::cout << "|-------------|---------------|----------------|\n";
    std::cout << "|    admin    |     admin     |  Admin system  |\n";
    std::cout << "|_____________|_______________|________________|\n";
}


