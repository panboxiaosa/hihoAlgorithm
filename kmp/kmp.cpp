#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

char pattern[10000];
int next_array[10000];
char target[1000000];
int len;

void getnext_array()
{
    next_array[0] = 0;
    for(int i = 1; i < len; i++){
        int pre = next_array[i - 1];
        while(pattern[pre] != pattern[i] && pre > 0)
            pre = next_array[pre - 1];
        if(pattern[pre] == pattern[i])
            next_array[i] = pre + 1;
    }
}

int findMatch()
{
    int pos = 0;
    int index = 0;
    int occur = 0;

    int itc = 0;
    int tar_len = strlen(target);
    while(index < tar_len){
        if(target[index] == pattern[pos]){
            if(pos == len - 1){
                occur++;
                pos = next_array[pos];
            }else{
                pos++;
                index++;
            }
        }else{
            if(pos == 0)
                index++;
            else
                pos = next_array[pos - 1];
        }
    }
    return occur;
}

int main()
{
    int tests;
    cin>>tests;
    vector<int> times;
    for(int i = 0; i < tests; i++){
        cin>>pattern;
        cin>>target;
        len = strlen(pattern);
        getnext_array();
        int result = findMatch();
        times.push_back(result);
    }

    for(int i = 0; i < tests; i++){
        cout<<times.at(i)<<endl;
    }
    return 0;
}
