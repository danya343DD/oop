#include <iostream>
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

using namespace std;

void identifyAndDraw(Shape* s) {
    if (Circle* c = dynamic_cast<Circle*>(s)) {
        cout << "Type: Circle\n";
        c->draw();
    }
    else if (Rectangle* r = dynamic_cast<Rectangle*>(s)) {
        cout << "Type: Rectangle\n";
        r->draw();
    }
}

int main() {
    vector<Shape*> shapes;

    shapes.push_back(new Circle());
    shapes.push_back(new Rectangle());
    shapes.push_back(new Circle());

    for (Shape* s : shapes) {
        identifyAndDraw(s);
        cout << "\n";
    }

    for (Shape* s : shapes) {
        delete s;
    }

    return 0;
}