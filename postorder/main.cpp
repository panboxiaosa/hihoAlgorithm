#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> holder;

void pro(string pre, string mid){
    int total = pre.size();
    if(total == 0)
        return;
    char root = pre[0];
    int split = mid.find(root);

    int rightLen = total - split - 1;
    string leftMid = mid.substr(0, split);
    string rightMid = mid.substr(split + 1, rightLen);

    string leftPre = pre.substr(1, split);
    string rightPre = pre.substr(split + 1, rightLen);

    holder.push(root);
    pro(rightPre, rightMid);
    pro(leftPre, leftMid);

}

int main()
{
    string pre;
    string mid;
    cin>>pre>>mid;
    pro(pre, mid);
    while(!holder.empty()){
        cout<<holder.top();
        holder.pop();
    }
    cout<<endl;
    return 0;
}
