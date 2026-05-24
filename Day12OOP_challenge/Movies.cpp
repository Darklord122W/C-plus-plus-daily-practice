#include "Movies.h"
#include <iostream>

Movies::Movies()
    :m_list{}{

}
bool Movies::add_movie(std::string name,std::string rating,int watched){
    for(Movie& m:m_list){
        if(m.get_name()==name){
            return false;
        }
    }
    m_list.push_back(Movie{name, rating, watched});
    return true;
}

void Movies::display(){
    if(m_list.empty()){
        std::cout<<"Sorry, no movies to display"<<std::endl;
    }
    else{
       for(Movie& m:m_list){
            std::cout<<m.name<<", "<<m.rating<<", "<<m.watched<<std::endl;
    }      
    }

}
bool Movies::increment_watched(std::string name){
    for(Movie& m:m_list){
        if(m.get_name()==name){
            m.watched+=1;
            return true;
        }
    }
    return false;
}
