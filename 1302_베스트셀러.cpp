#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N;
vector<pair<string, int>> v;
string str;
int ans = 0;

int main(){

	cin >> N;
	for (int i = 0; i < N; i++){
		int idx = -1;
		string tmp;
		cin >> tmp;
		for (int j = 0; j < v.size(); j++){
			if (v[j].first == tmp){
				idx = j;
				break;
			}
		}

		if (idx == -1)
			v.push_back({ tmp, 1 });
		else
			v[idx].second++;
	}

	for (int i = 0; i < v.size(); i++){
		if (v[i].second > ans || (v[i].second == ans && v[i].first < str)){
			ans = v[i].second;
			str = v[i].first;
		}
	}

	cout << str;

	return 0;
}
