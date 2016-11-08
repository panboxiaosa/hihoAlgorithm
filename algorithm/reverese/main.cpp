#include <iostream>
#include <string>
#include <string.h>

using namespace std;


int getReverse(const char* str){
    int len = strlen(str);
    char* extended = new char[2*len + 3];
    int* result = new int[2 * len + 3];
    extended[0] = '$';
    extended[2*len + 2] = '\0';
    extended[2*len + 1] = '#';
    for(int i = 0; i < len; i++){
        extended[2*i + 2] = str[i];
        extended[2*i + 1] = '#';
    }
    int reach = 0;
    int id = 0;
    int ans = 0;
    result[0] = 0;
    for(int i = 1; i < 2* len + 2; i++){
        int one;
        if(i < reach)
            one = min(result[2* id - i], reach - i + 1);
        else
            one = 1;
        while(extended[i + one] == extended[i - one])
            one++;

        if(i + one - 1 > reach){
            reach = i + one - 1;
            id = i;
        }
        result[i] = one;
        if(result[i] > ans)
            ans = result[i];

    }
    delete[] result;
    delete[] extended;
    return ans - 1;

}

int main()
{
    int tests;
    cin>>tests;
    for(int i = 0; i < tests; i++){
        string target;
        cin>>target;
        int result = getReverse(target.c_str());
        cout<<result<<endl;
    }
    return 0;
}
