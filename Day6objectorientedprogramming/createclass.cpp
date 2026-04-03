#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player{
    //attribute
    string name;
    int health;
    int xp;
    //methods
    void talk(string);
    bool is_dead();
} ;
class Account{
    string name{"account"};
    double balance{0.0};

    bool deposit(double);
    bool withdraw(double);
};
int main(){
    Player Grace;
    Player Janice;
    Player players[]{Grace,Janice};    
    vector<Player> player_vec{Grace};
    player_vec.push_back(Janice);



    return 0;
}