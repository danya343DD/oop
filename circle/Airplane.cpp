#include "Airplane.h"

Airplane::Airplane(string t, int p, int m)
    : type(t), passengers(p), maxPassengers(m) {
}

bool Airplane::operator==(const Airplane& other) const {
    return this->type == other.type;
}

Airplane& Airplane::operator++() {
    if (passengers < maxPassengers) passengers++;
    return *this;
}

Airplane& Airplane::operator--() {
    if (passengers > 0) passengers--;
    return *this;
}

bool Airplane::operator>(const Airplane& other) const {
    return this->maxPassengers > other.maxPassengers;
}

void Airplane::print() const {
    cout << "Type: " << type << " | Pass: " << passengers << "/" << maxPassengers;
}
