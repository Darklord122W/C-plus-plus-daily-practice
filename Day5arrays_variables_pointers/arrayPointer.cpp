#include <iostream>
using namespace std;


int main(){

    int NUMBER_ELEMENTS{0};

    cout << "Enter array size: ";
    cin >> NUMBER_ELEMENTS;

    int *array1 = new int[NUMBER_ELEMENTS];  // allocate on heap

    for (int i = 0; i < NUMBER_ELEMENTS; i++) {
        *(array1+i)=i;
    }
    // // Print
    cout<<"array1: ";
    for (int i = 0; i < NUMBER_ELEMENTS; i++) {
        cout << array1[i] << " ";
    }
    cout<<endl;

    int odd_number=(NUMBER_ELEMENTS)/2;
    int *array2 = new int[odd_number];  // allocate on heap

    for(int i=0;i<odd_number;i++){
        *(array2+i)=*(array1+1+2*i);
    }
    cout<<"array2: ";
    for (int i = 0; i < odd_number; i++) {
        cout << array2[i] << " ";
    }
    cout<<endl;
    delete[] array1;
    delete[] array2;
    return 0;
}