#ifndef ARRAY_2D
#define ARRAY_2D
#include <iostream>
#include <assert.h>

template<class T>
class TwoDArray{
private:
    T** array_pointer;
    int m;
    int n;
public:
    std::pair<int, int> getDem(){
        return std::pair<int, int>(m, n);
    }
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
        assert(array_pointer);
        for(int i = 0; i < m; i++)
            delete[] array_pointer[i];
        delete[] array_pointer;
        array_pointer = 0;

    }

    TwoDArray(const TwoDArray& value){
        this->m = value.m;
        this->n = value.n;
        this->array_pointer = new T*[m];
        for(int i = 0; i < m; i++)
            array_pointer[i] = new T[n];
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                this->array_pointer[i][j] = value.array_pointer[i][j];
    }


    T* operator[](int i){
        return array_pointer[i];
    }

    void setValue(const T& value){
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j++)
                array_pointer[i][j] = value;
    }
};

#endif
