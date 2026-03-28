#include "Apartment.h"
#include <iostream>

using namespace std;

Apartment::Apartment() {
    number = 0;
    residents = nullptr;
    residentCount = 0;
}

Apartment::Apartment(int n) {
    number = n;
    residents = nullptr;
    residentCount = 0;
}

Apartment::Apartment(const Apartment& other) {
    number = other.number;
    residentCount = other.residentCount;
    if (other.residents) {
        residents = new Person * [residentCount];
        for (int i = 0; i < residentCount; ++i) {
            residents[i] = new Person(*other.residents[i]);
        }
    }
    else {
        residents = nullptr;
    }
}

Apartment::Apartment(Apartment&& other) noexcept {
    number = other.number;
    residents = other.residents;
    residentCount = other.residentCount;
    other.number = 0;
    other.residents = nullptr;
    other.residentCount = 0;
}

Apartment::~Apartment() {
    for (int i = 0; i < residentCount; ++i) {
        delete residents[i];
    }
    delete[] residents;
}

Apartment& Apartment::operator=(Apartment&& other) noexcept {
    if (this != &other) {
        for (int i = 0; i < residentCount; ++i) {
            delete residents[i];
        }
        delete[] residents;
        number = other.number;
        residents = other.residents;
        residentCount = other.residentCount;
        other.number = 0;
        other.residents = nullptr;
        other.residentCount = 0;
    }
    return *this;
}

void Apartment::addResident(Person* p) {
    Person** newResidents = new Person * [residentCount + 1];
    for (int i = 0; i < residentCount; ++i) {
        newResidents[i] = residents[i];
    }
    newResidents[residentCount] = p;
    delete[] residents;
    residents = newResidents;
    residentCount++;
}

int Apartment::getNumber() {
    return number;
}

void Apartment::print() {
    cout << " Apartment #" << number << ", Residents:" << endl;
    if (residents) {
        for (int i = 0; i < residentCount; ++i) {
            residents[i]->print();
        }
    }
}
