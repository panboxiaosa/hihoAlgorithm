#pragma once
#include <iostream>
#define LIM_SIZE 512

template<typename T>
class Tinyarray
{
public:

    Tinyarray()
    {
        head = tail = 0;
    }

    void offer(T& item)
    {
        data[tail] = item;
        tail++;
    }

    void drop()
    {
        head++;
    }

    int size()
    {
        return tail - head;
    }

    void reset()
    {
        head = tail = 0;
    }

    void print()
    {
        for (int i = head; i < tail; i++)
            std::cout << data[i]<<std::endl;

        std::cout<<std::endl;
    }

    T& operator[](int index)
    {
        return data[index + head];
    }

    int head;
    int tail;
    T data[LIM_SIZE];
};
