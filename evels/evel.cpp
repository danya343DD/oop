#include "Elevator.h"
#include <iostream>
#include <string>
using namespace std;

Elevator::Elevator() {
	botFloor = 1;
	topFloor = 10;
	isOn = false;
	condition = false;
	floor = 1;
}

Elevator::Elevator(int bot, int top, bool iO, bool cond, int flor) {
	setBotFloor(bot);
	setTopFloor(top);
	setIsOn(iO);
	setCondition(cond);
	setFloor(flor);
}

void Elevator::setBotFloor(int bot) {
	botFloor = (bot <= 0) ? 1 : bot;
}

void Elevator::setTopFloor(int top) {
	topFloor = (top <= 0) ? 1 : top;
}

void Elevator::setIsOn(bool iO) {
	if (iO == true) {
		isOn = true;
	}
	else {
		isOn = false;
	}
}

void Elevator::setCondition(bool cond) {
	if (cond == true) {
		condition = true;
	}
	else {
		condition = false;
	}
}

void Elevator::setFloor(int flor) {
	if (flor > topFloor || flor < botFloor) {
		floor = 1;
	}
	else {
		floor = flor;
	}
}

void Elevator::printElevator() const {
	cout << "Диапозон лифта от " << botFloor
		<< " до " << topFloor << endl;

	if (isOn == true) {
		cout << "Лифт Включен" << endl;
	}
	else {
		cout << "Лифт Отключен" << endl;
	}

	cout << "Состояние: ";
	if (condition == true) {
		cout << "Работает" << endl;;
	}
	else {
		cout << "Не работает" << endl;
	}
	cout << "Текущий этаж: " << floor << endl;
}

void Elevator::callElevator() {
	int nowFloor;
	cout << "Куда хотите вызвать лифт(" << botFloor << "-"
		<< topFloor << "): ";
	cin >> nowFloor;

	if (nowFloor == floor) {
		cout << "Вы находитесь на одном этаже с лифтом" << endl;
		return;
	}
	else if (nowFloor > topFloor || nowFloor < botFloor) {
		cout << "Вы вызываете лифт не в диапозоне" << endl;
		return;
	}
	else if (isOn == false) {
		cout << "Лифт выключен" << endl;
		return;
	}
	else if (condition == false) {
		cout << "Лифт не работает" << endl;
		return;
	}
	floor = nowFloor;
	cout << "Вы вызвали лифт" << endl;
}