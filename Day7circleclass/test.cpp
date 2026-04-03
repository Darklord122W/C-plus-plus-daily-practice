#include <iostream>
#include "Circle.h"

using namespace std;

int main() {
    // Default constructor
    Circle c1;
    cout << "Default circle: ";
    c1.displayCircle();

    // Parameterized constructor
    Circle c2(3, 4, 7.5);
    cout << "Circle c2: ";
    c2.displayCircle();

    // Copy constructor
    Circle c3(c2);
    cout << "Copy of c2 (c3): ";
    c3.displayCircle();

    // Getters
    cout << "c1 radius: " << c1.getRadius() << ", x: " << c1.getX() << ", y: " << c1.getY() << endl;

    // Setters
    c1.setX(2);
    c1.setY(-3);
    c1.setRadius(4.0);
    cout << "c1 after setters: ";
    c1.displayCircle();

    // Invalid radius setter
    c1.setRadius(-1.0);

    // Translate
    c2.translate(2, -1);
    cout << "c2 after translate(2,-1): ";
    c2.displayCircle();

    // Area
    cout << "Area of c1: " << c1.getArea() << endl;

    // Intersect
    Circle c4(0, 0, 5);
    Circle c5(8, 0, 5);
    Circle c6(20, 0, 3);
    cout << "c4 and c5 intersect: " << (c4.intersect(c5) ? "true" : "false") << endl;
    cout << "c4 and c6 intersect: " << (c4.intersect(c6) ? "true" : "false") << endl;

    // operator==
    Circle c7(1, 2, 3.0);
    Circle c8(1, 2, 3.0);
    Circle c9(0, 0, 5.0);
    cout << "c7 == c8: " << (c7 == c8 ? "true" : "false") << endl;
    cout << "c7 == c9: " << (c7 == c9 ? "true" : "false") << endl;

    // operator+
    Circle c10(3, -5, 4.0);
    Circle c11(-1, 2, 6.0);
    Circle c12 = c10 + c11;
    cout << "c10 + c11: ";
    c12.displayCircle();

    return 0;
}