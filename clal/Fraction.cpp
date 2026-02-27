#include "Fraction.h"
#include <iostream>
#include <string>

using namespace std;

void Fraction::enterFraction() {
	cout << "¬ведите числитель:";
	cin >> num;
	cout << "¬ведите знаменатель:";
	cin >> den;
}

void Fraction::printFraction() {
	cout << "ƒробь:" << endl;
	cout << num << "\n-\n" << den << endl;
}

