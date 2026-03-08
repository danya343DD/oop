#include <iostream>
#include "Geometry.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    cout << "Площадь треугольника (10, 5): "
        << Geometry::triangle(10, 5) << endl;

    cout << "Площадь треугольника (3, 4, 5): "
        << Geometry::triangle(3, 4, 5) << endl;

    cout << "Площадь прямоугольника (4, 6): "
        << Geometry::rectangle(4, 6) << endl;

    cout << "Площадь квадрата (5): "
        << Geometry::square(5) << endl;

    cout << "Площадь ромба (8, 6): "
        << Geometry::rhombus(8, 6) << endl;

    cout << "\nВсего вычислений площади: "
        << Geometry::getCalcCount() << endl;

    return 0;
}