#pragma once
#include <iostream>
#include <string>
#include "Point.h"
using namespace std;

class Vehicle {
protected:
    string model;
    int year;
    Point position;

    static int totalVehicles;

public:
    Vehicle(string m, int y, Point p);
    Vehicle(const Vehicle& other);
    explicit Vehicle(string m);

    virtual ~Vehicle();

    virtual double getMaxSpeed() const = 0;
    virtual void print() const = 0;

    void move(const Point& newPos);

    static int getTotal();
};



