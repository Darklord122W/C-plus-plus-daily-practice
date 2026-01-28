#include<iostream>
using namespace std;

int main(){
    double inputFahrenheit;
    cout<<"please input a temperature in Fahrenheit:\n";
    cin>>inputFahrenheit;
    double Tincelsius=(5.0/9.0)*(inputFahrenheit-32.0);
    cout<< "Temperature in celsius is: "<<Tincelsius<<endl;

}