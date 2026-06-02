#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include <iostream>


class Movie{
    private:
        std::string name;
        std::string rating;
        int watched;
        Movie(std::string name,std::string rating,int watched);
        friend class Movies;
        std::string get_name() const;



};

#endif