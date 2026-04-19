#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H
#include "Shape.h"

class Quadrilateral : public Shape {
protected:
    double length;
    double height;
public:
    Quadrilateral(double l, double h);
    // We don't implement area() or display() here, so this class remains abstract
};

#endif