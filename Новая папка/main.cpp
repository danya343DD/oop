#include <iostream>
#include "Date.h"
#include "MyString.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru")
    cout << " Задание 1: Класс Date " << endl;
    Date d1(25, 12, 2023);
    Date d2(1, 1, 2024);

    cout << "Дата 1: "; d1.print(); cout << endl;
    cout << "Дата 2: "; d2.print(); cout << endl;

    
    int diff = d2 - d1;
    cout << "Разность между датами: " << diff << " дней" << endl;

    
    int addDays = 40;
    Date d3 = d1 + addDays;
    cout << "Дата 1 + " << addDays << " дней = ";
    d3.print(); cout << endl << endl;


    cout << " Задание 2: Класс MyString " << endl;
    MyString s1("sdqcg");
    MyString s2("rgfas34");

    cout << "Строка 1: "; s1.print(); cout << endl;
    cout << "Строка 2: "; s2.print(); cout << endl;

    
    MyString s3 = s1 * s2;
    cout << "Результат пересечения (s1 * s2): ";
    s3.print(); cout << endl;

    return 0;
}