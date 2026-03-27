#include <iostream>
#include "Circle.h"
#include "Airplane.h"

using namespace std;

int main() {
    // Тест Circle
    cout << "--- Testing Circle ---" << endl;
    Circle c1(10), c2(15);
    cout << "c1 == c2: " << (c1 == c2 ? "True" : "False") << endl;
    cout << "c2 > c1: " << (c2 > c1 ? "True" : "False") << endl;
    c1 += 5;
    cout << "c1 after += 5: "; c1.print(); cout << endl;

    // Тест Airplane
    cout << "\n--- Testing Airplane ---" << endl;
    Airplane plane1("Boeing 747", 300, 400);
    Airplane plane2("Airbus A320", 150, 180);

    cout << "Same types: " << (plane1 == plane2 ? "Yes" : "No") << endl;
    cout << "Plane1 larger capacity than Plane2: " << (plane1 > plane2 ? "Yes" : "No") << endl;

    ++plane1; // Добавили пассажира
    cout << "Plane1 after ++: "; plane1.print(); cout << endl;

    return 0;
}