#include <iostream>
#include <bitset>
#include <vector>

#define MAX 101

using namespace std;

bitset<MAX> direct[MAX];
bitset<MAX> sub[MAX];
vector<int> seq;
int index;
int total;

bool result;

void pre(int from, int now){

    sub[now][now] = 1;
    for(int i = 0; i < total; i++){
        if(direct[now][i])
        {
            if(i == from)
                continue;
            pre(now, i);
            sub[now] |= sub[i];
        }
    }
}

void dfs(int now, int from){

    if(now == seq[index])
        index++;
    if(index == seq.size()){
        result = true;
        return;
    }
    while(index < seq.size()){
        int temp = index;
        int target = seq[index];
        for(int i = 0; i < total; i++){
            if(direct[now][i] && from != i){
                if(sub[i][target]){
                    direct[now][i] = direct[i][now] = 0;
                    dfs(i, now);
                    break;
                }
            }
        }
        if(temp == index)
            break;
    }

}


int main()
{
    int c;
    cin>>c;
    for(int i = 0;i < c; i++){
        result = false;
        index = 0;
        cin>>total;
        for(int j = 0; j < MAX; j++){
            direct[j].reset();
            sub[j].reset();
        }

        for(int j = 1; j < total; j++){
            int first;
            int second;
            cin>>first>>second;
            first--;
            second--;
            direct[first][second] = direct[second][first] = 1;
        }
        pre(-1, 0);
        int m;
        cin>>m;
        seq.clear();
        for(int j = 0; j < m; j++){
            int temp;
            cin>>temp;
            seq.push_back(temp - 1);
        }
        dfs(0, -1);
        if(result)
        cout<<"YES"<<endl;
            else
        cout<<"NO"<<endl;
    }


    return 0;
}
