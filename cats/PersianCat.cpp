#include "PersianCat.h"
using namespace std;
PersianCat::PersianCat(const string& name, int age, const string& color, int woolLength)
    : Cat(name, age, color), woolLength(woolLength) {
}

PersianCat::~PersianCat() {
    cout << "PersianCat " << name << " destroyed" << endl;
}

void PersianCat::printInfo() const {
    Cat::printInfo();
    cout << "Wool Length: " << woolLength << " cm" << endl;
}

void PersianCat::sound() const {
    cout << name << " says softly: Meow" << endl;
}

void PersianCat::groom() const {
    cout << name << " needs grooming" << endl;
}
