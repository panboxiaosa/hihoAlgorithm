#ifndef SWAPPER
#define SWAPPER

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

#endif