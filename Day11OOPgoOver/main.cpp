#include "Circle.h"
#include <cassert>
#include <cmath>
#include <iostream>

int main() {
    // default constructor
    Circle empty;
    assert(empty.x == 0 && empty.y == 0 && empty.radius == 0.0);

    // parameterized constructor + getarea (uses M_PI now)
    Circle c1(0, 0, 5.0);
    assert(std::abs(c1.getarea() - M_PI * 25.0) < 1e-9);

    // translate
    c1.translate(2, 3);
    assert(c1.x == 2 && c1.y == 3);

    // copy constructor
    Circle c2(c1);
    assert(c2.x == 2 && c2.y == 3 && c2.radius == 5.0);

    // operator==
    Circle a(1, 2, 3.0);
    Circle b(1, 2, 3.0);
    Circle different(1, 2, 4.0);
    assert(a == b);
    assert(!(a == different));

    // intersect
    Circle nearC(4, 3, 5.0);
    Circle farC(100, 100, 1.0);
    assert(c1.intersect(nearC) == true);
    assert(c1.intersect(farC)  == false);

    // operator+ (returns radius sum, larger |x| and |y|)
    Circle sum = c1 + farC;
    assert(sum.radius == 6.0);
    assert(sum.x == 100 && sum.y == 100);

    // displayCircle (visual check)
    c1.displayCircle();
    std::cout << "\nAll tests passed\n";
}
