#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<string> a {"Tom","Grace","Dust"};
    for (auto &str:a){
        str="fat";
    }
    for(auto str:a)
        cout<<str<<endl;
}