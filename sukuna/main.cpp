#include "Student.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "=== Тестирование конструкторов ===" << endl << endl;

    
    cout << "1. Конструктор по умолчанию:" << endl;
    Student student1;
    student1.setFullName("Иванов Иван Иванович");
    student1.setGroupNumber("ПИ-201");
    cout << endl;

    
    cout << "2. Конструктор с параметрами:" << endl;
    Student student2("Петров Петр Петрович", "ПИ-202");
    student2.outputData();
    cout << endl;

    
    cout << "3. Конструктор копирования:" << endl;
    Student student3(student2);
    cout << "Копия студента: " << student3.getFullName() << endl;
    cout << endl;

    
    cout << "4. Ввод данных студента:" << endl;
    Student student4;
    student4.inputData();
    student4.outputData();

   
    cout << "5. Оператор присваивания:" << endl;
    Student student5;
    student5 = student2;
    cout << "Присвоен студент: " << student5.getFullName() << endl;
    cout << endl;

    cout << "=== Конец программы ===" << endl;
    cout << "Сейчас будут вызваны деструкторы..." << endl << endl;

    return 0;
}