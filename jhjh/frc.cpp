#include "frc.h"
#include <stdexcept>
#include <cstdlib>

using namespace std;

int Fraction::gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::reduce() {
    if (denominator == 0) {
        throw invalid_argument("Знаменатель не может быть равен нулю!");
    }

    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    int divisor = gcd(numerator, denominator);
    if (divisor != 0) {
        numerator /= divisor;
        denominator /= divisor;
    }
}

Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    reduce();  // Сокращаем дробь в конструкторе
}

void Fraction::print() const {
    if (denominator == 1) {
        cout << numerator;
    }
    else {
        cout << numerator << "/" << denominator;
    }
}

Fraction Fraction::add(const Fraction& other) const {
    int newNum = numerator * other.denominator + other.numerator * denominator;
    int newDen = denominator * other.denominator;
    return Fraction(newNum, newDen);
}

Fraction Fraction::subtract(const Fraction& other) const {
    int newNum = numerator * other.denominator - other.numerator * denominator;
    int newDen = denominator * other.denominator;
    return Fraction(newNum, newDen);
}

Fraction Fraction::multiply(const Fraction& other) const {
    int newNum = numerator * other.numerator;
    int newDen = denominator * other.denominator;
    return Fraction(newNum, newDen);
}

Fraction Fraction::add(int value) const {
    return this->add(Fraction(value, 1));
}

Fraction Fraction::subtract(int value) const {
    return this->subtract(Fraction(value, 1));
}

Fraction Fraction::multiply(int value) const {
    return this->multiply(Fraction(value, 1));
}

Fraction Fraction::operator+(const Fraction& other) const {
    return this->add(other);
}

Fraction Fraction::operator-(const Fraction& other) const {
    return this->subtract(other);
}

Fraction Fraction::operator*(const Fraction& other) const {
    return this->multiply(other);
}

Fraction Fraction::operator+(int value) const {
    return this->add(value);
}

Fraction Fraction::operator-(int value) const {
    return this->subtract(value);
}

Fraction Fraction::operator*(int value) const {
    return this->multiply(value);
}

ostream& operator<<(ostream& os, const Fraction& frac) {
    if (frac.getDenominator() == 1) {
        os << frac.getNumerator();
    }
    else {
        os << frac.getNumerator() << "/" << frac.getDenominator();
    }
    return os;
}