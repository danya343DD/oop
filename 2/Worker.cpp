#include "Worker.h"

Worker::Worker(const string& fullName,
    const string& position,
    int hireYear,
    double salary)
    : fullName(fullName), position(position),
    hireYear(hireYear), salary(salary) {
}

string Worker::getFullName() const {
    return fullName;
}

string Worker::getPosition() const {
    return position;
}

int Worker::getHireYear() const {
    return hireYear;
}

double Worker::getSalary() const {
    return salary;
}

int Worker::getWorkExperience(int currentYear) const {
    return currentYear - hireYear;
}

void Worker::display() const {
    cout << "ФИО: " << fullName << endl;
    cout << "Должность: " << position << endl;
    cout << "Год поступления: " << hireYear << endl;
    cout << "Зарплата: " << salary << endl;
    cout << "------------------------" << endl;
}

Worker::~Worker() {
}
