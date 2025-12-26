#include <iostream>
# include "MyUniquePtr.h"
using namespace std;


class Test {
    public:
        Test() { cout << "Test Constructor" << endl; }
        ~Test() { cout << "Test Destructor" << endl; }

        void greet() { cout << "Hello from Test!" << endl; }
};


int main() {

    MyUniquePtr<Test> p1(new Test());

    p1->greet();

    
    
    return 0;
}