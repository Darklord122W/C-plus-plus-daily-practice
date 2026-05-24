#include "Movie.h"
#include <iostream>

Movie::Movie(std::string name,std::string rating,int watched)
    :name{name},rating{rating},watched{watched}{}
std::string Movie::get_name(void) const{
    return name;
}