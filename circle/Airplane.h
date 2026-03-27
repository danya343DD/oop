#include <iostream>
#include <string>
using namespace std;

class Airplane {
private:
    string type;
    int passengers;
    int maxPassengers;

public:
    Airplane(string t, int p, int m);

    
    bool operator==(const Airplane& other) const;

    
    Airplane& operator++();
    Airplane& operator--();

    
    bool operator>(const Airplane& other) const;

    void print() const;
};


