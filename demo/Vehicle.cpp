#include "Vehicle.h"

int Vehicle::totalVehicles = 0;

Vehicle::Vehicle(string m, int y, Point p)
    : model(m), year(y), position(p) {
    totalVehicles++;
}

Vehicle::Vehicle(const Vehicle& other)
    : model(other.model), year(other.year), position(other.position) {
    totalVehicles++;
}

Vehicle::Vehicle(string m)
    : model(m), year(2020), position(Point(0, 0)) {
    totalVehicles++;
}

Vehicle::~Vehicle() {}

void Vehicle::move(const Point& newPos) {
    position = newPos;
}

int Vehicle::getTotal() {
    return totalVehicles;
}