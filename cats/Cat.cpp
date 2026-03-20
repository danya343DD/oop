#include "Cat.h"
using namespace std;
int Cat::count = 0;

Cat::Cat(const string& name, int age, const string& color)
    : name(name), age(age), color(color) {
    count++;
    cout << "Cat " << name << " created. Total cats: " << count << endl;
}

Cat::~Cat() {
    cout << "Cat " << name << " destroyed" << endl;
    count--;
}

void Cat::printInfo() const {
    cout << "Cat Info: Name=" << name << ", Age=" << age << ", Color=" << color << endl;
}

void Cat::sound() const {
    cout << "Cat makes a sound: Meow!" << endl;
}

int Cat::getCount() {
    return count;
}
