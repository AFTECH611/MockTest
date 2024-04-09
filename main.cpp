// #include "Application.h"

#include <iostream>
#include <vector>

using namespace std;

class Test {
public:
    int a = 10;
    int b = 20;
    Test() {}
    Test(int _a, int _b) {
        a = _a;
        b = _b;
    }

    void func(int _a, int _b) {
        *this = Test(_a,_b);
        cout << a << " " << b << endl;
    }
};

int main() {
    // Application::getApplication().run();
    Test t;
    t.func(2,3);


    return 0;
}