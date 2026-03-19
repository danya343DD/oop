#include "Car.h"

Car::Car(string m, int y, Point p, int d)
    : Vehicle(m, y, p), doors(d) {
}

double Car::getMaxSpeed() const {
    return 180.0;
}

void Car::print() const {
    cout << "Car: " << model << " " << year
        << " Pos: " << position
        << " Doors: " << doors << endl;
}

Car& Car::operator++() {
    doors++;
    return *this;
}

Car Car::operator++(int) {
    Car temp = *this;
    doors++;
    return temp;
}