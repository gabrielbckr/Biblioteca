#include "myVector.hpp"
#include <iostream>
#include <vector>
using namespace std;

class gato{
    string name;
public:
    gato(string n): name(n){};
    gato(gato& g): name(g.name){};
    bool operator==(gato& g){
        return this->name==g.name;
    }
    friend  ostream operator<<(ostream& o, gato& g){
        o<<g.name;
    }
    string nome(){
        return this->name;
    }
};

int main(){
    myVector<gato> vec;
    vec.push_back(gato("chato"));
    vec.push_back(gato("aroldo"));
    gato foudenr("aroldo");
    gato* var = vec.find(foudenr);
    cout<<var->nome();

}