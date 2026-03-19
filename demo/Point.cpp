#include "Point.h"
#include <cmath>

int Point::pointCount = 0;

Point::Point() : x(0), y(0) {
    pointCount++;
}

Point::Point(double x, double y) : x(x), y(y) {
    pointCount++;
}

Point::Point(const Point& other) : x(other.x), y(other.y) {
    pointCount++;
}

double Point::getX() const { return x; }
double Point::getY() const { return y; }

double Point::distance() const {
    return sqrt(x * x + y * y);
}

int Point::getCount() {
    return pointCount;
}

bool Point::operator==(const Point& other) const {
    return x == other.x && y == other.y;
}

bool Point::operator!=(const Point& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& os, const Point& p) {
    os << "(" << p.x << "; " << p.y << ")";
    return os;
}

istream& operator>>(istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}
