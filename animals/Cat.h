#pragma once
#include "Animal.h"

using namespace std;

class Cat : public Animal {
public:
    void speak() const override;
};

