#pragma once
#include "Vehicle.h"
using namespace std;

class Bike : public Vehicle {
private:
    string type;

public:
    Bike(string m, int y, Point p, string t);

    double getMaxSpeed() const override;
    void print() const override;
};


