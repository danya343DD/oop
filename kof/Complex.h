#include <iostream>

using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    
    Complex();
    Complex(double r);
    Complex(double r, double i);

    
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;
    void operator()();

    
    friend istream& operator>>(istream& is, Complex& c);
    friend ostream& operator<<(ostream& os, const Complex& c);
};




