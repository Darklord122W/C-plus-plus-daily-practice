#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    virtual ~Shape() {} // Virtual destructor is critical for polymorphism
    virtual double area() const = 0;      // Pure virtual function
    virtual void display() const = 0;     // Pure virtual function
};

#endif