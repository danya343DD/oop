#pragma once
#include "Vehicle.h"
using namespace std;

class Car : public Vehicle {
private:
    int doors;

public:
    Car(string m, int y, Point p, int d);

    double getMaxSpeed() const override;
    void print() const override;

    Car& operator++();      // префикс
    Car operator++(int);    // постфикс
};

