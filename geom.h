#pragma once
#ifndef GEOMETRY_H
#define GEOMETRY_H

class Geometry {
private:
    static int calcCount;

public:
    static double triangle(double base, double height);
    static double triangle(double a, double b, double c);
    static double rectangle(double a, double b);
    static double square(double a);
    static double rhombus(double d1, double d2);
    static int getCalcCount();
};

#endif