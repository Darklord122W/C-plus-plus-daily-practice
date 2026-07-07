#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class Mystring {
    // Level 8 — TODO: declare friend operator<< and operator>> here
    // friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    // friend std::istream &operator>>(std::istream &is, Mystring &rhs);

private:
    char *str;      // raw heap C-string — this is WHY =, copy and move matter

public:
    Mystring();                            // no-args: empty string ""
    Mystring(const char *s);               // from C-string
    Mystring(const Mystring &source);      // copy constructor (deep copy)
    Mystring(Mystring &&source) noexcept;  // move constructor (steal + null)
    ~Mystring();

    void display() const;
    int get_length() const;
    const char *get_str() const;

    // Level 9 — TODO: copy assignment and move assignment
    // Mystring &operator=(const Mystring &rhs);
    // Mystring &operator=(Mystring &&rhs) noexcept;

    // Level 1 — TODO: equality
    // bool operator==(const Mystring &rhs) const;
    // bool operator!=(const Mystring &rhs) const;

    // Level 2 — TODO: comparison
    // bool operator<(const Mystring &rhs) const;
    // bool operator>(const Mystring &rhs) const;

    // Level 3 — TODO: unary minus → lowercase copy
    // Mystring operator-() const;

    // Level 4 — TODO: concatenation
    // Mystring operator+(const Mystring &rhs) const;

    // Level 5 — TODO: compound concatenation (one-liner using = and +)
    // Mystring &operator+=(const Mystring &rhs);

    // Level 6 — TODO: repeat: s * 3 == "sss"
    // Mystring operator*(int n) const;
    // Mystring &operator*=(int n);

    // Level 7 — TODO: uppercase in place
    // Mystring &operator++();      // pre:  ++s  → uppercase, return *this
    // Mystring operator++(int);    // post: s++  → save old, uppercase, return old
};

#endif
