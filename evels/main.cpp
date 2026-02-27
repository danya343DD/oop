#include <iostream> 
#include "Elevator.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	Elevator elevator1;

	cout << "-------Лифт с использованием конструктора по умолчанию----------" << endl;

	elevator1.setBotFloor(1);
	elevator1.setTopFloor(10);
	elevator1.setIsOn(1);
	elevator1.setCondition(0);
	elevator1.setFloor(5);

	elevator1.printElevator();
	elevator1.callElevator();

	cout << endl;
	cout << "------------Лифты с использованием геттеров---------------" << endl;
	Elevator elevator2(1, 10, 0, 1, 9);

	cout << "Диапозон лифта от " << elevator2.getBotFloor()
		<< " до " << elevator2.getTopFloor() << endl;

	if (elevator2.getIsOn() == true) {
		cout << "Лифт Включен" << endl;
	}
	else {
		cout << "Лифт Отключен" << endl;
	}

	cout << "Состояние: ";
	if (elevator2.getCondition() == true) {
		cout << "Работает" << endl;;
	}
	else {
		cout << "Не работает" << endl;
	}
	cout << "Текущий этаж: " << elevator2.getFloor() << endl;
	elevator2.callElevator();

	cout << endl;
	Elevator elevator3(1, 10, 1, 1, 3);

	cout << "Диапозон лифта от " << elevator3.getBotFloor()
		<< " до " << elevator3.getTopFloor() << endl;

	if (elevator3.getIsOn() == true) {
		cout << "Лифт Включен" << endl;
	}
	else {
		cout << "Лифт Отключен" << endl;
	}

	cout << "Состояние: ";
	if (elevator3.getCondition() == true) {
		cout << "Работает" << endl;;
	}
	else {
		cout << "Не работает" << endl;
	}
	cout << "Текущий этаж: " << elevator3.getFloor() << endl;
	elevator3.callElevator();
	return 0;
}