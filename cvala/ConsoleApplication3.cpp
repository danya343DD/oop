#include "Student.h"
#include <iostream>
using namespace std;



void Student::inputData() {
    cout << "Введите ФИО: ";
    getline(cin, fullName);

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
    cout << "ФИО: " << fullName << endl;
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



string Student::getFullName() const {
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



void Student::setFullName(const string& name) {
    fullName = name;
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