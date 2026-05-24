#include "Movie.h"
#include <iostream>

Movie::Movie(std::string name,MovieRating rating,int watched)
    :name{name},rating{rating},watched{watched}{}
