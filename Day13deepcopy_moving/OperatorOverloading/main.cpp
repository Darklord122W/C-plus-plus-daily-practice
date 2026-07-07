/******************************************************************
 * Day 13.5 — Operator Overloading practice driver
 *
 * Uncomment one LEVEL block at a time as you implement it.
 * Expected output is in the comments — check yourself against it.
 *
 * build: g++ -std=c++17 -Wall main.cpp Mystring.cpp -o main && ./main
 * ***************************************************************/
#include <iostream>
#include "Mystring.h"

int main() {

    Mystring a{"hello"};
    Mystring b{"hello"};
    Mystring c{"WORLD"};

    a.display();        // hello : 5
    c.display();        // WORLD : 5

    // ---------- LEVEL 1: == and != ----------
    // std::cout << std::boolalpha;
    // std::cout << (a == b) << std::endl;   // true
    // std::cout << (a == c) << std::endl;   // false
    // std::cout << (a != c) << std::endl;   // true

    // ---------- LEVEL 2: < and > ----------
    // std::cout << (Mystring{"apple"} < Mystring{"banana"}) << std::endl; // true
    // std::cout << (Mystring{"zoo"}   > Mystring{"apple"})  << std::endl; // true

    // ---------- LEVEL 3: unary - (lowercase copy) ----------
    // Mystring lower = -c;
    // lower.display();    // world : 5
    // c.display();        // WORLD : 5   <-- original must be unchanged!

    // ---------- LEVEL 4: + (concatenation) ----------
    // Mystring greeting = a + Mystring{" "} + c;
    // greeting.display(); // hello WORLD : 11

    // ---------- LEVEL 5: += ----------
    // Mystring d{"C++"};
    // d += Mystring{" is fun"};
    // d.display();        // C++ is fun : 10

    // ---------- LEVEL 6: * and *= (repeat) ----------
    // Mystring ha{"ha"};
    // (ha * 3).display(); // hahaha : 6
    // ha *= 2;
    // ha.display();       // haha : 4

    // ---------- LEVEL 7: ++ pre and post ----------
    // Mystring s1{"shout"};
    // (++s1).display();   // SHOUT : 5   (pre: returns the new value)
    // Mystring s2{"quiet"};
    // Mystring old = s2++;
    // old.display();      // quiet : 5   (post: returns the OLD value)
    // s2.display();       // QUIET : 5

    // ---------- LEVEL 8: << and >> ----------
    // std::cout << a << " " << c << std::endl;  // hello WORLD
    // Mystring typed;
    // std::cout << "type a word: ";
    // std::cin >> typed;
    // std::cout << "you typed: " << typed << std::endl;

    // ---------- LEVEL 9: copy and move assignment ----------
    // Mystring x{"original"};
    // Mystring y;
    // y = x;                        // copy assignment
    // y.display();                  // original : 8
    // x.display();                  // original : 8   <-- source intact
    // y = Mystring{"temporary"};    // MOVE assignment (rhs is an rvalue)
    // y.display();                  // temporary : 9
    // x = x;                        // self-assignment: must not crash
    // x.display();                  // original : 8

    std::cout << "done" << std::endl;
    return 0;
}
