
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Subscriber {
public:
    char* fio;
    char homePhone[20];
    char workPhone[20];
    char mobilePhone[20];
    char additionalInfo[100];

    Subscriber() {
        fio = nullptr;
        homePhone[0] = workPhone[0] = mobilePhone[0] = additionalInfo[0] = '\0';
    }

    Subscriber(const char* name) {
        fio = new char[strlen(name) + 1];
        strcpy(fio, name);
        homePhone[0] = workPhone[0] = mobilePhone[0] = additionalInfo[0] = '\0';
    }

    ~Subscriber() {
        delete[] fio;
    }

    void display() {
        cout << "FIO: " << fio << endl;
        cout << "Home: " << homePhone << endl;
        cout << "Work: " << workPhone << endl;
        cout << "Mobile: " << mobilePhone << endl;
        cout << "Info: " << additionalInfo << endl;
        cout << "----------------" << endl;
    }
};

class PhoneBook {
public:
    Subscriber* subs;
    int count;

    PhoneBook() {
        subs = new Subscriber[100];
        count = 0;
    }

    ~PhoneBook() {
        delete[] subs;
    }

    void add(const char* fio, const char* home, const char* work, const char* mobile, const char* info) {
        subs[count].fio = new char[strlen(fio) + 1];
        strcpy(subs[count].fio, fio);
        strcpy(subs[count].homePhone, home);
        strcpy(subs[count].workPhone, work);
        strcpy(subs[count].mobilePhone, mobile);
        strcpy(subs[count].additionalInfo, info);
        count++;
    }

    void remove(const char* fio) {
        for (int i = 0; i < count; i++) {
            if (strcmp(subs[i].fio, fio) == 0) {
                for (int j = i; j < count - 1; j++) {
                    subs[j] = subs[j + 1];
                }
                count--;
                return;
            }
        }
    }

    void search(const char* fio) {
        for (int i = 0; i < count; i++) {
            if (strcmp(subs[i].fio, fio) == 0) {
                subs[i].display();
                return;
            }
        }
        cout << "Not found" << endl;
    }

    void showAll() {
        for (int i = 0; i < count; i++) {
            subs[i].display();
        }
    }

    void save(const char* filename) {
        ofstream file(filename);
        file << count << endl;
        for (int i = 0; i < count; i++) {
            file << subs[i].fio << endl;
            file << subs[i].homePhone << endl;
            file << subs[i].workPhone << endl;
            file << subs[i].mobilePhone << endl;
            file << subs[i].additionalInfo << endl;
        }
        file.close();
    }

    void load(const char* filename) {
        ifstream file(filename);
        if (!file.is_open()) return;
        file >> count;
        file.ignore();
        for (int i = 0; i < count; i++) {
            char buf[100];
            file.getline(buf, 100);
            subs[i].fio = new char[strlen(buf) + 1];
            strcpy(subs[i].fio, buf);
            file.getline(subs[i].homePhone, 20);
            file.getline(subs[i].workPhone, 20);
            file.getline(subs[i].mobilePhone, 20);
            file.getline(subs[i].additionalInfo, 100);
        }
        file.close();
    }
};

int main() {
    PhoneBook book;
    int choice;
    char fio[100], phone[20], info[100], filename[100];

    while (true) {
        cout << "1. Add  2. Delete  3. Search  4. Show All  5. Save  6. Load  0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 0) break;

        switch (choice) {
        case 1:
            cout << "FIO: "; cin.ignore(); cin.getline(fio, 100);
            cout << "Home phone: "; cin.getline(phone, 20);
            char home[20]; strcpy(home, phone);
            cout << "Work phone: "; cin.getline(phone, 20);
            char work[20]; strcpy(work, phone);
            cout << "Mobile phone: "; cin.getline(phone, 20);
            char mobile[20]; strcpy(mobile, phone);
            cout << "Info: "; cin.getline(info, 100);
            book.add(fio, home, work, mobile, info);
            break;

        case 2:
            cout << "FIO to delete: "; cin.ignore(); cin.getline(fio, 100);
            book.remove(fio);
            break;

        case 3:
            cout << "FIO to search: "; cin.ignore(); cin.getline(fio, 100);
            book.search(fio);
            break;

        case 4:
            book.showAll();
            break;

        case 5:
            cout << "Filename: "; cin.ignore(); cin.getline(filename, 100);
            book.save(filename);
            break;

        case 6:
            cout << "Filename: "; cin.ignore(); cin.getline(filename, 100);
            book.load(filename);
            break;
        }
    }
    return 0;
}
