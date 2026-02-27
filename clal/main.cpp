#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <fstream>

#include "Student.h" // Класс Student
#include "Point.h" // Класс Point
#include "Fraction.h" // Класс Fraction

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Работа с классом Student
	Student student1;

	student1.enterStudent();
	student1.printStudent();

	cout << endl;

	// Работа с классом Point
	Point coordinates1;

	coordinates1.enterCoordinates();
	coordinates1.saveToFile();

	if (coordinates1.loadFromFile()) {
		coordinates1.printCoordinates();
	}

	// Работа с классом Fraction
	Fraction fraction1, fraction2;

	fraction1.enterFraction();
	fraction1.printFraction();

	fraction2.enterFraction();
	fraction2.printFraction();

	_getch();
	return 0;
}