#include <iostream>
#include <cstring>
#include "Mystring.h"

 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

Mystring operator-(const Mystring& rhs) {
    char *buff=new char[std::strlen(rhs.str)+1];
    std::strcpy(buff,rhs.str);
    for(size_t i=0;i<std::strlen(buff);i++){
        buff[i]=std::tolower(buff[i]);
    }
    Mystring temp{buff};
    delete [] buff;
    return temp;

} // make lowercase
    
bool operator==(const Mystring& lhs,const Mystring& rhs){
    if(std::strcmp(lhs.str,rhs.str)==0){
        return true;
    } 
    else{
        return false;
    }
}
bool operator!=(const Mystring& lhs, const Mystring& rhs){
    if(std::strcmp(lhs.str,rhs.str)!=0){
        return true;
    } 
    return false;
}
bool operator<(const Mystring& lhs, const Mystring& rhs){
    if(std::strlen(lhs.str)<std::strlen(rhs.str)){
        return true;
    } 
    return false;
}
bool operator>(const Mystring& lhs, const Mystring& rhs){
    if(std::strlen(lhs.str)>std::strlen(rhs.str)){
        return true;
    } 
    return false;
}
Mystring operator+(const Mystring& lhs, const Mystring& rhs){
    char *buff=new char[std::strlen(lhs.str)+std::strlen(rhs.str)+1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp{buff};
    delete [] buff;
    return temp;

} 

Mystring& operator+=(Mystring& lhs, const Mystring& rhs){
    char *buff=new char[std::strlen(lhs.str)+std::strlen(rhs.str)+1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    delete [] lhs.str; //free old str
    lhs.str=buff;
    return lhs;
}    

Mystring operator*(const Mystring& lhs, const int rhs){
    char *buff=new char[std::strlen(lhs.str)*rhs+1];
    std::strcpy(buff, lhs.str);
    for(int i=0;i<rhs-1;i++){
    std::strcat(buff,lhs.str);
    }
    Mystring temp{buff};
    delete [] buff;
    return temp;

} 

Mystring& operator*=(Mystring& lhs,int rhs){
    char *buff=new char[std::strlen(lhs.str)*rhs+1];
    buff[0] = '\0';               // start empty, not with strcpy
    for (int i = 0; i < rhs; i++) {
        std::strcat(buff, lhs.str);
    }
    delete [] lhs.str; //free old str
    lhs.str=buff;
    return lhs;
}    

Mystring & operator++(Mystring& rhs) {  // pre-increment
   // do what ever you want increment do to - maybe make all characters uppercase?
    char *buff=new char[std::strlen(rhs.str)+1];
    std::strcpy(buff,rhs.str);
    for(size_t i=0;i<std::strlen(buff);i++){
        buff[i]=std::toupper(buff[i]);
    }
    delete [] rhs.str;
    rhs.str=buff;
    return rhs;
}

Mystring operator++(Mystring& lhs,int){
   Mystring temp (lhs);       // make a copy
   ++lhs;                    // call pre-increment - make sure you call pre-increment!
   return temp;                     // return the old value
}