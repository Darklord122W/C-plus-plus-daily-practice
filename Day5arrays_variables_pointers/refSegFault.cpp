#include <iostream>

int& getDanglingRef() {
    int localVar = 42;
    return localVar;  // Returning reference to local variable
}                     //    localVar is destroyed here!

int main() {
    int& ref = getDanglingRef();  // ref now points to destroyed memory
    std::cout << ref << std::endl; // SEG FAULT — accessing dead stack memory
    return 0;
}
// int main() {
//     int* ptr = new int(100);
//     int& ref = *ptr;   // ref binds to heap memory

//     delete ptr;        // memory freed

//     std::cout << ref;  // SEG FAULT — ref still points to freed memory
//     return 0;
// }