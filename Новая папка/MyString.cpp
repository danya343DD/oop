#include "MyString.h"

using namespace std;

MyString::MyString(const string& s) : str(s) {}


MyString MyString::operator*(const MyString& other) const {
    string result = "";

    
    for (char c : this->str) {
        
        if (other.str.find(c) != string::npos && result.find(c) == string::npos) {
            result += c;
        }
    }

    return MyString(result);
}

void MyString::print() const {
    cout << str;
}
