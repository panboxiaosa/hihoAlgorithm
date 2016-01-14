#include <iostream>
#include <vector>


using namespace std;

typedef pair<int,int> ward;

int pack(vector<ward> use,int asset){
    int* result = new int[asset + 1];
    for(int i = 0; i <= asset; i++)
        result[i] = 0;
    int ans;
    for(int i = 0; i < use.size(); i++)
        for(int j = asset; j >= use[i].first; j--)
            result[j] = max(use[i].second + result[j - use[i].first], result[j]);

    ans = result[asset];
    delete[] result;
    return ans;
}

int main()
{
    int num;
    int total;
    cin>>num>>total;
    vector<ward> all;
    for(int i = 0; i < num; i++){
        int pay, value;
        cin>>pay>>value;
        all.push_back(ward(pay, value));
    }
    cout<<pack(all, total)<<endl;
    return 0;
}
