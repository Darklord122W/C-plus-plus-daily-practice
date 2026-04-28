#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
    int x;
    int y;
    double radius;
    Circle();
    Circle(int a, int b,double r);
    Circle(const Circle &source);
    void translate(int horizShift, int vertShift);
    double getarea(void);
    void displayCircle(void);
    bool intersect(Circle C);

};



#endif




