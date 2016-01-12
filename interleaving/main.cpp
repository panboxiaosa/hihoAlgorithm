#include <iostream>
#include <memory.h>
using namespace std;

long long mod = 1000000007;
int store[20];
int nowCal;
long long bitBase[20];
int offset = 200;

struct node {
    long long s,n;
};
node dp[20][400];


node dfs(int pos, int target, bool limit)
{
    node one;
    one.s = one.n = 0;
    if(pos < 0){
        if(target == offset)
            one.n = 1;
        return one;
    }
    if(!limit && dp[pos][target].n != -1)
        return dp[pos][target];
    int start = (pos == nowCal ? 1: 0);
    int finish = limit ? store[pos]: 9;
    int sgn = (nowCal - pos) % 2 ? -1: 1;

    for(int i = start;i <= finish; i++){
        node tmp = dfs(pos - 1, target - sgn*i, limit&& i == finish);
        if(tmp.n > 0){
            one.n += tmp.n;
            one.s += tmp.s;
            one.s %= mod;
            long long added = ((tmp.n %mod)*bitBase[pos] %mod * i)%mod;
            one.s += added;
            one.s %= mod;
        }
    }

    if(!limit)
        dp[pos][target] = one;

    return one;

}

long long cal(long long num,long long match){
    int index = 0;
    while(num > 0){
        store[index] = num % 10;
        num /= 10;
        index++;
    }
    long long ans = 0;
    for(nowCal = 0; nowCal < index; nowCal++){
        memset(dp, -1, sizeof(dp));
        ans += dfs(nowCal, match + offset, nowCal == index - 1).s;
        ans = (ans + mod) % mod;

    }
    return ans;
}

int main()
{
    bitBase[0] = 1;
    for(int i = 1 ;i < 19; i++){
        bitBase[i] = (bitBase[i - 1] * 10) % mod;
    }

    long long start;
    long long finish;
    long long match;
    cin>>start>>finish>>match;

    long long resus = cal(start, match);
    long long resuf = cal(finish, match);

    cout<< (resuf - resus + mod) % mod<<endl;
    return 0;
}
