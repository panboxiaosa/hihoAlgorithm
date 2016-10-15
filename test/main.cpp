#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;
bool valid[100001];

int main(){

    int a;
    cin>>a;

    for (int i = 0 ;i <= 100000; i++){
        int temp = i;
        int bin = 0;
        int ten = 0;
        while(temp > 0){
            bin += temp & 1;
            temp >>= 1;
        }
        temp = i;
        while(temp > 0){
            temp += temp % 10;
            temp /= 10;
        }
        if (bin == ten){
            valid[i] = true;
        }else{
            valid[i] = false;
        }
    }
    vector<int> result;
    result[0] = 1;
    for (int i = 1; i <= 100000; i++)
    {
        if (valid[i])
        {
            result[i] = result[i-1] + 1;
        }
    }
    int b;
    for (int i = 0; i < a; i++)
    {
        cin>> b;
        cout<<result[b]<<endl;
    }
    return 0;
}
