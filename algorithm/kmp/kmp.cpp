#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

void getNext(string patternStr, int* next)
{
    int len = patternStr.length();
    const char* pattern = patternStr.c_str();
    next[0] = 0;
    for(int i = 1; i < len; i++){
        int comp = next[i - 1];
        while(comp > 0 && pattern[i] != pattern[comp])
            comp = next[comp - 1];
        if(pattern[comp] == pattern[i])
            next[i] = comp + 1;
        else
            next[i] = 0;
    }

}

int findMatch(string pattern, string target, int* next)
{
    int total = 0;
    int len = pattern.length();
    const char* p = pattern.c_str();
    const char* tar = target.c_str();
    int index = 0;
    int pos = 0;
    int all_len = target.length();
    while(index < all_len){
        if(p[pos] == tar[index]){
            if(pos == len - 1)
                total++, pos = next[pos];
            else
                pos++;
            index++;

        }else{
            if(pos == 0)
                index++;
            else
                pos = next[pos - 1];
        }
    }

    return total;
}

int main()
{
    int tests;
    cin>>tests;
    for(int i = 0; i < tests; i++){
        string pattern;
        string target;
        cin>>pattern;
        cin>>target;
        int* next = new int[pattern.length()];
        getNext(pattern, next);
        int result = findMatch(pattern, target, next);
        delete[] next;
        cout<<result<<endl;
    }
    return 0;
}
