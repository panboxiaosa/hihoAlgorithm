#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool vanish(int* record, int* match){
    int test[3];
    test[0] = record[0];
    test[1] = record[1];
    test[2] = record[2];

    sort(test, test + 3);
    int dis1 = test[1] - test[0];
    int dis2 = test[2] - test[1];
    if(dis1 == match[0] && dis2 == match[1])
    return true;
    else
    return false;
}

int main(){
   int match[3];
   cin>>match[0]>>match[1]>>match[2];
   sort(match, match + 3);
   string str;
   cin>>str;
   if(match[0] + match[1] != match[2]){
       cout<<str.length()<<endl;
       return 0;
   }
   int record[3] = {0};
   int ans = 0;
   int nowlength = 0;
   for(int i = 0; i < str.length(); i++){
       if(str[i] == 'R')
       record[0]++;
       if(str[i] == 'B')
       record[1]++;
       if(str[i] == 'Y')
       record[2]++;
       nowlength++;
       if(nowlength > ans)
           ans = nowlength;
       if(vanish(record, match)){
           record[0] = record[1] = record[2] = 0;
           nowlength = 0;
       }
   }
   cout<<ans<<endl;
   return 0;
}
