#ifndef ARRAY_2D
#define ARRAY_2D
#include <iostream>
template<class T>
class TwoDArray{
public:
    T** array_pointer;
    int m;
    int n;
    TwoDArray(int m, int n){
        this->m = m;
        this->n = n;
        array_pointer = new T*[m];
        for(int i = 0; i < m; i++)
            array_pointer[i] = new T[n];
    }

    void print(){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                std::cout<<array_pointer[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
    }

    ~TwoDArray(){
        for(int i = 0; i < m; i++)
            delete[] array_pointer[i];
        delete[] array_pointer;

    }
};

#endif
