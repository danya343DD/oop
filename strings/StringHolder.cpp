#include "StringHolder.h"
#include <iostream>

using namespace std;

int getStringLength(const char* s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

void copyString(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

StringHolder::StringHolder(const char* s) {
    int len = getStringLength(s);
    str = new char[len + 1];
    copyString(str, s);
}

StringHolder::~StringHolder() {
    cout << "StringHolder destructor for \"" << str << "\"\n";
    delete[] str;
}

void StringHolder::print() const {
    cout << str << "\n";
}
