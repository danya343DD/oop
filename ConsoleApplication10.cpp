#include <iostream>
#include <string>

using namespace std;

// ОТРЕФАКТОРЕННЫЕ ФУНКЦИИ ДЛЯ ПРОГРАММЫ 1 (ОЧИСТКА ВВОДА)

[span_1](start_span)// Выделение метода (Extract Method) для парсинга и очистки строки[span_1](end_span)
int extractAndCleanNumber(const string& str) {
    string cleaned = "";
    bool isNegative = false;
    bool digitFound = false;

    for (char ch : str) {
        if (ch == '-' && !digitFound) {
            isNegative = true;
        }
        if (ch >= '0' && ch <= '9') {
            cleaned += ch;
            digitFound = true;
        }
    }

    if (cleaned.empty()) {
        return 0;
    }

    int result = stoi(cleaned);
    return isNegative ? -result : result;
}

void runProgram1() {
    cout << "\nПрограмма 1: Очистка ввода и возведение в квадрат\n";
    string input;
    cout << "Введите строку (например, b5, -a10 или 25): ";
    cin >> input;

    int number = extractAndCleanNumber(input);

    [span_2] (start_span)// Оптимизация: использование типа long long для предотвращения переполнения при умножении[span_2](end_span)
        long long square = static_cast<long long>(number) * number;

    cout << "Вы ввели (выделено число): " << number << " (Только номер).\n";
    cout << "Квадрат числа: " << square << "\n";
}

// ОТРЕФАКТОРЕННЫЕ ФУНКЦИИ ДЛЯ ПРОГРАММЫ 2 (КАЛЬКУЛЯТОР)

[span_3](start_span)// Оптимизация: Проверка всех переменных, вводимых с клавиатуры[span_3](end_span)
double getValidatedNumber(const string& prompt) {
    double num;
    while (true) {
        cout << prompt;
        if (cin >> num) {
            return num;
        }
        cout << "Ошибка! Введено неверное число. Попробуйте еще раз.\n";
        cin.clear(); [span_4] (start_span)// Сброс флага ошибки потока[span_4](end_span)
            cin.ignore(10000, '\n'); [span_5] (start_span)// Очистка буфера[span_5](end_span)
    }
}

[span_6](start_span)// Проверка корректности ввода оператора[span_6](end_span)
char getValidatedOperator() {
    char op;
    while (true) {
        cout << "Введите оператор (+, -, *, /, ^): ";
        cin >> op;
        if (op == '+'  op == '-'  op == '*'  op == '/'  op == '^') {
            return op;
        }
        cout << "Ошибка! Неверный оператор.\n";
    }
}

[span_7](start_span)[span_8](start_span)[span_9](start_span)// Оптимизация производительности: замена std::pow быстрым итеративным циклом[span_7](end_span)[span_8](end_span)[span_9](end_span)
double power(double base, int exp) {
    if (exp == 0) return 1.0;
    double res = 1.0;
    long long absExp = abs(static_cast<long long>(exp));

    for (long long i = 0; i < absExp; ++i) {
        res *= base;
    }

    return (exp < 0) ? (1.0 / res) : res;
}

void runProgram2() {
    cout << "\nПрограмма 2: Калькулятор с валидацией\n";
    double num1 = getValidatedNumber("Введите первое число: ");
    char op = getValidatedOperator();
    double num2 = getValidatedNumber("Введите второе число: ");

    [span_10] (start_span)// Замена громоздкого if-else на switch (Замена условного оператора полиморфизмом/структурированием)[span_10](end_span)
        switch (op) {
        case '+':
            cout << "Результат: " << num1 + num2 << "\n";
            break;
        case '-':
            cout << "Результат: " << num1 - num2 << "\n";
            break;
        case '*':
            cout << "Результат: " << num1 * num2 << "\n";
            break;
        case '/':
            if (num2 == 0.0) {
                cout << "Ошибка: деление на ноль невозможно!\n";
            }
            else {
                cout << "Результат: " << num1 / num2 << "\n";
            }
            break; case '^':
                // Приведение степени к целому числу для работы оптимизированного алгоритма
                cout << "Результат: " << power(num1, static_cast<int>(num2)) << "\n";
                break;
        }
}

// ГЛАВНОЕ МЕНЮ (ТОЧКА ВХОДА)
int main() {
    // Настройка локализации для корректного вывода на русском языке
    setlocale(LC_ALL, "Russian");

    int choice;
    while (true) {
        cout << "ПРАКТИЧЕСКОЕ ЗАНЯТИЕ №25 (МЕНЮ ПРОВЕРКИ)\n";
        cout << "1. Запустить Программу 1 (Очистка и квадрат)\n";
        cout << "2. Запустить Программу 2 (Калькулятор)\n";
        cout << "3. Выйти из программы\n";
        cout << "Выберите пункт меню: ";

        if (!(cin >> choice)) {
            cout << "Неверный выбор! Завершение работы.\n";
            break;
        }

        if (choice == 1) {
            runProgram1();
        }
        else if (choice == 2) {
            runProgram2();
        }
        else if (choice == 3) {
            cout << "Выход из лабораторной работы. До свидания!\n";
            break;
        }
        else {
            cout << "Неверный пункт! Пожалуйста, выберите 1, 2 или 3.\n";
        }
    }
    return 0;
}