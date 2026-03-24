#pragma once
#include <iostream>

using namespace std;

class Set {
private:
    int* elements;
    int size;

    bool contains(int value) const;
    void resize();

public:
    explicit Set(int initialSize = 10);
    Set(const Set& other);
    ~Set();

    Set& operator=(const Set& other);

    bool operator==(const Set& other) const;
    bool operator!=(const Set& other) const;

    Set operator+(int value) const;
    Set& operator+=(int value);

    Set operator-(int value) const;
    Set& operator-=(int value);

    Set operator+(const Set& other) const;
    Set& operator+=(const Set& other);

    Set operator-(const Set& other) const;
    Set& operator-=(const Set& other);

    Set operator*(const Set& other) const;
    Set& operator*=(const Set& other);

    int getSize() const;
    int getElement(int index) const;

    friend ostream& operator<<(ostream& output, const Set& set);
    friend istream& operator>>(istream& input, Set& set);
};


