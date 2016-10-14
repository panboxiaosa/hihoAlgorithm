#include <iostream>
#include "../util/tinyarray.hpp"

using namespace std;

char matrix[200][200];

char temp[200][200];

char target[3][3];

void rotate(int w, int h){
    for(int i = 0; i < 200; i++)
        for(int j = 0; j < 200; j++)
            temp[i][j] = matrix[199 - j][i];

    for(int i = 0; i < 200; i++)
        for(int j = 0; j < 200; j++)
            matrix[i][j] = 0;

    for(int i = 0; i < w; i++)
        for(int j = 0; j < h; j++)
            matrix[i][j] = temp[i][j + 200 - h];
}


int main(){

    Tinyarray<int> item;
    int num1 = 0;
    int num2 = 2;
    item.offer(num1);
    item.print();
    item.offer(num2);
    item.print();
    item.drop();
    item.print();
    cout <<item[0]<<endl;
    cout <<"==="<<endl;
    item.reset();
    item.print();
    return 0;
}
