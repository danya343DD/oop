#pragma once
#include "Animal.h"

using namespace std;

class Horse : public Animal {
public:
    void speak() const override;
};
