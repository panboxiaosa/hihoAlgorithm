#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct seg{
	int l, r, n;
	seg(int x, int y, int z) :l(x), r(y), n(z){}
	bool operator<(const seg& another) const{
		return l < another.l;
	}
};

bool alloc(vector<seg> data, int limit){

    if(data.size() == 0)
        return true;
	int pos = 0;
	int* loca = new int[data.size()];
	for (int i = 0; i < data.size(); i++){
		loca[i] = (data[i].l + data[i].r) / 2;
	}
	int rest = limit;
	for(int i = 0; i < data.size(); i++){
        while(data[i].n > 0){
            if(pos == data.size()){
                delete loca;
                return false;
            }
            while(loca[pos] < data[i].l){
                pos++;
                rest = limit;
            }
            if(rest > data[i].n){
                rest -= data[i].n;
                data[i].n = 0;
            }else{
                data[i].n -= rest;
                pos++;
                rest = limit;
            }
            if(data[i].r < loca[pos] && data[i].n != 0){
                delete loca;
                return false;
            }

        }
	}

	delete loca;
	return true;
}

int main(){

	int N; cin >> N;
	for (int i = 0; i<N; i++){
		int point, dis;
		cin >> point >> dis;
		vector<seg> data;
		int maxPos = 0;
		long long minTemp = 0;
		for (int j = 0; j < point; j++){
			int a, b;
			cin >> a >> b;
			maxPos = max(maxPos, b);
			minTemp += b;
			data.push_back(seg(a - dis, a + dis, b));
		}
		int minPos = (minTemp + point - 1) / point;
		sort(data.begin(), data.end());
		while (maxPos != minPos){
			int test = (maxPos + minPos) / 2;
			if (alloc(data, test))
				maxPos = test;
			else
				minPos = test + 1;
		}
		cout << maxPos << endl;
	}
	return 0;
}
