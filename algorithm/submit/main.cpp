#include <iostream>
#include <vector>


using namespace std;

typedef pair<int, int> frag;

int solve(vector<frag>& fs, int chances){
    int ans = 0;
    vector<int> dis;
    for(int i = 0; i < fs.size() - 1; i++){
        dis.push_back(fs[i + 1].first - fs[i].second);
    }
    for(int i = 0; i < fs.size() - 1; i++){
        for(int j = i + 1; j < fs.size(); j++){
            int total = 0;
            for(int k = i; k < j; k++)
                total += dis[k];
            if(total <= chances){
                int result = fs[j].second - fs[i].first + chances - total;
                if(ans < result)
                    ans = result;
            }
        }
    }
    return ans < 100 ? ans: 100;
}

int main()
{
    int num;
    cin>>num;
    for(int i = 0 ;i < num; i++){
        int lost;
        int chances;
        cin>>lost;
        cin>>chances;
        vector<frag> use;
        use.push_back(frag(1, 1));
        int last = 1;
        for(int i = 0; i < lost; i++){
            int item;
            cin>>item;
            if(last == item)
                last++;
            else{
                use.push_back(frag(last, item));
                last = item + 1;
            }
        }
        use.push_back(frag(last, 101));
        cout<<solve(use, chances)<<endl;
    }
    return 0;
}
