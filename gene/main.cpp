#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory.h>

using namespace std;

int main()
{
    int num;
    cin>>num;
    string str;
    int need;

    for(int i = 0 ;i < num; i++){
        int result = 0;
        cin>>str>>need;
        int len = str.size();
        if(len == need){
            cout<<0<<endl;
            continue;
        }
        int index = 0;
        bool used[1000];
        memset(used, 0, sizeof(used));
        int dis = len - need;
        vector<int> group[1000];
        map<int, int> belong;
        for(int i = 0; i < need; i++){
            int fellow = i + dis;
            int should;
            if(!used[i]){
                group[index].push_back(i);
                belong[i] = index;
                used[i] = true;
                should = index;
                index++;
            }else{
                should = belong[i];
            }
            group[should].push_back(fellow);
            belong[fellow] = should;
            used[fellow] = true;
        }

        for(int i = 0; i < index; i++){
            int sum[4];
            memset(sum, 0, sizeof(sum));
            for(int j = 0; j < group[i].size(); j++){
                if(str[group[i][j]] == 'A')
                    sum[0]++;
                else if(str[group[i][j]] == 'T')
                    sum[1]++;
                else if(str[group[i][j]] == 'C')
                    sum[2]++;
                else if(str[group[i][j]] == 'G')
                    sum[3]++;
            }

            result += group[i].size() - max(sum[0], max(sum[1], max(sum[2], sum[3])));
        }
        cout<<result<<endl;
    }
    return 0;
}
