#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Осмысленные имена структуры и её полей
struct Task {
    string description;
    int priority;
    bool isCompleted;
};

// Вспомогательная функция для очистки буфера ввода (обработка ошибок)
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Функция выполняет одно действие - сбор и валидацию данных
vector<Task> readTasks(int taskCount) {
    vector<Task> tasks;
    tasks.reserve(taskCount); // Оптимизация выделения памяти

    for (int i = 0; i < taskCount; ++i) {
        Task currentTask;
        currentTask.isCompleted = false;

        cout << "\nTask " << i + 1 << " description: ";
        getline(cin, currentTask.description);

        // Безопасный ввод и проверка диапазона приоритета (1-5)
        while (true) {
            cout << "Priority (1-5): ";
            if (cin >> currentTask.priority && currentTask.priority >= 1 && currentTask.priority <= 5) {
                clearInputBuffer(); // Очищаем '\n' после ввода числа
                break;
            }
            cout << "Invalid input. Please enter a number between 1 and 5.\n";
            clearInputBuffer();
        }
        tasks.push_back(currentTask);
    }
    return tasks;
}

// Использование современного C++: sort с лямбда-выражением
void sortTasksByPriority(vector<Task>& tasks) {
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.priority > b.priority;
        });
}

// Константность: мы не меняем состояние вектора при выводе
void printTopTasks(const vector<Task>& tasks, int topCount) {
    cout << "\n--- Top " << topCount << " tasks ---\n";
    // Защита от выхода за пределы вектора, если задач меньше, чем topCount
    int count = min(static_cast<int>(tasks.size()), topCount);

    for (int i = 0; i < count; ++i) {
        cout << tasks[i].description << " (Priority: " << tasks[i].priority << ")\n";
    }
}

int main() {
    int taskCount = 0;

    // Безопасный ввод количества задач
    while (true) {
        cout << "Enter number of tasks: ";
        if (cin >> taskCount && taskCount >= 0) {
            clearInputBuffer(); // Очищаем '\n' после ввода числа
            break;
        }
        cout << "Invalid input. Please enter a positive integer.\n";
        clearInputBuffer();
    }

    // Обработка пустого списка
    if (taskCount == 0) {
        cout << "No tasks to process.\n";
        return 0;
    }

    // Структурированная логика программы
    vector<Task> tasks = readTasks(taskCount);
    sortTasksByPriority(tasks);
    printTopTasks(tasks, 3);

    return 0;
}