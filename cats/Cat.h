#pragma once
#include <string>
#include <iostream>

class Cat {
protected:
    string name;
    int age;
    string color;
    static int count;

public:
    Cat(const string& name, int age, const string& color);
    ~Cat();
    void printInfo() const;
    void sound() const;
    static int getCount();
};

