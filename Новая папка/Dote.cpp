#include "Date.h"
#include <cmath>

using namespace std;

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}


bool Date::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}


int Date::getDaysInMonth(int m, int y) const {
    if (m == 2) return isLeapYear(y) ? 29 : 28;
    if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
    return 31;
}


int Date::toAbsoluteDays() const {
    int totalDays = day;
    for (int i = 1; i < year; ++i) {
        totalDays += isLeapYear(i) ? 366 : 365;
    }
    for (int i = 1; i < month; ++i) {
        totalDays += getDaysInMonth(i, year);
    }
    return totalDays;
}


int Date::operator-(const Date& other) const {
    return abs(this->toAbsoluteDays() - other.toAbsoluteDays());
}


Date Date::operator+(int days) const {
    Date result = *this;
    while (days > 0) {
        int daysInCurrentMonth = getDaysInMonth(result.month, result.year);
        int daysLeftInMonth = daysInCurrentMonth - result.day + 1;

        if (days >= daysLeftInMonth) {
            days -= daysLeftInMonth;
            result.day = 1;
            result.month++;
            if (result.month > 12) {
                result.month = 1;
                result.year++;
            }
        }
        else {
            result.day += days;
            days = 0;
        }
    }
    return result;
}


void Date::print() const {
    if (day < 10) cout << "0";
    cout << day << ".";
    if (month < 10) cout << "0";
    cout << month << "." << year;
}
