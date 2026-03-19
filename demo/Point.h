#pragma once
#include <iostream>
using namespace std;

class Point {
private:
    double x, y;
    static int pointCount;

public:
    Point();
    Point(double x, double y);
    Point(const Point& other);

    double getX() const;
    double getY() const;

    double distance() const;

    static int getCount();

    bool operator==(const Point& other) const;
    bool operator!=(const Point& other) const;

    friend ostream& operator<<(ostream& os, const Point& p);
    friend istream& operator>>(istream& is, Point& p);
};

