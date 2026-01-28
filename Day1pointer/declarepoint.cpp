#include<iostream>
using namespace std;

int main(){
    int *p;
    cout<<"value of p is: "<<p<<endl;
    cout<<"Address of p is: "<< &p<<endl;
    cout<<"size of p is: "<<sizeof p<<endl;
    p=nullptr;
    cout<< "Value of p is: "<<p<<endl;
    return 0;
}