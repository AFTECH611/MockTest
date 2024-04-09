// #include "Application.h"
#include "DatabaseManager.h"

#include <vector>

using namespace std;

int main() {
    // Application::getApplication().run();
    vector<string> v{"a", "b", "c"};


    DatabaseManager::writeFile("testFile.txt", v);
    return 0;
}