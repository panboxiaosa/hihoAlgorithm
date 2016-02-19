#include <iostream>
#include <bitset>
#include <assert.h>

using namespace std;

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

template<typename T>
class Swapper{
private:
    TwoDArray<T> * buf;
    int current = 0;
public:
    Swapper(int len){
        buf = new TwoDArray<T>(2, len);
    }
    ~Swapper(){
        delete buf;
    }
    swap(){
        current = 1 - current;
    }
    getFront(){
        return buf[current];
    }
    getBack(){
        return buf[1 - current];
    }

};

int main()
{
    int n,m;
    cin>>n>>m;
    Swapper<int> buf(1000);
    for(int i = 0; i < m; i++){
        int* now = buf.getFront();
        int* back = buf.getBack();
        for(int j = 0; j < n; j++){

        }

        buf.swap();
    }
    return 0;
}
