#include <iostream>
using namespace std;
class A {
protected:
    int var;
public:
    A() { var = 0;} 
    void increment() { var++; }
    virtual void decrement() { var--; }
    virtual void print() {cout << "var = " << var << endl;}
};
class B : public A {
public:
    void increment() { var += 3; }
    virtual void decrement() { var -= 3; }
    B(){varB=10;var=10;}
    void print() {cout << "varB = " << varB << endl;}

protected:
    int varB;
};
A processObject(A obj) {
    cout<<"good accept class b object"<<endl;
    return obj;
};
int main() {
A a;
B b;
A * ptr;

// ptr = &a;
// ptr -> increment();
// ptr -> print();
// ptr -> decrement();
// ptr -> print();

// ptr=&b;
// ptr->print();
// a = b;
// a.print();
// ptr = &a;
// ptr -> print();
b.A::print();
// processObject(b);

}