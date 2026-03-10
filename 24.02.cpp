#include <iostream>
#include <cmath>
using namespace std;

// ВАРИАНТ 4: Решение биквадратного уравнения
void variant4() {
    double a, b, c;
    cout << "Вариант 4: Биквадратное уравнение ax^4 + bx^2 + c = 0" << endl;
    cout << "Введите a, b, c: ";
    cin >> a >> b >> c;

    double D = b * b - 4 * a * c;
    if (D < 0) {
        cout << "Корней нет" << endl;
        return;
    }

    double y1 = (-b + sqrt(D)) / (2 * a);
    double y2 = (-b - sqrt(D)) / (2 * a);

    cout << "Корни: ";
    if (y1 >= 0) {
        cout << "x = " << sqrt(y1) << ", x = " << -sqrt(y1) << endl;
    }
    if (y2 >= 0 && y2 != y1) {
        cout << "x = " << sqrt(y2) << ", x = " << -sqrt(y2) << endl;
    }
}

// ВАРИАНТ 5: Последовательный поиск
void variant5() {
    int n, key;
    cout << "Вариант 5: Последовательный поиск" << endl;
    cout << "Введите количество элементов: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Введите элементы: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Введите искомый элемент: ";
    cin >> key;

    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            index = i;
            break;
        }
    }

    if (index != -1)
        cout << "Найден на позиции: " << index << endl;
    else
        cout << "Не найден" << endl;

    delete[] arr;
}

// ВАРИАНТ 6: Бинарный поиск
void variant6() {
    int n, key;
    cout << "Вариант 6: Бинарный поиск" << endl;
    cout << "Введите количество элементов: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Введите отсортированные элементы: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Введите искомый элемент: ";
    cin >> key;

    int left = 0, right = n - 1;
    int index = -1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) {
            index = mid;
            break;
        }
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    if (index != -1)
        cout << "Найден на позиции: " << index << endl;
    else
        cout << "Не найден" << endl;

    delete[] arr;
}

// ВАРИАНТ 7: Интерполяционный поиск
void variant7() {
    int n, key;
    cout << "Вариант 7: Интерполяционный поиск" << endl;
    cout << "Введите количество элементов: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Введите отсортированные элементы: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Введите искомый элемент: ";
    cin >> key;

    int left = 0, right = n - 1;
    int index = -1;

    while (left <= right && key >= arr[left] && key <= arr[right]) {
        int pos = left + ((key - arr[left]) * (right - left)) / (arr[right] - arr[left]);

        if (arr[pos] == key) {
            index = pos;
            break;
        }
        else if (arr[pos] < key)
            left = pos + 1;
        else
            right = pos - 1;
    }

    if (index != -1)
        cout << "Найден на позиции: " << index << endl;
    else
        cout << "Не найден" << endl;

    delete[] arr;
}

// ВАРИАНТ 8: Элементы больше C
void variant8() {
    int n, C;
    cout << "Вариант 8: Элементы больше C" << endl;
    cout << "Введите количество элементов: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Введите элементы: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Введите C: ";
    cin >> C;

    int count = 0;
    cout << "Индексы: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] > C) {
            cout << i << " ";
            count++;
        }
    }
    cout << "Количество: " << count << endl;

    delete[] arr;
}

// ВАРИАНТ 9: Элементы меньше C
void variant9() {
    int n, C;
    cout << "Вариант 9: Элементы меньше C" << endl;
    cout << "Введите количество элементов: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Введите элементы: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Введите C: ";
    cin >> C;

    int count = 0;
    cout << "Индексы: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] < C) {
            cout << i << " ";
            count++;
        }
    }
    cout << "Количество: " << count << endl;

    delete[] arr;
}

// ВАРИАНТ 10: Элементы в диапазоне (A, B)
void variant10() {
    int n, A, B;
    cout << "Вариант 10: Элементы в диапазоне (A, B)" << endl;
    cout << "Введите количество элементов: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Введите элементы: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Введите A и B (A<B): ";
    cin >> A >> B;

    int count = 0;
    cout << "Индексы: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] > A && arr[i] < B) {
            cout << i << " ";
            count++;
        }
    }
    cout << "\nКоличество: " << count << endl;

    delete[] arr;
}

// ВАРИАНТ 11: Элементы < A И > B
void variant11() {
    int n, A, B;
    cout << "Вариант 11: Элементы < A и > B" << endl;
    cout << "Введите количество элементов: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Введите элементы: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Введите A и B (A<B): ";
    cin >> A >> B;

    int count = 0;
    cout << "Индексы: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] < A || arr[i] > B) {
            cout << i << " ";
            count++;
        }
    }
    cout << "\nКоличество: " << count << endl;

    delete[] arr;
}

// ВАРИАНТ 12: Метод деления отрезка пополам
void variant12() {
    double epsilon;
    cout << "Вариант 12: Метод деления отрезка пополам" << endl;
    cout << "Введите точность epsilon: ";
    cin >> epsilon;

    double a, b;
    cout << "Введите интервал [a, b]: ";
    cin >> a >> b;

    // Пример: x^2 - 2 = 0 (корень из 2)
    auto f = [](double x) { return x * x - 2; };

    while (b - a > epsilon) {
        double c = (a + b) / 2;
        if (f(c) == 0)
            break;
        else if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    cout << "Приближенный корень: " << (a + b) / 2 << endl;
}

int main() {
    int choice;
    cout << "Выберите вариант (4-12): ";
    cin >> choice;

    switch (choice) {
    case 4: variant4(); break;
    case 5: variant5(); break;
    case 6: variant6(); break;
    case 7: variant7(); break;
    case 8: variant8(); break;
    case 9: variant9(); break;
    case 10: variant10(); break;
    case 11: variant11(); break;
    case 12: variant12(); break;
    default: cout << "Неверный номер варианта" << endl;
    }

    return 0;
}