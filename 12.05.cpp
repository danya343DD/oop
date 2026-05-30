#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <limits>
#include <iomanip>

//структура студента с использованием современных контейнеров STL
struct Student {
    std::string name;
    std::vector<int> grades;
    double avg = 0; //храним один раз для оптимизации сортировки
};

//константа для топ-студентов
constexpr size_t TOP_STUDENTS_COUNT = 3;

//вычисление среднего балла с использованием std::accumulate
void computeAverage(Student& s) {
    if (s.grades.empty()) {
        s.avg = 0;
        return;
    }
    //вычисляем сумму элементов и делим на их количество
    double sum = std::accumulate(s.grades.begin(), s.grades.end(), 0);
    s.avg = sum / s.grades.size();
}

//функция для очистки буфера ввода в случае ошибок
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

//логический блок чтения данных с валидацией
std::vector<Student> readStudents() {
    int n = 0;
    std::cout << "Enter number of students: ";
    while (!(std::cin >> n) || n < 0) {
        std::cout << "Invalid input. Enter a positive number for students: ";
        clearInputBuffer();
    }

    if (n == 0) return {};

    std::vector<Student> students;
    students.reserve(n); //оптимизация памяти: избегаем лишних реаллокаций

    for (int i = 0; i < n; ++i) {
        Student s;
        std::cout << "\nStudent " << i + 1 << "\n";
        std::cout << "Enter name: ";

        //очищаем остаточный ньюлайн из потока перед getline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, s.name);

        int m = 0;
        std::cout << "Enter number of grades: ";
        while (!(std::cin >> m) || m <= 0) {
            std::cout << "Invalid input. Number of grades must be greater than 0: ";
            clearInputBuffer();
        }

        s.grades.resize(m);
        for (int j = 0; j < m; ++j) {
            std::cout << "Grade " << j + 1 << ": ";
            while (!(std::cin >> s.grades[j]) || s.grades[j] < 0) {
                std::cout << "Invalid grade. Enter a valid non-negative integer: ";
                clearInputBuffer();
            }
        }

        computeAverage(s);
        students.push_back(std::move(s)); //перемещаем объект, избегая копирования
    }
    return students;
}

//вывод среднего балла всех студентов
void printAverages(const std::vector<Student>& students) {
    std::cout << "\nAverage Grades\n";
    for (const auto& s : students) {
        std::cout << s.name << " average: " << std::fixed << std::setprecision(2) << s.avg << "\n";
    }
}

//вывод топ-3 студентов с учетом крайних случаев
void printTop(const std::vector<Student>& students) {
    //корректно обрабатываем случай, если студентов меньше трех
    size_t count = std::min(students.size(), TOP_STUDENTS_COUNT);

    std::cout << "\nTop " << count << " students:\n";
    for (size_t i = 0; i < count; ++i) {
        std::cout << i + 1 << ". " << students[i].name << " (" << std::fixed << std::setprecision(2) << students[i].avg << ")\n";
    }
}

//вывод полного отсортированного списка студентов
void printSorted(const std::vector<Student>& students) {
    std::cout << "\nSorted list of all students:\n";
    for (const auto& s : students) {
        std::cout << s.name << " - " << std::fixed << std::setprecision(2) << s.avg << "\n";
    }
}

int main() {
    //безопасный ввод данных
    std::vector<Student> students = readStudents();

    if (students.empty()) {
        std::cout << "No students to process.\n";
        return 0;
    }

    //вывод промежуточных средних баллов
    printAverages(students);

    //быстрая эффективная сортировка O(N log N) вместо пузырьковой O(N^2)
    //используем лямбда-функцию для кастомного компаратора (по убыванию среднего балла)
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.avg > b.avg;
        });

    //модульный вывод результатов
    printTop(students);
    printSorted(students);

    return 0;
}