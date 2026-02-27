#pragma once
class Elevator
{
private:
	int botFloor; // нижний этаж
	int topFloor; // верхний этаж
	bool isOn; // Включен ли
	bool condition; // Состояние (работает или нет)
	int floor; // текущий этаж лифта

public:
	Elevator();

	Elevator(int botFloor, int topFloor, bool isOn, bool condition, int floor);

	// геттеры
	int getBotFloor() const { return botFloor; }
	int getTopFloor() const { return topFloor; }
	bool getIsOn() const { return isOn; }
	bool getCondition() const { return condition; }
	int getFloor() const { return floor; }

	// сеттеры
	void setBotFloor(int botFloor);
	void setTopFloor(int topFloor);
	void setIsOn(bool isOn);
	void setCondition(bool condition);
	void setFloor(int floor);

	// методы
	
	// Вывод
	void printElevator() const;

	// Вызов лифта
	void callElevator();
};


