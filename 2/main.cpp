#include <iostream>
#include <string>
#include "Book.h"
#include "Worker.h"

using namespace std;

void demonstrateBooks() {
    cout << "\n ЗАДАНИЕ 1: КНИГИ\n\n";

    const int BOOK_COUNT = 5;
    Book books[BOOK_COUNT] = {
        Book("Пушкин А.С.", "Евгений Онегин", "Азбука", 1833, 1000, 250),
        Book("Толстой Л.Н.", "Война и мир", "Эксмо", 1869, 500, 1200),
        Book("Пушкин А.С.", "Капитанская дочка", "Азбука", 1836, 800, 180),
        Book("Достоевский Ф.М.", "Преступление и наказание", "АСТ", 1866, 600, 650),
        Book("Толстой Л.Н.", "Анна Каренина", "Эксмо", 1878, 450, 850)
    };

    string searchAuthor = "Пушкин А.С.";
    cout << "\n Книги автора: " << searchAuthor << " ---\n";
    for (int i = 0; i < BOOK_COUNT; i++) {
        if (books[i].getAuthor() == searchAuthor) {
            books[i].display();
        }
    }

    string searchPublisher = "Эксмо";
    cout << "\n Книги издательства: " << searchPublisher << " ---\n";
    for (int i = 0; i < BOOK_COUNT; i++) {
        if (books[i].getPublisher() == searchPublisher) {
            books[i].display();
        }
    }

    int searchYear = 1850;
    cout << "\n Книги, выпущенные после " << searchYear << " года ---\n";
    for (int i = 0; i < BOOK_COUNT; i++) {
        if (books[i].getYear() > searchYear) {
            books[i].display();
        }
    }
}

void demonstrateWorkers() {
    cout << "\n ЗАДАНИЕ 2: РАБОТНИКИ \n\n";

    const int WORKER_COUNT = 5;
    Worker workers[WORKER_COUNT] = {
        Worker("Иванов И.И.", "Инженер", 2015, 75000),
        Worker("Петров П.П.", "Менеджер", 2018, 65000),
        Worker("Сидоров С.С.", "Инженер", 2010, 85000),
        Worker("Козлова А.А.", "Директор", 2005, 120000),
        Worker("Новиков Н.Н.", "Инженер", 2020, 60000)
    };

    int currentYear = 2026;

    int minExperience = 5;
    cout << "\n Работники со стажем более " << minExperience << " лет ---\n";
    for (int i = 0; i < WORKER_COUNT; i++) {
        if (workers[i].getWorkExperience(currentYear) > minExperience) {
            cout << "Стаж: " << workers[i].getWorkExperience(currentYear) << " лет\n";
            workers[i].display();
        }
    }

    double minSalary = 70000;
    cout << "\n Работники с зарплатой более " << minSalary << " ---\n";
    for (int i = 0; i < WORKER_COUNT; i++) {
        if (workers[i].getSalary() > minSalary) {
            workers[i].display();
        }
    }

    string searchPosition = "Инженер";
    cout << "\n Работники должности: " << searchPosition << " ---\n";
    for (int i = 0; i < WORKER_COUNT; i++) {
        if (workers[i].getPosition() == searchPosition) {
            workers[i].display();
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    demonstrateBooks();
    demonstrateWorkers();

    cout << "\n ПРОГРАММА ЗАВЕРШЕНА \n";

    return 0;
}