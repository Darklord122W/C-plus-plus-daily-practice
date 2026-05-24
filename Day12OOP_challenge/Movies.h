#ifndef b
#define b
#include <string>
#include <iostream>
#include <vector>
#include "Movie.h"

class Movies{
    private:
        std::vector<Movie> m_list;
    public:
        bool add_movie(std::string name,MovieRating rating,int watched);
        void display(void);
        bool increment_watched(std::string name);





};

#endif