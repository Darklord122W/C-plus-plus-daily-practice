#include <iostream>
#include <cmath>
#include "Circle.h"

using namespace std;

// Default constructor
Circle::Circle() : x{0}, y{0}, radius{5} {}

// Parameterized constructor
Circle::Circle(int a, int b, double r) : x{a}, y{b} {
    radius = (r > 0.0) ? r : 5;
}

// Copy constructor
Circle::Circle(const Circle &c) : x{c.x}, y{c.y}, radius{c.radius} {}

// Getters
int Circle::getX() const { return x; }
int Circle::getY() const { return y; }
double Circle::getRadius() const { return radius; }

// Setters
void Circle::setX(int a) { x = a; }
void Circle::setY(int b) { y = b; }
void Circle::setRadius(double r) {
    if (r > 0.0)
        radius = r;
    else
        cout << "Invalid radius: must be greater than 0." << endl;
}

void Circle::translate(int horizShift, int vertShift) {
    x += horizShift;
    y += vertShift;
}

double Circle::getArea() const {
    return 3.14159 * radius * radius;
}

void Circle::displayCircle() const {
    cout << "Radius: " << radius << " at point x = " << x << ", y = " << y << endl;
}

// Two circles intersect if the distance between centers <= sum of radii
bool Circle::intersect(Circle c) const {
    double dist = sqrt(pow(x - c.x, 2) + pow(y - c.y, 2));
    return dist <= (radius + c.radius);
}

bool Circle::operator==(Circle c) const {
    return (radius == c.radius && x == c.x && y == c.y);
}

// Friend: new circle with sum of radii, coordinates with greater absolute magnitude
Circle operator+(const Circle &c1, const Circle &c2) {
    double newRadius = c1.radius + c2.radius;
    int newX = (abs(c1.x) >= abs(c2.x)) ? c1.x : c2.x;
    int newY = (abs(c1.y) >= abs(c2.y)) ? c1.y : c2.y;
    return Circle(newX, newY, newRadius);
}
