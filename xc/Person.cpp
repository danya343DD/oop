#include "Person.h"
#include <cstring>
#include <iostream>

using namespace std;

Person::Person() {
    name = nullptr;
    address = nullptr;
}

Person::Person(const char* n, const char* a) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    address = new char[strlen(a) + 1];
    strcpy(address, a);
}

Person::Person(const Person& other) {
    if (other.name) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
    else {
        name = nullptr;
    }
    if (other.address) {
        address = new char[strlen(other.address) + 1];
        strcpy(address, other.address);
    }
    else {
        address = nullptr;
    }
}

Person::Person(Person&& other) noexcept {
    name = other.name;
    address = other.address;
    other.name = nullptr;
    other.address = nullptr;
}

Person::~Person() {
    delete[] name;
    delete[] address;
}

Person& Person::operator=(Person&& other) noexcept {
    if (this != &other) {
        delete[] name;
        delete[] address;
        name = other.name;
        address = other.address;
        other.name = nullptr;
        other.address = nullptr;
    }
    return *this;
}

char* Person::getName() {
    return name;
}

void Person::print() {
    cout << "  Person: " << (name ? name : "null") << ", Address: " << (address ? address : "null") << endl;
}
