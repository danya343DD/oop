#include "Student.h"
#include "Person.h"
#include "Apartment.h"
#include "House.h"
#include <iostream>
#include <utility>

using namespace std;

int main() {
    cout << " Task 1: Student Move Constructor " << endl;
    Student student1("Alice Smith", "ST12345");
    student1.print();

    Student student2 = move(student1);
    student2.print();
    student1.print();

    cout << "\n Task 2: House Project Move Constructors " << endl;
    Person* person1 = new Person("Bob Johnson", "123 Maple St");
    Person* person2 = new Person("Carol White", "456 Oak Ave");

    Apartment* apt1 = new Apartment(101);
    apt1->addResident(person1);
    apt1->addResident(person2);

    House house1("Metropolis", "Main St", 10);
    house1.addApartment(apt1);
    house1.print();

    House house2 = move(house1);
    house2.print();
    house1.print();

    return 0;
}