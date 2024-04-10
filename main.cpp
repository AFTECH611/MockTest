#include "Application.h"
// #include "User.h"
// #include "DatabaseManager.h"

int main() {
    Application::getApplication().run();

    // Trip t1("abc", "abc", "10/12/2022", "1/12/2023", 100, 1);
    
    // User u("asdf", "asdf", "asdf asdf", "asdf", 123, std::vector<Trip>{t1});
    
    // DatabaseManager::writeFile("./Database/Accounts.txt", std::vector<std::string>{u.toString()});

    // DatabaseManager::readFile();
    return 0;
}