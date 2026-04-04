#include <iostream>
#include <vector>
#include "Animal.h"
#include "Dog.h"
#include "Cat.h"
#include "Cow.h"
#include "Horse.h"
#include "Bird.h"

using namespace std;

int main() {
    vector<Animal*> animals;

    animals.push_back(new Dog());
    animals.push_back(new Cat());
    animals.push_back(new Cow());
    animals.push_back(new Horse());
    animals.push_back(new Bird());

    for (Animal* animal : animals) {
        animal->speak();
    }

    for (Animal* animal : animals) {
        delete animal;
    }

    return 0;
}