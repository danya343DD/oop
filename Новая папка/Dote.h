#include <iostream>

using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

    
    bool isLeapYear(int y) const;
    int getDaysInMonth(int m, int y) const;
    int toAbsoluteDays() const;

public:
    
    Date(int d = 1, int m = 1, int y = 2000);

    
    int operator-(const Date& other) const;

    
    Date operator+(int days) const;

    
    void print() const;
};


