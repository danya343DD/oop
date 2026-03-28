#include "Complex.h"
#include "Time.h"
#include <iostream>

using namespace std;

int main() {
    Complex c1(3, 4);
    Complex c2(1, -2);

    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;

    cout << c1 << "\n" << c2 << "\n";
    cout << c3 << "\n" << c4 << "\n";

    c3();
    cout << c3 << "\n";

    Time t1(23, 59, 58);
    cout << t1 << "\n";

    t1.tick();
    cout << t1 << "\n";

    t1++;
    cout << t1 << "\n";

    Time t2(0, 0, 5);
    t1 += t2;
    cout << t1 << "\n";

    t1(12, 30, 0);
    cout << t1 << "\n";

    return 0;
}