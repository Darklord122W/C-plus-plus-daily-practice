#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
    int x;
    int y;
    double radius;

public:
    // Default constructor: radius 5 at (0,0)
    Circle();

    // Parameterized constructor
    Circle(int a, int b, double r);

    // Copy constructor
    Circle(const Circle &c);

    // Getters
    int getX() const;
    int getY() const;
    double getRadius() const;

    // Setters (radius must be > 0)
    void setX(int a);
    void setY(int b);
    void setRadius(double r);

    void translate(int horizShift, int vertShift);
    double getArea() const;
    void displayCircle() const;
    bool intersect(Circle c) const;
    bool operator==(Circle c) const;

    friend Circle operator+(const Circle &c1, const Circle &c2);
};

#endif