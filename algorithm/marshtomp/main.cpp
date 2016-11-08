#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string str;
    string temp = "marshtomp";
    while(getline(cin, str)){
        string result;
        int index = 0;
        int pos = 0;
        for(int i = 0; i < str.size(); i++){

            if(str[i] == temp[pos] || abs(str[i] - temp[pos]) == 32){
                pos++;
            }else{
                pos = 0;
            }
            result += str[i];
            if(pos == 9){
                result = result.substr(0, result.size() - 9);
                result += "fjxmlhx";
                pos = 0;
            }
            index++;
        }
        cout<<result<<endl;
    }
    return 0;
}
