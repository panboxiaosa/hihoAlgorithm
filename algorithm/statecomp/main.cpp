#include <iostream>

#include <vector>
#include <memory.h>

using namespace std;

int n, m, q;

bool check(int target){
    if(m == q)
        return true;
    int total = 0;
    while(target > 0){
        if(target&1)
            total++;
        target>>=1;
    }
    if(total > q)
        return false;
    else
        return true;
}

int main()
{
    int buf[2][1024];

    vector<int> trash;
    cin>>n>>m>>q;
    for(int i = 0;i < n; i++){
        int temp;
        cin>>temp;
        trash.push_back(temp);
    }
    int limit = 1;
    for(int i = 0; i < m; i++){
        limit<<=1;

    }

    int rolling = 1;
    int use;
    memset(buf, 0, sizeof(buf));
    for(int i = 0; i < n; i++){
        rolling *= -1;
        use = (1 + rolling) / 2;
        for(int j = 0; j < limit; j++)
            buf[use][j] = 0;

        for(int j = 0; j < limit; j++){
            if(check(j)){
                int last = j >> 1;
                if(j & 1){
                    buf[use][j] = max(buf[1 - use][last] + trash[i], buf[1 - use][last | (limit>>1)] + trash[i] );
                }else{
                    buf[use][j] = buf[1 - use][last];
                    last |= limit>>1;
                    if(check(last))
                        if(buf[1 - use][last] > buf[use][j])
                            buf[use][j] = buf[1 - use][last];
                }

            }
        }

    }
    int result = 0;
    for(int i = 0; i < limit; i++){
        if(result < buf[use][i])
            result = buf[use][i];
    }
    cout<<result<<endl;
    return 0;
}
