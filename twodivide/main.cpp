#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

bool dyed[10001];
bool man[10001];
vector<int> con[10000];
int already;

bool flag;

void dye(int from, int now){
    man[now] = !man[from];
    dyed[now] = true;
    already++;
    for(int i = 0; i < con[now].size(); i++){
        int next = con[now][i];
        if(next == from)
            continue;

        if(dyed[next] && man[now] == man[next]){
            flag = false;
            return;
        }
        if(!dyed[next]){
            dye(now, next);
        }
    }
}

int main()
{
    int group;
    cin>>group;
    for(int i = 0; i < group; i++){
        int m,n;
        cin>>m>>n;
        flag = true;

        memset(dyed, 0, sizeof(dyed));
        memset(man, 0, sizeof(man));
        already = 0;
        for(int j = 0; j < n; j++){
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            con[a].push_back(b);
            con[b].push_back(a);
        }
        dye(10000, 0);

        if(flag && already == m)
            cout<<"Correct"<<endl;
        else
            cout<<"Wrong"<<endl;
        for(int j = 0; j < m; j++)
            con[j].clear();
    }
    return 0;
}
