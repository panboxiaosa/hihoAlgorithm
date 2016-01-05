#include <iostream>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

char pattern[10001];
int next_array[10001];
char target[1000001];
int len;

void GetNext()
{
    int i=0;
    int j=-1;
    next_array[i]=j;
    while(i<len)
    {
        if(j==-1||pattern[i]==pattern[j])
        {
            i++;
            j++;
            if(i==len||pattern[i]!=pattern[j])//不允许出现P[i]==P[next[i]]
                next_array[i]=j;
            else
                next_array[i]=next_array[j];
        }
        else
        {
            j=next_array[j];
        }
    }

}

void getnext_array()
{
    next_array[0] = 0;
    for(int i = 1; i < len; i++){
        int pre = next_array[i - 1];
        while(pattern[pre] != pattern[i] && pre > 0)
            pre = next_array[pre - 1];
        if(pattern[pre] == pattern[i])
            next_array[i] = pre + 1;
    }
}

int findMatch()
{
    int pos = 0;
    int index = 0;
    int occur = 0;

    int itc = 0;
    int tar_len = strlen(target);
    while(index < tar_len){
        if(target[index] == pattern[pos]){
            if(pos == len - 1){
                occur++;
                pos = next_array[pos];
            }else{
                pos++;
                index++;
            }
        }else{
            if(pos == 0)
                index++;
            else
                pos = next_array[pos - 1];
        }
    }
    return occur;
}

int KMPSearch()
{
    int Plen = len;
    int Slen = strlen(target);

    unsigned int i=0;//在S串中的下标
    unsigned int j=0;//在P串中的下标
	unsigned int count=0;//匹配串出现的次数
    while(i<Slen)
    {
        if(j==-1||target[i]==pattern[j])
        {
            i++;
            j++;
        }
        else  if(j<Plen)
            j=next_array[j];
		if(j==Plen)
		{
			count++;
			j=next_array[Plen];
		}
    }
    return count;
}

int main()
{
    int tests;
    cin>>tests;
    for(int i = 0; i < tests; i++){
        cin>>pattern;
        cin>>target;
        len = strlen(pattern);
        getnext_array();
        int result = findMatch();
        cout<<result<<endl;
    }
    return 0;
}
