#include "House.h"
#include <cstring>
#include <iostream>

using namespace std;

House::House() {
    city = nullptr;
    street = nullptr;
    houseNumber = 0;
    apartments = nullptr;
    apartmentCount = 0;
}

House::House(const char* c, const char* s, int hn) {
    city = new char[strlen(c) + 1];
    strcpy(city, c);
    street = new char[strlen(s) + 1];
    strcpy(street, s);
    houseNumber = hn;
    apartments = nullptr;
    apartmentCount = 0;
}

House::House(const House& other) {
    if (other.city) {
        city = new char[strlen(other.city) + 1];
        strcpy(city, other.city);
    }
    else {
        city = nullptr;
    }
    if (other.street) {
        street = new char[strlen(other.street) + 1];
        strcpy(street, other.street);
    }
    else {
        street = nullptr;
    }
    houseNumber = other.houseNumber;
    apartmentCount = other.apartmentCount;
    if (other.apartments) {
        apartments = new Apartment * [apartmentCount];
        for (int i = 0; i < apartmentCount; ++i) {
            apartments[i] = new Apartment(*other.apartments[i]);
        }
    }
    else {
        apartments = nullptr;
    }
}

House::House(House&& other) noexcept {
    city = other.city;
    street = other.street;
    houseNumber = other.houseNumber;
    apartments = other.apartments;
    apartmentCount = other.apartmentCount;
    other.city = nullptr;
    other.street = nullptr;
    other.houseNumber = 0;
    other.apartments = nullptr;
    other.apartmentCount = 0;
}

House::~House() {
    delete[] city;
    delete[] street;
    for (int i = 0; i < apartmentCount; ++i) {
        delete apartments[i];
    }
    delete[] apartments;
}

House& House::operator=(House&& other) noexcept {
    if (this != &other) {
        delete[] city;
        delete[] street;
        for (int i = 0; i < apartmentCount; ++i) {
            delete apartments[i];
        }
        delete[] apartments;
        city = other.city;
        street = other.street;
        houseNumber = other.houseNumber;
        apartments = other.apartments;
        apartmentCount = other.apartmentCount;
        other.city = nullptr;
        other.street = nullptr;
        other.houseNumber = 0;
        other.apartments = nullptr;
        other.apartmentCount = 0;
    }
    return *this;
}

void House::addApartment(Apartment* a) {
    Apartment** newApartments = new Apartment * [apartmentCount + 1];
    for (int i = 0; i < apartmentCount; ++i) {
        newApartments[i] = apartments[i];
    }
    newApartments[apartmentCount] = a;
    delete[] apartments;
    apartments = newApartments;
    apartmentCount++;
}

void House::print() {
    cout << "House in " << (city ? city : "null") << ", " << (street ? street : "null") << " #" << houseNumber << ":" << endl;
    if (apartments) {
        for (int i = 0; i < apartmentCount; ++i) {
            apartments[i]->print();
        }
    }
}
