#include <iostream>
using namespace std;

class Circle {
private:
    double radius;

public:
    Circle(double r = 0);

    
    bool operator==(const Circle& other) const;

    
    bool operator>(const Circle& other) const;

    
    Circle& operator+=(double r);
    Circle& operator-=(double r);

    void print() const;
};



