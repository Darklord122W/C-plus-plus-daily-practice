#include "Movies.h"
#include <iostream>

Movies::Movies(){
    m_list{};    
}
bool Movies::add_movie(std::string name,MovieRating rating,int watched){
    m_list.push_back(Movie{name, rating, watched});
}
