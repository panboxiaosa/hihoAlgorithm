#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <map>

using namespace std;
string start_tag = "START";
string end_tag = "END";

struct ts{
    int hour;
    int minute;
    int second;
};

ts fromFormat(const string& str){
    ts item;
    item.hour = (str[0] - '0') * 10 + str[1] - '0';
    item.minute = (str[3] - '0') * 10 + str[4] - '0';
    item.second = (str[6] - '0') * 10 + str[7] - '0';
    return item;
}

string format(ts item){
    if(item.hour < 0 || item.minute < 0 || item.second < 0 || (item.second | item.minute | item.hour == 0 ))
        return "";
    string result = "";
    result += (char)(item.hour/10 + '0');
    result += (char)(item.hour%10 + '0');
    result += ":";
    result += (char)(item.minute/10 + '0');
    result += (char)(item.minute%10 + '0');
    result += ":";
    result += (char)(item.second/10 + '0');
    result += (char)(item.second%10 + '0');
    return result;
}

string time_minus(string bigger, string smaller){
    ts one = fromFormat(bigger);
    ts two = fromFormat(smaller);
    one.second -= two.second;
    if(one.second < 0){
        one.second += 60;
        one.minute -= 1;
    }
    one.minute -= two.minute;
    if(one.minute < 0){
        one.minute += 60;
        one.hour -= 1;
    }
    one.hour -= two.hour;
    return format(one);
}


int main()
{
    int num;
    stack<string> call;
    map<string, string> times;
    vector<string> names;
    cin>>num;
    string last = "00:00:00";
    for(int i = 0; i < num; i++){
        string name, time, tag;
        cin>>name>>time>>tag;
        string result = time_minus(time, last);
        if(result == ""){
            cout<<"Incorrect performance log"<<endl;
            return 0;
        }
        last = time;
        if(tag.compare(start_tag) == 0){
            names.push_back(name);
            times[name] = time;
            call.push(name);
        }else{
            if(call.top().compare(name)){
                break;
            }
            string resultTime = time_minus(time , times[name]);
            times[name] = resultTime;
            call.pop();
        }
    }
    if(!call.empty()){
        cout<<"Incorrect performance log"<<endl;
    }else{
        for(int i = 0;i < names.size(); i++)
            cout<<names[i]<<" "<<times[names[i]]<<endl;
    }
    return 0;
}
