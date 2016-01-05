#include <iostream>

using namespace std;


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
