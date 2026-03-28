#include "Complex.h"
using namespace std;

Complex::Complex() : real(0), imag(0) {}

Complex::Complex(double r) : real(r), imag(0) {}

Complex::Complex(double r, double i) : real(r), imag(i) {}

Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

bool Complex::operator==(const Complex& other) const {
    return (real == other.real) && (imag == other.imag);
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

void Complex::operator()() {
    real = 0;
    imag = 0;
}

istream& operator>>(istream& is, Complex& c) {
    is >> c.real >> c.imag;
    return is;
}

ostream& operator<<(ostream& os, const Complex& c) {
    os << c.real << (c.imag >= 0 ? "+" : "") << c.imag << "i";
    return os;
}