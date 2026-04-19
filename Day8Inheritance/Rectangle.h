#ifndef RECTANGLE_H  // If RECTANGLE_H hasn't been defined yet...
#define RECTANGLE_H  // ...define it now.

#include "Quadrilateral.h"

class Rectangle : public Quadrilateral {
public:
    Rectangle(double l, double h);
    double area() const override;
    void display() const override;
};

#endif // End of guard