#pragma once
#include "Shape.h"

using namespace std;

class Circle : public Shape {
public:
    void draw() const override;
};