#include "Circle.h"

Circle::Circle(double r) : radius(r < 0 ? 0 : r) {}

bool Circle::operator==(const Circle& other) const {
    return this->radius == other.radius;
}

bool Circle::operator>(const Circle& other) const {
    return this->radius > other.radius;
}

Circle& Circle::operator+=(double r) {
    this->radius += r;
    return *this;
}

Circle& Circle::operator-=(double r) {
    this->radius -= r;
    if (this->radius < 0) this->radius = 0;
    return *this;
}

void Circle::print() const {
    cout << "Circle(r=" << radius << ")";
}
