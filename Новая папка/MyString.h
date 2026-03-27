#include <iostream>
#include <string>

using namespace std;

class MyString {
private:
    string str;

public:
    
    MyString(const string& s = "");

    
    MyString operator*(const MyString& other) const;

    
    void print() const;
};


