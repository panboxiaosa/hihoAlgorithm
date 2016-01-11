#include <iostream>
#include <string>
#include <string.h>
#include "../util/array2D.hpp"

using namespace std;

const int mod_tar = 1000000007;
const int dig_num = 10;
long long dp[20][10][220];

int getSum(string str)
{
    int sum = 0;
    int hold = -1;
    for(int i = 0; i < str.length(); i++){
        hold *= -1;
        sum += hold * (str[i] - '0');
    }
}

int getCross(string target, int match){
    int len = target.length();
    for(int i = 0; i < len; i++){
        for(int j = 0; j <= target[i] - '0'; j++){
            for(k = -109; k < 109; k++){

            }
        }
    }

    return 0;
}


int main()
{
    string first;
    string second
    int match;
    cin>>first;
    cin>>second;
    cin>>match;
    cout<<getCross(first, second, match)<<endl;
    return 0;
}
