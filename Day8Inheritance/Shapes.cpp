#include <iostream>
#include <cmath>
#include "Circle.h"
#include "Rectangle.h"
#include "Trapezoid.h"

// Circle
Circle::Circle(double r) : radius(r) {}
double Circle::area() const { return M_PI * radius * radius; }
void Circle::display() const {
    std::cout << "Circle: " << radius << " | Area = " << area() << std::endl;
}

// Quadrilateral
Quadrilateral::Quadrilateral(double l, double h) : length(l), height(h) {}

// Rectangle
Rectangle::Rectangle(double l, double h) : Quadrilateral(l, h) {}
double Rectangle::area() const { return length * height; }
void Rectangle::display() const {
    std::cout << "Rectangle: " << length << ", " << height << " | Area = " << area() << std::endl;
}

// Trapezoid
Trapezoid::Trapezoid(double l, double h, double s) : Quadrilateral(l, h), side(s) {}
double Trapezoid::area() const { return 0.5 * (length + side) * height; }
void Trapezoid::display() const {
    std::cout << "Trapezoid: " << length << ", " << height << ", " << side << " | Area = " << area() << std::endl;
}