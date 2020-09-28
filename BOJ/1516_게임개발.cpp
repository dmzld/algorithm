#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <functional>
#include <cmath>
#include <string>

using namespace std;

int N;
vector<int> v[501];
int res[501] = { 0, };

int dfs(int n){
	if (v[n].size() == 1){
		res[n] = v[n][0];
		return v[n][0];
	}

	int time = dfs(v[n][1]);
	for (int i = 2; i < v[n].size(); i++){
		if (res[v[n][i]] == 0)
			time = max(time, dfs(v[n][i]));
		else
			time = max(time, res[v[n][i]]);
	}
	
	res[n] = time + v[n][0];
	return res[n];
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++){
		int tmp;
		cin >> tmp;
		while (tmp != -1){
			v[i].push_back(tmp);
			cin >> tmp;
		}
	}

	for (int i = 1; i <= N; i++)
		if (res[i] == 0)
			res[i] = dfs(i);

	for (int i = 1; i <= N; i++)
		cout << res[i] << "\n";

	return 0;
}
