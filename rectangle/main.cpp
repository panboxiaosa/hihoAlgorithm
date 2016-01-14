#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> point;

typedef pair<point, point> line;

bool isParraller(line one, line two){
    pair<int, int> direct1 = pair<int,int>(one.first.first - one.second.first, one.first.second - one.second.second);
    pair<int, int> direct2 = pair<int, int>(two.first.first - two.second.first, two.first.second - two.second.second);
    if(direct1.first * direct2.second == direct1.second * direct2.first)
        return true;
    return false;
}

bool validNeighbor(line one, line two){
    if(one.first.first == two.first.first && one.first.second == two.first.second)
        return true;
    if(one.first.first == two.second.first && one.first.second == two.second.second)
        return true;
    if(one.second.first == two.first.first && one.second.second == two.first.second)
        return true;
    if(one.second.first == two.second.first && one.second.second == two.second.second)
        return true;
    return false;
}

bool validVertical(line one, line two){
    pair<int, int> direct1 = pair<int,int>(one.first.first - one.second.first, one.first.second - one.second.second);
    pair<int, int> direct2 = pair<int,int>(two.first.first - two.second.first, two.first.second - two.second.second);
    if(direct1.first * direct2.first + direct1.second * direct2.second == 0)
        return true;
    return false;
}


bool judge(int matrix[][4]){
    line lines[4];
    for(int i = 0; i < 4; i++){
        point one(matrix[i][0], matrix[i][1]);
        point two(matrix[i][2], matrix[i][3]);
        lines[i].first = one;
        lines[i].second = two;
    }
    vector<pair<int, int> > peers;
    for(int i = 0; i < 3; i++){
        for(int j = i + 1; j < 4; j++){
            if(peers.size() > 1)
                break;
            if(isParraller(lines[i], lines[j]))
                peers.push_back(pair<int, int>(i, j));
        }
    }

    if(peers.size() != 2)
        return false;

    if(!validVertical(lines[peers[0].first], lines[peers[1].first]))
        return false;

    if(!validNeighbor(lines[peers[0].first], lines[peers[1].first]))
        return false;
    if(!validNeighbor(lines[peers[0].first], lines[peers[1].second]))
        return false;

    if(!validNeighbor(lines[peers[0].second], lines[peers[1].first]))
        return false;
    if(!validNeighbor(lines[peers[0].second], lines[peers[1].second]))
        return false;

    return true;
}

int main()
{
    int num;
    cin>>num;

    for(int i = 0; i < num; i++){
        int matrix[4][4];
        for(int j = 0; j < 4; j++)
            for(int k = 0; k < 4; k++)
                cin>>matrix[j][k];
        bool result = judge(matrix);
        if(result)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
