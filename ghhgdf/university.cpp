#include <iostream>
#include <vector>

using namespace std;

class Student {
public:
    string name;

    Student(string n) {
        name = n;
    }

    void show() {
        cout << "Студент: " << name << endl;
    }
};

class University {
private:
    vector<Student*> students;

public:
    void addStudent(Student* s) {
        students.push_back(s);
    }

    void showStudents() {
        cout << "Студенты университета:" << endl;
        for (int i = 0; i < students.size(); i++) {
            students[i]->show();
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    
    Student s1("Иван");
    Student s2("Анна");

    University uni;

    uni.addStudent(&s1);
    uni.addStudent(&s2);

    uni.showStudents();

    return 0;
}