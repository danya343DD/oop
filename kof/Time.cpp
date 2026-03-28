#include "Time.h"

using namespace std;

void Time::normalize() {
    while (seconds < 0) { seconds += 60; minutes--; }
    while (seconds >= 60) { seconds -= 60; minutes++; }
    while (minutes < 0) { minutes += 60; hours--; }
    while (minutes >= 60) { minutes -= 60; hours++; }
    while (hours < 0) { hours += 24; }
    while (hours >= 24) { hours -= 24; }
}

Time::Time() : hours(0), minutes(0), seconds(0) {}

Time::Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
    normalize();
}

void Time::tick() {
    seconds++;
    normalize();
}

Time& Time::operator++() {
    tick();
    return *this;
}

Time Time::operator++(int) {
    Time temp = *this;
    tick();
    return temp;
}

Time& Time::operator--() {
    seconds--;
    normalize();
    return *this;
}

Time Time::operator--(int) {
    Time temp = *this;
    seconds--;
    normalize();
    return temp;
}

bool Time::operator==(const Time& other) const {
    return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
}

bool Time::operator!=(const Time& other) const {
    return !(*this == other);
}

bool Time::operator>(const Time& other) const {
    if (hours != other.hours) return hours > other.hours;
    if (minutes != other.minutes) return minutes > other.minutes;
    return seconds > other.seconds;
}

bool Time::operator<(const Time& other) const {
    return !(*this > other) && !(*this == other);
}

Time& Time::operator=(const Time& other) {
    if (this != &other) {
        hours = other.hours;
        minutes = other.minutes;
        seconds = other.seconds;
    }
    return *this;
}

Time& Time::operator+=(const Time& other) {
    hours += other.hours;
    minutes += other.minutes;
    seconds += other.seconds;
    normalize();
    return *this;
}

Time& Time::operator-=(const Time& other) {
    hours -= other.hours;
    minutes -= other.minutes;
    seconds -= other.seconds;
    normalize();
    return *this;
}

void Time::operator()(int h, int m, int s) {
    hours = h;
    minutes = m;
    seconds = s;
    normalize();
}

istream& operator>>(istream& is, Time& t) {
    is >> t.hours >> t.minutes >> t.seconds;
    t.normalize();
    return is;
}

ostream& operator<<(ostream& os, const Time& t) {
    os << (t.hours < 10 ? "0" : "") << t.hours << ":"
        << (t.minutes < 10 ? "0" : "") << t.minutes << ":"
        << (t.seconds < 10 ? "0" : "") << t.seconds;
    return os;
}
