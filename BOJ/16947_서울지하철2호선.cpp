#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, ans[3001];
vector<int> e[3001]; // edge between two cities
int check[3001] = { 0, };


void checkCycle(int pv, int cv){
	while (pv != cv){
		for (int i = 0; i < e[pv].size(); i++){
			if (check[e[pv][i]] == check[pv] - 1){
				pv = e[pv][i];
				break;
			}
		}
		ans[pv] = 0;
	}
}

void findCycle(int pv, int cv){ // 이전 vertex, 현재 vertex
	for (int i = 0; i < e[cv].size(); i++){
		if (e[cv][i] == pv)
			continue;

		if (check[e[cv][i]] != 0 && check[e[cv][i]] < check[cv]){
			ans[e[cv][i]] = 0, ans[cv] = 0;
			checkCycle(cv, e[cv][i]);
			return;
		}
		
		if (check[e[cv][i] == 0){
			check[e[cv][i]] = check[cv] + 1;
			findCycle(cv, e[cv][i]);
			if (ans[e[cv][i]] == 0)
				return;
		}
	
	}

	return;
}

void dfs(int n, int cnt){
	for (int i = 0; i < e[n].size(); i++){
		if (ans[e[n][i]] < 0){
			ans[e[n][i]] = cnt;
			dfs(e[n][i], cnt + 1);
		}
	}

	return;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for (int i = 1; i <= N; i++){
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	memset(ans, -1, sizeof(ans));


	check[1] = 1;
	for (int i = 0; i < e[1].size(); i++){
		check[e[1][i]] = check[1] + 1;
		findCycle(1, e[1][i]);
	}

	for (int i = 1; i <= N; i++){
		if (ans[i] == 0){
			for (int j = 0; j < e[i].size(); j++){
				if (ans[e[i][j]] < 0){
					ans[e[i][j]] = 1;
					dfs(e[i][j], 2);
				}
			}
		}
	}


	for (int i = 1; i <= N; i++)
		cout << ans[i] << " ";
	cout << "\n";

	return 0;
}
