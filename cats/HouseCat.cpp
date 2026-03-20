#include "HouseCat.h"
using namespace std;
HouseCat::HouseCat(const string& name, int age, const string& color, const string& owner)
     : Cat(name, age, color), ownerName(owner) {
}

HouseCat::~HouseCat() {
    std::cout << "HouseCat " << name << " destroyed" << endl;
}

void HouseCat::printInfo() const {
    Cat::printInfo();
    cout << "Owner: " << ownerName << endl;
}

void HouseCat::sound() const {
    cout << name << " purrs: Mrrr-mrrr" << endl;
}

void HouseCat::play() const {
    cout << name << " plays with a ball" << endl;
}
