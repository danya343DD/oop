#include "Student.h"
#include <iostream>
#include <cstring>
using namespace std;


Student::Student()
    : fullName(nullptr), birthDate(""), phone(""), city(""),
    country(""), universityName(""), univCity(""),
    univCountry(""), groupNumber("") {
    cout << "Вызван конструктор по умолчанию" << endl;
}

Student::Student(const char* name, const string& group)
    : birthDate(""), phone(""), city(""), country(""),
    universityName(""), univCity(""), univCountry(""),
    groupNumber(group) {
    cout << "Вызван конструктор с параметрами" << endl;
    if (name != nullptr) {
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
    }
    else {
        fullName = nullptr;
    }
}

Student::Student(const Student& other)
    : birthDate(other.birthDate), phone(other.phone),
    city(other.city), country(other.country),
    universityName(other.universityName), univCity(other.univCity),
    univCountry(other.univCountry), groupNumber(other.groupNumber) {
    cout << "Вызван конструктор копирования" << endl;
    if (other.fullName != nullptr) {
        fullName = new char[strlen(other.fullName) + 1];
        strcpy(fullName, other.fullName);
    }
    else {
        fullName = nullptr;
    }
}


Student::~Student() {
    cout << "Вызван деструктор для: ";
    if (fullName != nullptr) {
        cout << fullName << endl;
        delete[] fullName;
        fullName = nullptr;
    }
    else {
        cout << "(без имени)" << endl;
    }
}

==

Student& Student::operator=(const Student& other) {
    cout << "Вызван оператор присваивания" << endl;
    if (this != &other) {
        delete[] fullName;

        if (other.fullName != nullptr) {
            fullName = new char[strlen(other.fullName) + 1];
            strcpy(fullName, other.fullName);
        }
        else {
            fullName = nullptr;
        }

        birthDate = other.birthDate;
        phone = other.phone;
        city = other.city;
        country = other.country;
        universityName = other.universityName;
        univCity = other.univCity;
        univCountry = other.univCountry;
        groupNumber = other.groupNumber;
    }
    return *this;
}



void Student::inputData() {
    char tempName[100];

    cout << "Введите ФИО: ";
    cin.getline(tempName, 100);
    setFullName(tempName);

    cout << "Введите дату рождения: ";
    getline(cin, birthDate);

    cout << "Введите контактный телефон: ";
    getline(cin, phone);

    cout << "Введите город проживания: ";
    getline(cin, city);

    cout << "Введите страну проживания: ";
    getline(cin, country);

    cout << "Введите название учебного заведения: ";
    getline(cin, universityName);

    cout << "Введите город учебного заведения: ";
    getline(cin, univCity);

    cout << "Введите страну учебного заведения: ";
    getline(cin, univCountry);

    cout << "Введите номер группы: ";
    getline(cin, groupNumber);
}

void Student::outputData() const {
    cout << "\n===== Информация о студенте =====" << endl;
    cout << "ФИО: " << (fullName != nullptr ? fullName : "Не указано") << endl;
    cout << "Дата рождения: " << birthDate << endl;
    cout << "Телефон: " << phone << endl;
    cout << "Город проживания: " << city << endl;
    cout << "Страна проживания: " << country << endl;
    cout << "Учебное заведение: " << universityName << endl;
    cout << "Город университета: " << univCity << endl;
    cout << "Страна университета: " << univCountry << endl;
    cout << "Номер группы: " << groupNumber << endl;
    cout << "==================================" << endl;
}



const char* Student::getFullName() const {
    return fullName;
}

string Student::getBirthDate() const {
    return birthDate;
}

string Student::getPhone() const {
    return phone;
}

string Student::getCity() const {
    return city;
}

string Student::getCountry() const {
    return country;
}

string Student::getUniversityName() const {
    return universityName;
}

string Student::getUnivCity() const {
    return univCity;
}

string Student::getUnivCountry() const {
    return univCountry;
}

string Student::getGroupNumber() const {
    return groupNumber;
}



void Student::setFullName(const char* name) {
    delete[] fullName;
    if (name != nullptr) {
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
    }
    else {
        fullName = nullptr;
    }
}

void Student::setBirthDate(const string& date) {
    birthDate = date;
}

void Student::setPhone(const string& phoneNumber) {
    phone = phoneNumber;
}

void Student::setCity(const string& studentCity) {
    city = studentCity;
}

void Student::setCountry(const string& studentCountry) {
    country = studentCountry;
}

void Student::setUniversityName(const string& uniName) {
    universityName = uniName;
}

void Student::setUnivCity(const string& city) {
    univCity = city;
}

void Student::setUnivCountry(const string& country) {
    univCountry = country;
}

void Student::setGroupNumber(const string& group) {
    groupNumber = group;
}