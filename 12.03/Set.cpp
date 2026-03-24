#include "Set.h"

Set::Set(int initialSize) : size(0) {
    elements = new int[initialSize];
}

Set::Set(const Set& other) : size(other.size) {
    elements = new int[size];
    for (int i = 0; i < size; i++) {
        elements[i] = other.elements[i];
    }
}

Set::~Set() {
    delete[] elements;
}

Set& Set::operator=(const Set& other) {
    if (this != &other) {
        delete[] elements;
        size = other.size;
        elements = new int[size];
        for (int i = 0; i < size; i++) {
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

bool Set::contains(int value) const {
    for (int i = 0; i < size; i++) {
        if (elements[i] == value) {
            return true;
        }
    }
    return false;
}

void Set::resize() {
    int newSize = (size == 0) ? 10 : size * 2;
    int* newElements = new int[newSize];
    for (int i = 0; i < size; i++) {
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
}

bool Set::operator==(const Set& other) const {
    if (size != other.size) {
        return false;
    }
    for (int i = 0; i < size; i++) {
        if (!other.contains(elements[i])) {
            return false;
        }
    }
    return true;
}

bool Set::operator!=(const Set& other) const {
    return !(*this == other);
}

Set Set::operator+(int value) const {
    Set result(*this);
    result += value;
    return result;
}

Set& Set::operator+=(int value) {
    if (!contains(value)) {
        if (size >= 10 && size % 10 == 0) {
            resize();
        }
        elements[size++] = value;
    }
    return *this;
}

Set Set::operator-(int value) const {
    Set result(*this);
    result -= value;
    return result;
}

Set& Set::operator-=(int value) {
    for (int i = 0; i < size; i++) {
        if (elements[i] == value) {
            for (int j = i; j < size - 1; j++) {
                elements[j] = elements[j + 1];
            }
            size--;
            break;
        }
    }
    return *this;
}

Set Set::operator+(const Set& other) const {
    Set result(*this);
    result += other;
    return result;
}

Set& Set::operator+=(const Set& other) {
    for (int i = 0; i < other.size; i++) {
        *this += other.elements[i];
    }
    return *this;
}

Set Set::operator-(const Set& other) const {
    Set result(*this);
    result -= other;
    return result;
}

Set& Set::operator-=(const Set& other) {
    for (int i = 0; i < other.size; i++) {
        *this -= other.elements[i];
    }
    return *this;
}

Set Set::operator*(const Set& other) const {
    Set result(10);
    for (int i = 0; i < size; i++) {
        if (other.contains(elements[i])) {
            result += elements[i];
        }
    }
    return result;
}

Set& Set::operator*=(const Set& other) {
    Set result(10);
    for (int i = 0; i < size; i++) {
        if (other.contains(elements[i])) {
            result += elements[i];
        }
    }
    *this = result;
    return *this;
}

int Set::getSize() const {
    return size;
}

int Set::getElement(int index) const {
    if (index >= 0 && index < size) {
        return elements[index];
    }
    return 0;
}

ostream& operator<<(ostream& output, const Set& set) {
    output << "{";
    for (int i = 0; i < set.size; i++) {
        output << set.elements[i];
        if (i < set.size - 1) {
            output << ", ";
        }
    }
    output << "}";
    return output;
}

istream& operator>>(istream& input, Set& set) {
    cout << "Enter number of elements: ";
    int n;
    input >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        int value;
        input >> value;
        set += value;
    }
    return input;
}
