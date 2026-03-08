#include "Geometry.h"
#include <cmath>

int Geometry::calcCount = 0;

double Geometry::triangle(double base, double height) {
    calcCount++;
    return (base * height) / 2.0;
}

double Geometry::triangle(double a, double b, double c) {
    calcCount++;
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

double Geometry::rectangle(double a, double b) {
    calcCount++;
    return a * b;
}

double Geometry::square(double a) {
    calcCount++;
    return a * a;
}

double Geometry::rhombus(double d1, double d2) {
    calcCount++;
    return (d1 * d2) / 2.0;
}

int Geometry::getCalcCount() {
    return calcCount;
}