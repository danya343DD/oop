#include <fstream>
#include <string>
#include "Point.h"
#include <iostream>

using namespace std;
void Point::enterCoordinates() {
	cout << "Введите значение x: ";
	cin >> x;
	cout << "Введите значение y: ";
	cin >> y;
	cout << "Введите значение z: ";
	cin >> z;
}

void Point::printCoordinates() {
	cout << "\nКоординаты:" << endl;
	cout << "x: " << x << endl;
	cout << "y: " << y << endl;
	cout << "z: " << z << endl;
}

void Point::saveToFile() {
	ofstream file(FILE_NAME);
	if (file.is_open()) {
		file << x << " " << y << " " << z;
		file.close();
		cout << "Координаты сохранены в файл " << FILE_NAME << endl;
	}
	else {
		cerr << "Не открывается файл для записи" << endl;
	}
}

bool Point::loadFromFile() {
	ifstream file(FILE_NAME);
	if (file.is_open()) {
		file >> x >> y >> z;
		file.close();
		cout << "Координаты загружены из файла " << FILE_NAME << endl;
		return true;
	}
	else {
		cout << "Ошибка загрузки из файла " << FILE_NAME << endl;
		return false;
	}
}