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
    int findPos(T& obj) {
        for (int ii = 0; ii<this->size(); ii++){
            try{
                if ( (*this)[ii] == obj){
                    return ii;
                }
            }
            catch (int e){
                throw("Implement operator== overload");
            }
        }
        return -1;
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
            }
        }
        return false;
    }
    friend ostream& operator<<(ostream& op, const myVector& m){
        op<<"vector "<<m.size()<<std::endl;
        for (int ii = 0; ii<m.size(); ii++){
            op<<m[ii];
        }
        return op;
    }
    friend istream& operator>>(istream& op, myVector& m){
        string useless;
        int size;
        T var;
        op>>useless>>size;
        getline(op,useless);
        for(int ii = 0; ii<size; ii++){
            op>>var;
            m.push_back(var);
        }
        return op;
    }
};



#endif
