#include "myVector.hpp"
#include <iostream>
#include <vector>
using namespace std;



int main(){
    myVector<double> vec;
    
    for (int ii = 0; ii<10; ii++)
        vec.push_back(ii*10);
    double foudenr  = 40;
    double* var = vec.find(foudenr);
    cout<<*var;

}