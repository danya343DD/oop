#pragma once
#include "StringHolder.h"

using namespace std;

class ReverseString : public StringHolder {
    char* revStr;
public:
    ReverseString(const char* s);
    ~ReverseString() override;
    void print() const override;
};
