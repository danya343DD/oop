#include <iostream>

using namespace std;

class Person {
private:
    char* name;
    char* address;

public:
    Person();
    Person(const char* n, const char* a);
    Person(const Person& other);
    Person(Person&& other) noexcept;
    ~Person();

    Person& operator=(Person&& other) noexcept;

    char* getName();
    void print();
};


