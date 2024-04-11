#include "Application.h"

int main() {
    Application::getApplication().run();
    // DatabaseManager::appendFile("test.txt", Utility::strCommaD() + Utility::strOpenBracketD() + Utility::strCloseBracketD());

    return 0;
}