#include <iostream>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;
    void normalize();

public:
    Time();
    Time(int h, int m, int s);

    void tick();

    Time& operator++();
    Time operator++(int);
    Time& operator--();
    Time operator--(int);

    bool operator==(const Time& other) const;
    bool operator!=(const Time& other) const;
    bool operator>(const Time& other) const;
    bool operator<(const Time& other) const;

    Time& operator=(const Time& other);
    Time& operator+=(const Time& other);
    Time& operator-=(const Time& other);

    void operator()(int h, int m, int s);

    friend istream& operator>>(istream& is, Time& t);
    friend ostream& operator<<(ostream& os, const Time& t);
};


