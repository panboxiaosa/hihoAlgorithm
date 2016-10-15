#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include "../util/tinyarray.hpp"

using namespace std;

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
