#include <cstring>
#include <cctype>
#include <iostream>
#include "Mystring.h"

// ---- given: constructors / destructor (same pattern as your Day13 work) ----

Mystring::Mystring()
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

Mystring::Mystring(const char *s)
    : str{nullptr} {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

Mystring::Mystring(const Mystring &source)
    : str{nullptr} {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

Mystring::Mystring(Mystring &&source) noexcept
    : str{source.str} {
    source.str = nullptr;
}

Mystring::~Mystring() {
    delete[] str;
}

void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

int Mystring::get_length() const {
    return std::strlen(str);
}

const char *Mystring::get_str() const {
    return str;
}

// ============================================================
// YOUR WORK STARTS HERE — implement level by level (see TODO.md)
// Uncomment the matching declaration in Mystring.h as you go.
// ============================================================

// Level 1 — equality
// hint: std::strcmp(a, b) returns 0 when equal
// bool Mystring::operator==(const Mystring &rhs) const { }
// bool Mystring::operator!=(const Mystring &rhs) const { }

// Level 2 — comparison
// hint: strcmp returns <0 when lhs comes first lexically
// bool Mystring::operator<(const Mystring &rhs) const { }
// bool Mystring::operator>(const Mystring &rhs) const { }

// Level 3 — unary minus: return a LOWERCASE COPY (don't modify *this)
// hint: copy first, then loop with std::tolower
// Mystring Mystring::operator-() const { }

// Level 4 — concatenation: return a NEW Mystring by value
// hint: new char[len(lhs)+len(rhs)+1], strcpy then strcat, wrap, delete[] buffer
// Mystring Mystring::operator+(const Mystring &rhs) const { }

// Level 5 — compound concatenation
// hint: this is ONE line once = and + exist:  *this = *this + rhs;
// Mystring &Mystring::operator+=(const Mystring &rhs) { }

// Level 6 — repeat
// Mystring Mystring::operator*(int n) const { }
// Mystring &Mystring::operator*=(int n) { }

// Level 7 — increment (uppercase in place)
// pre:  modify, then return *this
// post: Mystring temp{*this}; then ++(*this); then return temp;
// Mystring &Mystring::operator++() { }
// Mystring Mystring::operator++(int) { }

// Level 8 — stream insertion / extraction (NON-member friends)
// note: no Mystring:: prefix — these are free functions
// std::ostream &operator<<(std::ostream &os, const Mystring &rhs) { }
// std::istream &operator>>(std::istream &is, Mystring &rhs) { }

// Level 9 — copy and move assignment
// copy: check self-assignment, delete[] old, allocate, strcpy, return *this
// move: check self-assignment, delete[] old, steal pointer, null rhs.str
// Mystring &Mystring::operator=(const Mystring &rhs) { }
// Mystring &Mystring::operator=(Mystring &&rhs) noexcept { }
