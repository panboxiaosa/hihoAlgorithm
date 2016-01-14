#include <iostream>
#include <string>
#include <list>

using namespace std;


void testInsert(char letter, int index, string origin, list<char>& target){
    for(int i = 0; i <= origin.length(); i++){
        if(i == index){
            target.push_back(letter);
        }else{
            target.push_back(origin[i - (i > index? 1 : 0)]);
        }
    }
}

int cal(list<char> use){
    int ans = 0;
    while(true){
        int inc = 0;
        bool dealing = false;
        char last = 'D';
        list<char>::iterator it;
        for(it = use.begin(); it != use.end();){
            if(last == *it){
                dealing = true;
                it = use.erase(it);
                inc++;
                if(it == use.end()){
                    use.pop_back();
                    it = use.end();
                    inc++;
                }
            }else{
                if(dealing == true){
                    it--;
                    it = use.erase(it);
                    inc++;
                    dealing = false;
                }
                last = (*it);
                it++;
            }
        }

        if(inc == 0)
            break;
        else
            ans += inc;
    }
    return ans;
}

int earase(string str){
    int ans = 0;
    for(int i = 0 ; i <= str.length(); i++){
        for(int j = 0; j < 3; j++){
            list<char> use;
            testInsert('A' + j, i, str, use);
            int result = cal(use);
            if(result > ans)
                ans = result;
        }
    }


    return ans;
}

int main()
{
    int tests;
    cin>>tests;
    for(int i = 0; i < tests; i++){
        string str;
        cin>>str;
        int result = earase(str);
        cout<<result<<endl;
    }
    return 0;
}
