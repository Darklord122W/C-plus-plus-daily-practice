#ifndef a
#define a
#include <string>
#include <iostream>

enum class MovieRating {
    G,
    PG,
    PG_13, // Hyphens aren't allowed in variable names, so we use an underscore
    R
};

class Movie{
    private:
        std::string name;
        MovieRating rating;
        int watched;
        Movie(std::string name,MovieRating rating,int watched);
        friend class Movies;
        



};

#endif