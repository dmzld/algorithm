#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

/*
	이분 그래프의 성질을 파악하고 표현할 방식을 생각해내고
	해당 방식을 bfs와 dfs를 복합적으로 사용하여 정답을 도출
	vector 배열을 사용하는 것 또한 관건이었음
*/

int K, V, E;
int v[20001] = { 0, };
vector<int> e[20001];

void dfs(int n, int color){
	v[n] = color;

	for (int i = 0; i < e[n].size(); i++){
		if (!v[e[n][i]]) // colored not yet
			dfs(e[n][i], 3 - color); // next color is depended on current color
	}
}

bool validation(){
	for (int i = 1; i <= V; i++){
		for (int j = 0; j < e[i].size(); j++){
			if (v[i] == v[e[i][j]])
				return false;
		}
	}
	return true;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K;

	for (int i = 0; i < K; i++){
		cin >> V >> E;

		// init 
		memset(v, 0, sizeof(v));
		for (int j = 0; j <= V; j++)
			e[j].clear();
		
		// input
		for (int j = 0; j < E; j++){
			int v1, v2;
			cin >> v1 >> v2;
			e[v1].push_back(v2);
			e[v2].push_back(v1);
		}

		// bfs
		for (int j = 1; j <= V; j++){
			if (v[j] == 0) // not colored
				dfs(j, 1);
		}

		if (validation())
			cout << "YES\n";	
		else
			cout << "NO\n";
	}
}
