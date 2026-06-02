#include "Movies.h"
#include <iostream>

Movies::Movies(){
    m_list=new std::vector<Movie>;
}
Movies::Movies(const Movies &source){
    m_list=new std::vector<Movie>;
    *m_list=*source.m_list;
	std::cout<<"Copy constructor -deep"<<std::endl;
}
// Movies::Movies(Movies &&source){
//     *m_list=*source.m_list;
//     source.m_list=nullptr;
//     std::cout<<"move constructor used"<<std::endl;
// }
Movies::Movies(Movies &&source) : m_list(source.m_list) {
    source.m_list = nullptr;
    std::cout<<"move constructor used"<<std::endl;
}
bool Movies::add_movie(std::string name,std::string rating,int watched){
    for(Movie& m:*m_list){ //taking each element by reference instead of copying it.
        if(m.get_name()==name){
            return false;
        }
    }
    m_list->push_back(Movie{name, rating, watched});
    // (*m_list).push_back(Movie{name, rating, watched});
    return true;
}

void Movies::display(){
    if(m_list->empty()){
        std::cout<<"Sorry, no movies to display"<<std::endl;
    }
    else{
       for(Movie& m:*m_list){
            std::cout<<m.name<<", "<<m.rating<<", "<<m.watched<<std::endl;
    }      
    }

}
bool Movies::increment_watched(std::string name){
    for(Movie& m:*m_list){
        if(m.get_name()==name){
            m.watched+=1;
            return true;
        }
    }
    return false;
}
Movies::~Movies(){
	if(m_list!=nullptr){
        std::cout<<"Destructor freeing "<<m_list->size()<<" movies"<<std::endl;
	}else{
        std::cout<<"Destructor freeing nullptr"<<std::endl;
	}
	delete m_list;
}