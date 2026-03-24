#pragma once

#include <string>
#include <iostream>

using namespace std;

class Worker {
private:
    string fullName;
    string position;
    int hireYear;
    double salary;

public:
    explicit Worker(const string& fullName,
        const string& position,
        int hireYear,
        double salary);

    string getFullName() const;
    string getPosition() const;
    int getHireYear() const;
    double getSalary() const;

    int getWorkExperience(int currentYear) const;

    void display() const;

    ~Worker();
};




