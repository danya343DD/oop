#include "Person.h"
#include <iostream>

using namespace std;

class Apartment {
private:
    int number;
    Person** residents;
    int residentCount;

public:
    Apartment();
    Apartment(int n);
    Apartment(const Apartment& other);
    Apartment(Apartment&& other) noexcept;
    ~Apartment();

    Apartment& operator=(Apartment&& other) noexcept;

    void addResident(Person* p);
    int getNumber();
    void print();
};



