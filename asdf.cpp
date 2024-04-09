#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

string toLower(string input){
    string res = "";
    for (int i = 0; i < input.length(); i++) {
        res += tolower(input[i]);
    }
    return res;
}

bool lengthValidAcc(string acc){
    return acc.length() < 12;
}

bool lengthValidPwd(string pwd){
    return pwd.length() >= 6;
}

bool lengthValidName(string name){
    return name.length() < 24;
}

bool isNumeric(char c) {
    return isdigit(static_cast<unsigned char>(c)) != 0;
}

bool isUpperLetter(char c) {
    return (c >= 'a' && c <= 'z');
}

bool isLowerLetter(char c) {
    return (c >= 'A' && c <= 'Z');
}

bool isValidAcc(string acc){
    if (!lengthValidAcc(acc)) {
        cout << "User account length must not greater than 16!\n";
        return false;
    }
    for (int i = 0; i < acc.length(); i++) {
        char c = acc[i];
        if(c == ' ') {
            cout << "Account user must not contain space character!\n";
            return false;
        }
    }
    return true;
}

bool isValidPassword(string pass){
    bool f1, f2, f3;
    f1 = f2 = f3 = false;
    if(!lengthValidPwd(pass)) {
        cout << "Password must contain at least 6 character!\n";
        return false;
    }

    for (char c:pass){
        if (isLowerLetter(c)){
            f1 = true;
        }
        if (isUpperLetter(c)){
            f2 = true;
        }
        if (isNumeric(c)){
            f3 = true;
        }
    }
    if(f1 && f2 && f3) return true;
    if(!f1){
        cout << "Password must have at least 1 lowercase letter!\n";
    }
    if(!f2){
        cout << "Password must have at least 1 uppercase letter!\n";
    }
    if(!f3){
        cout << "Password must have at least 1 number letter!\n";
    }
    return false;
}

bool isValidName(string name) {
    if (!lengthValidName(name)) {
        cout << "Name length must not greater than 24!\n";
        return false;
    }
    for (int i = 0; i < name.length(); i++) {
        char c = name[i];
        if(c != ' '){
            if (!isLowerLetter(c) && !isUpperLetter(c)) {
                cout << "User full name must not have special character or number!\n";
                return false;
            }   
        }
    }
    return true;
}

class Account {
protected:
    string username;
    string password;
    string name;
    string address;
    int age;

public:
    // ructor
    Account()
        : username(""), password(""), name(""), address(""), age(0) {}
    Account( string& uname,  string& pwd,  string& n,  string& addr, int a)
        : username(uname), password(pwd), name(n), address(addr), age(a) {}

    // Virtual destructor to allow proper destruction of derived classes
    virtual ~Account() {}

    // Virtual function to display account details
    virtual void display()  {
        cout << "Username: " << username << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Age: " << age << endl;
    }

    string& getUsername()  {
        return username;
    }

    string& getPassword()  {
        return password;
    }

    string& getName()  {
        return name;
    }

    string& getAddress()  {
        return address;
    }

    int& getAge()  {
        return age;
    }

    void setUsername( string& username) {
        password = username;
    }

    void setPassword( string& pwd) {
        password = pwd;
    }

    void setName( string& _name) {
        name = _name;
    }

    void setAddress( string& addr) {
        address = addr;
    }

    void setAge(int a) {
        age = a;
    }
};

class Customer : public Account {
public:
    // ructor
    Customer() 
        : Account() {}
    Customer( string& uname,  string& pwd,  string& n,  string& addr, int a)
        : Account(uname, pwd, n, addr, a) {}
};

class Admin : public Account {
public:
    // ructor
    Admin()
        : Account() {}
    Admin( string& uname,  string& pwd,  string& n,  string& addr, int a)
        : Account(uname, pwd, n, addr, a) {}
};

class UserManager {
private:
    vector<Account*> accounts;
    Account* currentUser;

public:
    UserManager() : currentUser(nullptr) {}

    ~UserManager() {
        for (Account* acc : accounts) {
            delete acc;
        }
    }

    bool isExisted(string username){
        for (int i = 0; i < accounts.size(); i++) {
            if(accounts[i]->getUsername() == username) {
                cout << accounts[i]->getUsername();
                return true;
            }
        }
        return false;
    }

    string inputRegAccount(){
        cout << "Input User information!\n";
        cout << "Enter Account: " << endl;
        string _Acc;
        cin.ignore();
        getline(cin, _Acc);
        while (!isValidAcc(_Acc)) {
            cout << "Username must not have special character or space. Please enter again: \n";
            getline(cin, _Acc);
        }
        string lwacc = toLower(_Acc);
        while (this->isExisted(lwacc)) {
            cout << "Username existed! Please choose another username: \n";
            getline(cin, lwacc);
        }
        lwacc = toLower(_Acc);
        return lwacc;
    }

    string inputLogAccountCustomer(){
        cout << "Enter Account: " << endl;
        string _Acc;
        cin.ignore();
        getline(cin, _Acc);
        while (!isValidAcc(_Acc)) {
            cout << "Username must not have special character or space. Please enter again: \n";
            getline(cin, _Acc);
        }
        string lwacc = toLower(_Acc);
        return lwacc;
    }

    string inputRegPassword(){
        cout << "Enter your password: ";
        string pass;
        getline(cin, pass);
        while (!isValidPassword(pass)) {
            cout << "Please choose another password, enter password: \n";
            getline(cin, pass);
        }
        return pass;
    }

    string inputLogPassword(){
        cout << "Enter your password: ";
        string pass;
        getline(cin, pass);
        return pass;
    }

    string inputFullName(){
        cout << "Enter your full name: ";
        string _name;
        getline(cin, _name);
        while (!isValidName(_name)) {
            cout << "Please enter again: \n";
            getline(cin, _name);
        }
        string lwname = toLower(_name);
        return lwname;
    }

    int inputAge(){
        int age;
        cout << "Enter age: ";
        cin >> age;
        while (age < 0 || cin.fail()) {
            cout << "Age is must non-negative number. Please enter again: \n";
            cin.clear();
            cin.ignore();
            cin >> age;
        }
        return age;
    }

    void registerAdmin(){
        Account* newAdmin = new Admin;
        string acc = inputRegAccount();
        string name = inputFullName();
        string pass = inputRegPassword();
        newAdmin->setUsername(acc);
        newAdmin->setName(name);
        newAdmin->setPassword(pass);
        accounts.push_back(newAdmin);
        cout << "Administrator account registered successfully." << endl;
    }

    void registerCustomer(){
        Account* newCustomer = new Customer;
        string acc = inputRegAccount();
        string name = inputFullName();
        string pass = inputRegPassword();
        int age = inputAge();
        newCustomer->setUsername(acc);
        newCustomer->setName(name);
        newCustomer->setAge(age);
        newCustomer->setPassword(pass);
        accounts.push_back(newCustomer);
        cout << "User account registered successfully." << endl;
    }

    bool login() {
        string username = this->inputLogAccountCustomer(); 
        string pass = this->inputLogPassword();
        for (Account* acc : accounts) {
            if (acc->getUsername() == username && acc->getPassword() == pass) {
                currentUser = acc;
                cout << "Logged in successfully." << endl;
                return true;
            }
        }
        cout << "Invalid username or password." << endl;
        return false;
    }

    void logout() {
        currentUser = nullptr;
        cout << "Logged out successfully." << endl;
    }

    void changeUserInfo(string name, string address, int age) {
        if (currentUser != nullptr) {
            currentUser->setName(name);
            currentUser->setAddress(address);
            currentUser->setAge(age);
            cout << "User information updated successfully." << endl;
        } else {
            cout << "Please login first." << endl;
        }
    }
};

int main() {
    UserManager userManager;
    bool running = true;

    while (running) {
        cout << "1. Register\n2. Login\n3. Logout\n4. Change Information\n5. Exit" << endl;
        int choice;
        cin >> choice;
        while (cin.fail()) {
            cout << "Please enter again: \n";
            cin.clear();
            cin.ignore();
            cin >> choice;
        }
        switch (choice) {
            case 1: {
                userManager.registerCustomer();
                break;
            }
            case 2: {
                userManager.login();
                break;
            }
            case 3:
                userManager.logout();
                break;
            case 4: {
                string address, name;
                int age;
                cout << "Enter new address: ";
                cin.ignore(); // Clear input buffer
                getline(cin, address);
                cout << "Enter new age: ";
                cin >> age;
                userManager.changeUserInfo(name, address, age);
                break;
            }
            case 5:
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

