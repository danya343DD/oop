#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* str;
    int size;
    static int count;

public:
    String() : String(80) {}

    String(int n) {
        size = n;
        str = new char[size + 1];
        str[0] = '\0';
        count++;
    }

    String(const char* s) : String(strlen(s)) {
        strcpy(str, s);
    }

    ~String() {
        delete[] str;
        count--;
    }

    void input() {
        cout << "Input: ";
        cin.getline(str, size + 1);
    }

    void output() {
        cout << "Output: " << str << endl;
    }

    static int getCount() {
        return count;
    }
};

int String::count = 0;

int main() {
    String s1;
    String s2(20);
    String s3("Test");

    s1.input();
    s1.output();
    s3.output();

    cout << "Count: " << String::getCount() << endl;

    return 0;
}
