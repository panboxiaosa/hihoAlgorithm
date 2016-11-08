#include <iostream>
#include <memory.h>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    int need[512];
    int value[512];
    int result[2][100001];

    for(int i = 0; i < n; i++)
        cin>>need[i]>>value[i];

    memset(result, 0 ,sizeof(result));
    int turning = 1;
    int use;
    for(int i = 0; i < n; i++){
        turning *= -1;
        use = (turning + 1) /2;
        for(int j = 1; j <= m; j++)
            if(need[i] <= j)
                result[use][j] = max(result[1 - use][j], result[use][j - need[i]] + value[i]);
            else
                result[use][j] = result[1 - use][j];
    }
    cout<<result[use][m]<<endl;
    return 0;
}
