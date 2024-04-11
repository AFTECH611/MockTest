#include "Utility.h"

bool Utility::isValidInt(std::string s) {
    try {
        stoi(s);
        return true;   
    }
    catch(const std::exception& e) {
        return false;
    }
}

bool Utility::isValidPrice(std::string s) {
    if(isValidInt(s) and std::stoi(s) >= 0) return true;
    return false;
}

std::string Utility::encrypt(std::string s) {
    std::hash<std::string> hasher;
    size_t hash = hasher(s);
    return std::to_string(hash);
}

std::string Utility::toLower(std::string input){
    std::string res = "";
    for (int i = 0; i < input.length(); i++) {
        res += tolower(input[i]);
    }
    return res;
}

bool lengthValidAcc(std::string acc){
    return acc.length() < 16 && acc.length() >= 2;
}

bool lengthValidPwd(std::string pwd){
    return pwd.length() >= 6;
}

bool lengthValidName(std::string name){
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

bool Utility::isValidAcc(std::string acc){
    if (!lengthValidAcc(acc)) {
        std::cout << "User account length must in range 1-16 characters!\n";
        return false;
    }
    for (int i = 0; i < acc.length(); i++) {
        char c = acc[i];
        if(c == ' ' || c == '\t') { //tab or space is not allowed
            std::cout << "Account user must not contain space character!\n";
            return false;
        }
    }
    return true;
}

bool Utility::isValidPassword(std::string pass) {
    bool f1, f2, f3;
    f1 = f2 = f3 = false;
    if(!lengthValidPwd(pass)) {
        std::cout << "Password must contain at least 6 character!\n";
        return false;
    }

    for (char c:pass){
        if (c == '\t'){
            std::cout << "Password can not contain a Tab space!. \n";
            return false;
        }
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
        std::cout << "Password must have at least 1 uppercase letter!\n";
    }
    if(!f2){
        std::cout << "Password must have at least 1 lowercase letter!\n";
    }
    if(!f3){
        std::cout << "Password must have at least 1 number letter!\n";
    }
    return false;
}

bool Utility::isValidName(std::string name) {
    if (!lengthValidName(name)) {
        std::cout << "Name length must not greater than 24!\n";
        return false;
    }
    for (int i = 0; i < name.length(); i++) {
        char c = name[i];
        if(c != ' '){
            if (!isLowerLetter(c) && !isUpperLetter(c)) {
                std::cout << "User full name must not have special character or number!\n";
                return false;
            }   
        }
    }
    return true;
}

void Utility::printVector(std::vector<std::string> vec) {
    std::cout << "Menu: \n";
    for(const std::string& s: vec) {
        std::cout << s << std::endl;
    }
    std::cout << "Enter number in range (1-" << vec.size() << "): ";
}

int Utility::getCommandFromCLI() {
    std::string command;

    while(true) {
        std::cout << "Insert command: "; std::cin >> command;

        if(Utility::isValidInt(command)) {
            return stoi(command);
        }
        else {
            std::cout << "Invalid command" << std::endl;
        }
    }

    return stoi(command);
}

std::vector<std::string> Utility::stringToVector(std::string s, char delimiter) {
    std::vector<std::string> vec = {""};
    int openBrackets = 0;
    for(char c: s) {
        if(c == delimiter && openBrackets == 0) {
            vec.push_back("");
        }
        else {
            if(c == '[') {
                openBrackets++;
            }
            else if(c == ']') {
                openBrackets--;
            }
        
            vec.back()+=c;
        } 
    }
    return vec;
}

std::string Utility::stripBrackets(std::string s) {
    if((s[0] == '(' && s.back() == ')') || (s[0] == '[' && s.back() == ']') || (s[0] == '{' && s.back() == '}')) {
        s.pop_back();
        s.erase(0,1);
    }

    return s;
}

bool Utility::isValidDate(std::string date) {
    int testIdx[8] = { 0, 1, 3, 4, 6, 7, 8, 9 };
    if (date.length() != 10) {
        return false;
    }
    else if (date[2] != '/' || date[5] != '/') {
        return false;
    }
    else {
        for (int i = 0; i < 8; i++) {
            if (date[i] < '0' && date[i] > '9') {
                return false;
            }
        }
    }
    int day, month, year;
    day = (date[0] - '0') * 10 + (date[1] - '0');
    month = (date[3] - '0') * 10 + (date[4] - '0');
    year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
    if ((day <= 0 || day > 31) || (month <= 0 || month > 12) || (year < 1900 || year > 2024)) {
        return false;
    }
    return true;
}

bool Utility::isValidPlace(std::string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            return false;
        }
    }
    return true;
}

int Utility::inputAge() {
    int age;
    std::cout << "Enter age: ";
    std::cin >> age;
    while (age < 0 || std::cin.fail()) {
        std::cout << "Age is must non-negative number. Please enter again: \n";
        std::cin.clear();
        std::cin.ignore();
        std::cin >> age;
    }
    return age;
}

void Utility::delay() {
    auto start = std::chrono::steady_clock::now();
    while (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - start).count() < 2);
}

int daysSince1900(int day, int month, int year) {
    const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int days = (year - 1900) * 365 + (year - 1901) / 4;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && month <= 2))
        days--;
    for (int i = 1; i < month; ++i)
        days += daysInMonth[i];
    days += day;
    return days;
}

int Utility::dateDiff(std::string date1, std::string date2) {
    int dayDiff, monthDiff, yearDiff;
    int day1, day2, month1, month2, year1, year2;
    day1 = (date1[0] - '0') * 10 + (date1[1] - '0'); day2 = (date2[0] - '0') * 10 + (date2[1] - '0');
    month1 = (date1[3] - '0') * 10 + (date1[4] - '0'); month2 = (date2[3] - '0') * 10 + (date2[4] - '0');
    year1 = (date1[6] - '0') * 1000 + (date1[7] - '0') * 100 + (date1[8] - '0') * 10 + (date1[9] - '0');
    year2 = (date2[6] - '0') * 1000 + (date2[7] - '0') * 100 + (date2[8] - '0') * 10 + (date2[9] - '0');
    int date1Since1900 = daysSince1900(day1, month1, year1);
    int date2Since1900 = daysSince1900(day2, month2, year2);
    return std::abs(date2Since1900 - date1Since1900);
}

int Utility::dateDiff1(std::string date1, std::string date2) {
    int dayDiff, monthDiff, yearDiff;
    int day1, day2, month1, month2, year1, year2;
    day1 = (date1[0] - '0') * 10 + (date1[1] - '0'); day2 = (date2[0] - '0') * 10 + (date2[1] - '0');
    month1 = (date1[3] - '0') * 10 + (date1[4] - '0'); month2 = (date2[3] - '0') * 10 + (date2[4] - '0');
    year1 = (date1[6] - '0') * 1000 + (date1[7] - '0') * 100 + (date1[8] - '0') * 10 + (date1[9] - '0');
    year2 = (date2[6] - '0') * 1000 + (date2[7] - '0') * 100 + (date2[8] - '0') * 10 + (date2[9] - '0');
    int date1Since1900 = daysSince1900(day1, month1, year1);
    int date2Since1900 = daysSince1900(day2, month2, year2);
    return date2Since1900 - date1Since1900;
}