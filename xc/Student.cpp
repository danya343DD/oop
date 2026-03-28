#include "Student.h"
#include <cstring>
#include <iostream>

using namespace std;

Student::Student() {
    name = nullptr;
    studentId = nullptr;
}

Student::Student(const char* n, const char* id) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    studentId = new char[strlen(id) + 1];
    strcpy(studentId, id);
}

Student::Student(const Student& other) {
    if (other.name) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
    else {
        name = nullptr;
    }
    if (other.studentId) {
        studentId = new char[strlen(other.studentId) + 1];
        strcpy(studentId, other.studentId);
    }
    else {
        studentId = nullptr;
    }
}

Student::Student(Student&& other) noexcept {
    name = other.name;
    studentId = other.studentId;
    other.name = nullptr;
    other.studentId = nullptr;
}

Student::~Student() {
    delete[] name;
    delete[] studentId;
}

Student& Student::operator=(Student&& other) noexcept {
    if (this != &other) {
        delete[] name;
        delete[] studentId;
        name = other.name;
        studentId = other.studentId;
        other.name = nullptr;
        other.studentId = nullptr;
    }
    return *this;
}

void Student::print() {
    cout << "Student: " << (name ? name : "null") << ", ID: " << (studentId ? studentId : "null") << endl;
}
