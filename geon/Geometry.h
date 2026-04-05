#pragma once

using namespace std;

namespace Geometry {
    const double PI = 3.14159;
    double circleArea(double radius);
    double rectangleArea(double width, double height);

    namespace Shapes {
        class Circle {
            double radius;
        public:
            Circle(double r);
            double area() const;
        };
    }
}
