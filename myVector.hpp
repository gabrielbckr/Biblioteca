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
                throw("Implement operator== overload");
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
                throw("Implement operator== overload");
                throw;
            }
        }
        return false;
    }
    friend ostream& operator<<(ostream& op, myVector& m){
        op<<"vector "<<m.size()<<std::endl;
        for (int ii = 0; ii<m.size(); ii++){
            op<<m[ii];
        }
        return op;
    }
    friend istream& operator>>(istream& op, myVector& m){
        string useles;
        int size;
        T var;
        op>>useles>>size;
        getline(op,useles);
        for(int ii = 0; ii<size; ii++){
            op>>var;
            m.push_back(var);
        }
        return op;
    }
};



#endif