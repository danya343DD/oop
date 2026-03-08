#pragma once
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <numeric>

using namespace std;

class Fraction {
private:
    int numerator;    
    int denominator;  

    void reduce();

    static int gcd(int a, int b);

public:
    Fraction(int num = 0, int den = 1);

    Fraction() : Fraction(0, 1) {}
    void print() const;

    Fraction add(const Fraction& other) const;
    Fraction subtract(const Fraction& other) const;
    Fraction multiply(const Fraction& other) const;

    Fraction add(int value) const;
    Fraction subtract(int value) const;
    Fraction multiply(int value) const;

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;

    Fraction operator+(int value) const;
    Fraction operator-(int value) const;
    Fraction operator*(int value) const;

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }
};

ostream& operator<<(ostream& os, const Fraction& frac);

#endif 