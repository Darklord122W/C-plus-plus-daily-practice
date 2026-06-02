#ifndef MOVIES_H
#define MOVIES_H
#include <string>
#include <iostream>
#include <vector>
#include "Movie.h"

class Movies{
    private:
        std::vector<Movie> *m_list;
    public:
        bool add_movie(std::string name,std::string rating,int watched);
        void display(void);
        bool increment_watched(std::string name);
        Movies();
        Movies(const Movies &source); // copy constructor
        Movies(Movies &&source); //move constructor
        ~Movies();



};

#endif