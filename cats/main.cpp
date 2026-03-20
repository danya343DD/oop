#include <iostream>
#include "Cat.h"
#include "HouseCat.h"
#include "WildCat.h"
#include "PersianCat.h"

using namespace std;

int main() {
    cout << "--- Creating Objects ---" << endl;

    Cat baseCat("GenericCat", 3, "Gray");
    HouseCat house("Murka", 2, "White", "Ivan");
    WildCat wild("Tiger", 5, "Striped", "Taiga");
    PersianCat persian("Fluffy", 4, "Beige", 15);

    cout << "\n--- Total Cats Count: " << Cat::getCount() << " ---" << endl;

    cout << "\n--- Calling Methods via Derived Objects ---" << endl;
    house.sound();
    wild.sound();
    persian.sound();

    cout << "\n--- Calling Methods via Base Class Pointers ---" << endl;
    Cat* ptr1 = &house;
    Cat* ptr2 = &wild;
    Cat* ptr3 = &persian;

    ptr1->sound();
    ptr2->sound();
    ptr3->sound();

    cout << "\n--- Specific Methods ---" << endl;
    house.play();
    wild.hunt();
    persian.groom();

    cout << "\n--- End of Main, Destroying Objects ---" << endl;
    return 0;
}