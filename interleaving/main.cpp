#include <iostream>
#include <string>
#include <string.h>
#include "../util/array2D.hpp"

using namespace std;

const int mod_tar = 1000000007;
const int dig_num = 10;

int getCross(string first, string second, int match){
    int len1 = first.length();
    int len2 = second.length();

    int* digits = new int[len1];
    for(int i = 0; i < len1; i++)
        digits[i] = first.at(i) - '0';



    TwoDArray smaller(len1, dig_num);
    delete[] digits;

    return 0;
}


int main()
{
    string first;
    string second;
    int match;
    cin>>first;
    cin>>second;
    cin>>match;
    cout<<getCross(first, second, match)<<endl;
    return 0;
}
