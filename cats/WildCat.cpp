#include "WildCat.h"
using namespace std;
WildCat::WildCat(const string& name, int age, const string& color, const string& habitat)
    : Cat(name, age, color), habitat(habitat) {
}

WildCat::~WildCat() {
    cout << "WildCat " << name << " destroyed" << endl;
}

void WildCat::printInfo() const {
    Cat::printInfo();
    cout << "Habitat: " << habitat << endl;
}

void WildCat::sound() const {
    cout << name << " growls: Rrrr!" << endl;
}

void WildCat::hunt() const {
    cout << name << " is hunting" << endl;
}
