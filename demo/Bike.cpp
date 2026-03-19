#include "Bike.h"

Bike::Bike(string m, int y, Point p, string t)
    : Vehicle(m, y, p), type(t) {
}

double Bike::getMaxSpeed() const {
    return 60.0;
}

void Bike::print() const {
    cout << "Bike: " << model << " " << year
        << " Pos: " << position
        << " Type: " << type << endl;
}