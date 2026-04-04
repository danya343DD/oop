
#pragma once
#include "Animal.h"

using namespace std;

class Bird : public Animal {
public:
    void speak() const override;
};
