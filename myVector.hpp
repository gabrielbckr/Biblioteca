#ifndef _PUBLIC_MYVECTOR_
#define _PUBLIC_MYVECTOR_

#include <vector>
#include <iostream>

template<class T>  class myVector : public std::vector<T>{
public:
    myVector<T>():std::vector<T>(){}    
    T* find(T& obj){
        for (int ii = 0; ii<this->size(); ii++){
            try{
                if ( (*this)[ii] == obj){ 
                    return &(*this)[ii];
                }
            }
            catch (int e){
                throw("Implement operator== overloading");
            }
        }
        return NULL;
    }
    bool has(T& obj){
        for (int ii = 0; ii<this->size(); ii++){
            try{
                if ( (*this)[ii] == obj){ 
                    return true;
                }
            }
            catch (int e){
                throw("Implement operator== overloading");
                throw;
            }
        }
        return false;
    }
};

#endif