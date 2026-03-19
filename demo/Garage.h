#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Garage {
private:
    T* arr;
    int size;
    int capacity;

    static int garageCount;

public:
    Garage() {
        size = 0;
        capacity = 10;
        arr = new T[capacity];
        garageCount++;
    }

    Garage(int cap) {
        size = 0;
        capacity = cap;
        arr = new T[capacity];
        garageCount++;
    }

    Garage(const Garage& other) {
        size = other.size;
        capacity = other.capacity;
        arr = new T[capacity];
        for (int i = 0; i < size; i++)
            arr[i] = other.arr[i];
        garageCount++;
    }

    ~Garage() {
        delete[] arr;
    }

    Garage& operator=(const Garage& other) {
        if (this != &other) {
            delete[] arr;
            size = other.size;
            capacity = other.capacity;
            arr = new T[capacity];
            for (int i = 0; i < size; i++)
                arr[i] = other.arr[i];
        }
        return *this;
    }

    Garage& add(const T& item) {
        if (size < capacity) {
            arr[size++] = item;
        }
        return *this;
    }

    int getCount() const {
        return size;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size)
            throw "Index error!";
        return arr[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= size)
            throw "Index error!";
        return arr[index];
    }

    Garage operator+(const Garage& other) const {
        Garage result(size + other.size);
        for (int i = 0; i < size; i++)
            result.add(arr[i]);
        for (int i = 0; i < other.size; i++)
            result.add(other.arr[i]);
        return result;
    }

    static int getTotalGarages() {
        return garageCount;
    }
};

template <typename T>
int Garage<T>::garageCount = 0;


