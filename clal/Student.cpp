#include <iostream>
#include <conio.h>
#include <string>

#include "Student.h"

using namespace std;

void Student::enterStudent() {
	cout << "Введите ФИО: ";
	getline(cin, name);
	cout << "Введите дату: ";
	getline(cin, date);
	cout << "Введите номер телефона: ";
	cin >> number;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Введите город студента: ";
	getline(cin, city);
	cout << "Введите страну студента: ";
	getline(cin, country);
	cout << "Введите название учебного заведения: ";
	getline(cin, school_name);
	cout << "Введите город учебного заведения: ";
	getline(cin, school_city);
	cout << "Введите страну учебного заведения: ";
	getline(cin, school_country);
	cout << "Введите группу: ";
	getline(cin, group);
}

void Student::printStudent() {
	cout << "\nДанные о студенте: " << endl;
	cout << name << endl;
	cout << date << endl;
	cout << number << endl;
	cout << city << endl;
	cout << country << endl;
	cout << school_name << endl;
	cout << school_city << endl;
	cout << school_country << endl;
	cout << group << endl;
}
