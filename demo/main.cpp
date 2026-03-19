#include <iostream>
#include "Car.h"
#include "Bike.h"
#include "Garage.h"
using namespace std;

int main() {
    Car* c1 = new Car("BMW", 2022, Point(1, 2), 4);
    Car* c2 = new Car("Audi", 2020, Point(3, 4), 2);
    Bike* b1 = new Bike("Yamaha", 2021, Point(5, 6), "sport");

    cout << "Vehicles: " << Vehicle::getTotal() << endl;

    Garage<Vehicle*> g;
    g.add(c1).add(c2).add(b1);

    for (int i = 0; i < g.getCount(); i++) {
        g[i]->print();
        cout << "Speed: " << g[i]->getMaxSpeed() << endl;
    }

    
    Garage<Vehicle*> g2 = g;

    
    Garage<Vehicle*> g3 = g + g2;

    cout << "Garages: " << Garage<Vehicle*>::getTotalGarages() << endl;

    
    Point p1(1, 1), p2(2, 2);
    cout << p1 << " == " << p2 << " ? " << (p1 == p2) << endl;

    cout << "Points: " << Point::getCount() << endl;

    
    try {
        g[100];
    }
    catch (...) {
        cout << "Error!" << endl;
    }

    delete c1;
    delete c2;
    delete b1;

    return 0;
}