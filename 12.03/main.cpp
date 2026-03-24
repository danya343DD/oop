#include <iostream>
#include "Set.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << " ТЕСТ КЛАССА SET \n\n";

    Set A(10);
    A += 3;
    A += 8;
    A += 46;
    A += 5;
    A += 11;

    Set B(10);
    B += 18;
    B += 8;
    B += 90;
    B += 11;
    B += 2;

    cout << "Множество A: " << A << endl;
    cout << "Множество B: " << B << endl;
    cout << endl;

    cout << " Проверка принадлежности " << endl;
    cout << "8 принадлежит A: " << (A.contains(8) ? "да" : "нет") << endl;
    cout << "7 принадлежит A: " << (A.contains(7) ? "да" : "нет") << endl;
    cout << endl;

    cout << " Добавление элемента " << endl;
    Set C = A + 4;
    cout << "A + 4 = " << C << endl;
    Set D = A + 3;
    cout << "A + 3 (уже есть) = " << D << endl;
    cout << endl;

    cout << " Удаление элемента " << endl;
    Set E = A - 8;
    cout << "A - 8 = " << E << endl;
    cout << endl;

    cout << " Объединение множеств " << endl;
    Set unionSet = A + B;
    cout << "A + B = " << unionSet << endl;
    cout << endl;

    cout << " Пересечение множеств " << endl;
    Set intersectionSet = A * B;
    cout << "A * B = " << intersectionSet << endl;
    cout << endl;

    cout << " Разность множеств " << endl;
    Set differenceSet = A - B;
    cout << "A - B = " << differenceSet << endl;
    cout << endl;

    cout << " Сравнение множеств " << endl;
    Set F = A;
    cout << "A == F: " << (A == F ? "да" : "нет") << endl;
    cout << "A == B: " << (A == B ? "да" : "нет") << endl;
    cout << "A != B: " << (A != B ? "да" : "нет") << endl;
    cout << endl;

    cout << " Операции присваивания " << endl;
    Set G;
    G = A;
    cout << "G = A, G = " << G << endl;
    cout << endl;

    cout << " Составные операции " << endl;
    Set H = A;
    H += 100;
    cout << "H += 100, H = " << H << endl;
    H -= 100;
    cout << "H -= 100, H = " << H << endl;
    H *= B;
    cout << "H *= B, H = " << H << endl;
    cout << endl;

    cout << " ПРОГРАММА ЗАВЕРШЕНА \n";

    return 0;
}