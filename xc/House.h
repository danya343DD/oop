#include "Apartment.h"
#include <iostream>

using namespace std;

class House {
private:
    char* city;
    char* street;
    int houseNumber;
    Apartment** apartments;
    int apartmentCount;

public:
    House();
    House(const char* c, const char* s, int hn);
    House(const House& other);
    House(House&& other) noexcept;
    ~House();

    House& operator=(House&& other) noexcept;

    void addApartment(Apartment* a);
    void print();
};



