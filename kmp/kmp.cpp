#include <iostream>
#include <vector>
#include <string>

using namespace std;

void getNext(const char* nStr, int* next, int len){
    next[0] = -1;
    for(int i = 1 ;i < len; i++){
        next[i] = -1;
        int k = next[i - 1];
        while(true){
            if(nStr[i] == nStr[k + 1]){
                next[i] = k + 1;
                break;
            }
            if(!k > -1)
                break;
            k = next[k];
        }
    }
}

int occurs(string target, const char* nStr, int* next, int len){
    int pos = 0;
    int cursor = 0;
    int total = 0;
    while(pos < target.length()){
        if(target.at(pos) == nStr[cursor] && cursor == len - 1){
            total ++;
            pos++;
            cursor = next[cursor] + 1;
        }
        else if(target.at(pos) == nStr[cursor]){
            pos++;
            cursor++;
        }else{
            pos++;
            if(cursor != 0)
                cursor = next[cursor - 1] + 1;
        }
    }
    return total;
}

int main()
{
    int tests;
    cin>>tests;
    vector<int> times;
    for(int i = 0; i < tests; i++){
        string one;
        cin>>one;
        int len = one.length();
        int* next = new int[len];
        string target;
        cin>>target;
        getNext(one.c_str(), next, len);
        times.push_back(occurs(target, one.c_str(), next, one.length()));
        delete next;
    }

    for(int i = 0; i < tests; i++){
        cout<<times.at(i)<<endl;
    }
    return 0;
}
