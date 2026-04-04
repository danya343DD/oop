#include "ReverseString.h"
#include <iostream>

using namespace std;

extern int getStringLength(const char* s);

ReverseString::ReverseString(const char* s) : StringHolder(s) {
    int len = getStringLength(s);
    revStr = new char[len + 1];
    for (int i = 0; i < len; ++i) {
        revStr[i] = s[len - 1 - i];
    }
    revStr[len] = '\0';
}

ReverseString::~ReverseString() {
    cout << "ReverseString destructor\n";
    delete[] revStr;
}

void ReverseString::print() const {
    cout << revStr << "\n";
}
