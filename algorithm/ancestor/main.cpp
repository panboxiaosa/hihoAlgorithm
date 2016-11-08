#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{

    map<string, string> father;
    int relation;
    cin>>relation;
    for(int i = 0; i < relation; i++){
        string son;
        string fa;
        cin>>fa>>son;
        father[son] = fa;
    }
    cin>>relation;
    for(int i = 0; i < relation; i++){
        string first;
        string second;
        vector<string> firstLine;
        vector<string> secondLine;
        cin>>first>>second;
        firstLine.push_back(first);
        while(father.find(first) != father.end()){
            first = father[first];
            firstLine.push_back(first);
        }
        secondLine.push_back(second);
        while(father.find(second) != father.end()){
            second = father[second];
            secondLine.push_back(second);
        }
        bool found = false;
        for(int m = 0; m < firstLine.size() && !found; m++){
            for(int n = 0; n < secondLine.size() && !found; n++){
                if(firstLine[m] == secondLine[n]){
                    found = true;
                    cout<<firstLine[m]<<endl;
                    break;
                }
            }
        }
        if(!found)
            cout<<-1<<endl;
    }
    return 0;
}
