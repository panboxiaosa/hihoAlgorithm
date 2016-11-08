#include <iostream>
#include <vector>
#include <assert.h>
#include "../util/array2D.hpp"
#define INFINITE 999999

using namespace std;

struct edge{
    int one;
    int two;
    int len;
};

void floyd(TwoDArray<int>& store){
    assert(store.m == store.n);
    int** pointer = store.array_pointer;
    int d = store.m;
    for(int k = 0; k < d; k++)
        for(int i = 0; i < d; i++)
            for(int j = 0; j < d; j++)
                if(pointer[i][k] + pointer[k][j] < pointer[i][j])
                    pointer[i][j] = pointer[i][k] + pointer[k][j];
}

int main()
{
    int edges;
    int nodes;
    cin>>nodes;
    cin>>edges;
    vector<edge> all;
    for(int i = 0; i < edges; i++){
        struct edge one;
        cin>>one.one;
        cin>>one.two;
        one.one--;
        one.two--;
        cin>>one.len;
        all.push_back(one);
    }
    TwoDArray<int> matrix(nodes, nodes);
    for(int i = 0; i < nodes; i++){
        for(int j = 0; j < nodes; j++){
            if(i == j)
                matrix.array_pointer[i][j] = 0;
            else
                matrix.array_pointer[i][j] = INFINITE;
        }
    }

    for(int i = 0; i < edges; i++){
        int one = all.at(i).one;
        int two = all.at(i).two;
        int len = all.at(i).len;
        if(matrix.array_pointer[one][two] > len){
            matrix.array_pointer[one][two] = len;
            matrix.array_pointer[two][one] = len;
        }

    }
    floyd(matrix);
    matrix.print();
    return 0;
}
