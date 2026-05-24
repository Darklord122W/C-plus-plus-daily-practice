#include "Circle.h"
#include <cmath>
#include <iostream>
using namespace std;

Circle::Circle(const Circle &source){
    x= int(source.x);
    y= int(source.y);
    radius=double(source.radius);
}
Circle::Circle(int a, int b,double r)
:x{a},y{b},radius{r}{
}
void Circle::translate(int horizShift, int vertShift){
    x+=horizShift;
    y+=vertShift;
}
double Circle::getarea(){
    return M_PI*radius*radius;
}
void Circle::displayCircle(void){
     cout<<"Radius: "<<radius<<" at point x= "<<x<<", "<<"y= "<<y;

}
bool Circle::intersect(const Circle &C) const{
    if(pow((x-C.x),2)+pow((y-C.y),2)>pow(radius+C.radius,2)){
        return false;
    }
    else{
        return true;
    }

}
Circle Circle::operator+(const Circle& other) const{
    int xbig{0};
    int ybig{0};
    if (abs(x)>abs(other.x)){
        xbig=x;
    }
    else{
        xbig=other.x;
    }
    if (abs(y)>abs(other.y)){
        ybig=y;
    }
    else{
        ybig=other.y;
    }
    return Circle(xbig,ybig,radius+other.radius);
}
Circle::Circle(){
    x=0;
    y=0;
    radius=0.0;
}
bool Circle::operator==(const Circle& other) const {
    const double EPSILON = 1e-9;
    return x == other.x                                // ints are safe
        && y == other.y                                // ints are safe
        && std::abs(radius - other.radius) < EPSILON;  // doubles need tolerance
}