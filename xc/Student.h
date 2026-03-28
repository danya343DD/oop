#include <iostream>

using namespace std;

class Student {
private:
    char* name;
    char* studentId;

public:
    Student();
    Student(const char* n, const char* id);
    Student(const Student& other);
    Student(Student&& other) noexcept;
    ~Student();

    Student& operator=(Student&& other) noexcept;

    void print();
};


