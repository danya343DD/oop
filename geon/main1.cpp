#include <iostream>
#include "Geometry.h"

using namespace std;
using Geometry::circleArea;

int main() {
    cout << circleArea(5.0) << "\n";
    cout << Geometry::rectangleArea(4.0, 6.0) << "\n";

    Geometry::Shapes::Circle c(5.0);
    cout << c.area() << "\n";

    return 0;
}