#include "Student.h"
#include <iostream>
using namespace std;

int main() {
   
    setlocale(LC_ALL, "Russian");

    Student student1;

    cout << "Введите данные студента:" << endl;
    student1.inputData();

    student1.outputData();

    cout << "\nФИО студента: " << student1.getFullName() << endl;
    cout << "Группа: " << student1.getGroupNumber() << endl;

    student1.setPhone("+7 (999) 123-45-67");
    cout << "\nОбновленный телефон: " << student1.getPhone() << endl;

    return 0;
}