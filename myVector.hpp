#include <vector>
#include <iostream>

template<class T>  class myVector : public std::vector<T>{
public:
    myVector<T>():std::vector<T>(){}    
    T* find(const T& obj){
        for (int ii = 0; ii<this->size()-1; ii++){
            try{
                if ( (*this)[ii] == obj){ 
                    return &(*this)[ii];
                }
            }
            catch (int e){
                std::cout << "An exception occurred. Exception Nr. " << e << '\n';
                throw;
            }
        }
        return NULL;
    }
};