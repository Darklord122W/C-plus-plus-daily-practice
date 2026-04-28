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
    return 3.14*radius*radius;
}
void Circle::displayCircle(void){
     cout<<"Radius: "<<radius<<" at point x= "<<x<<", "<<"y= "<<y;

}
bool Circle::intersect(Circle C){
    if(pow((x-C.x),2)+pow((y-C.y),2)>pow(radius+C.radius,2)){
        return false;
    }
    else{
        return true;
    }

}