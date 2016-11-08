#include <iostream>
#include <vector>
#include <memory.h>

using namespace std;

typedef pair<int, int> edge;

edge con[100000];

int first[100000];
int second[100000];

int result = 0;

vector<int> near[100000];

int post(int pre, int now){
    for(int i = 0; i < near[now].size(); i++){
        int target = near[now][i];
        if(target == pre)
            continue;
        int temp = post(now, target);

        if(temp > first[now]){
            second[now] = first[now];
            first[now] = temp;
        }else if(temp > second[now]){
            second[now] = temp;
        }

    }
    result = max(result, first[now] + second[now]);
    return first[now] + 1;
}

int main()
{

    memset(first, 0, sizeof(first));
    memset(second, 0, sizeof(second));
    int num;
    cin>>num;
    for(int i = 0; i < num - 1; i++){
        int a, b;
        cin>>a>>b;
        a--;
        b--;
        con[i].first = a;
        con[i].second = b;
        near[a].push_back(b);
        near[b].push_back(a);
    }

    post(-1, 0);

    cout<<result<<endl;
    return 0;
}
