#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <memory.h>
#include <list>


using namespace std;

int main()
{
    int num;
    cin>>num;
    for(int i = 0; i < num; i++){
        int group;
        cin>>group;
        set<int> containing;
        vector<list<int> > seq;
        for(int j = 0; j < group; j++){
            int a, b;
            cin>>a>>b;
            containing.insert(a);
            containing.insert(b);
            bool found = false;
            for(int i = 0; i < seq.size(); i++){
                if(seq[i].front() == a){
                    seq[i].push_front(b);
                    found = true;
                }
                if(seq[i].front() == b){
                    seq[i].push_front(a);
                    found = true;
                }
                if(seq[i].back() == a){
                    seq[i].push_back(b);
                    found = true;
                }
                if(seq[i].back() == b){
                    seq[i].push_back(b);
                    found = true;
                }
            }
            if(!found){
                list<int> added;
                added.push_back(a);
                added.push_back(b);
                seq.push_back(added);
            }
        }
        cout<<seq.size()<<containing.size()<<endl;

    }

    return 0;
}
