#include <iostream>
#include <queue>
#include "../util/array2D.hpp"

using namespace std;

typedef TwoDArray<int> TwoDInt;
typedef pair<pair<int,int>, int> state;


int solve(TwoDInt& store){
    queue<state> path;
    pair<int, int> dem = store.getDem();
    TwoDArray<int> best(dem.first, dem.second);
    best.setValue(-1);
    state ini;
    ini.first.first = 0;
    ini.first.second = 0;
    ini.second = store[0][0];
    best[0][0] = store[0][0];
    path.push(ini);
    while(true){
        state item = path.front();

        int current_row = item.first.first;
        int current_line = item.first.second;
        int current_value = item.second;
        if(current_row >= dem.first - 1)
            break;
        int result1 = current_value + store[current_row + 1][current_line];
        if(best[current_row + 1][current_line] != -1){
            if(result1 > best[current_row + 1][current_line]){
                best[current_row + 1][current_line] = result1;
                path.back().second = result1;
            }

        }else{
            path.push(state(pair<int,int>(current_row+1, current_line), result1));
            best[current_row + 1][current_line] = result1;
        }

        int result2 = current_value + store[current_row + 1][current_line + 1];
        best[current_row + 1][current_line + 1] = result2;
        path.push(state(pair<int,int>(current_row + 1, current_line + 1), result2));

        path.pop();

    }
    int ans = 0;
    for(int i = 0; i < dem.second; i++){
        if(ans < best[dem.first - 1][i])
            ans = best[dem.first - 1][i];
    }
    return ans;
}

int main()
{
    int layer;
    cin>>layer;
    TwoDInt store(layer, layer);
    store.setValue(0);
    for(int i = 0; i < layer; i++){
        for(int j = 0; j <= i; j++)
            cin>>store[i][j];
    }
    cout<<solve(store)<<endl;
    return 0;
}
