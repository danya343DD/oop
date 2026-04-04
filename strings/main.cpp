#include <iostream>
#include "StringHolder.h"
#include "ReverseString.h"

using namespace std;

int main() {
    StringHolder* s1 = new StringHolder("World");
    StringHolder* s2 = new ReverseString("Hello");

    s1->print();
    s2->print();

    delete s2;
    delete s1;

    return 0;
}