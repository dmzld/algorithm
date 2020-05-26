#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int V;
vector<pair<int, int>> G[100001];
bool check[100001] = { false, };
int leafNode = 0, ans = 0;

void dfs(int node, int distance){
	check[node] = true;

	if (ans < distance){
		leafNode = node;
		ans = distance;
	}

	for (int i = 0; i < G[node].size(); i++)
		if (!check[G[node][i].first])
			dfs(G[node][i].first, distance + G[node][i].second);
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V;

	for (int i = 0; i < V;i++){
		int v1, v2, d;
		cin >> v1;
		while (1){
			cin >> v2;
			if (v2 == -1) break;
			cin >> d;

			G[v1].push_back({ v2, d });
			G[v2].push_back({ v1, d });
		}
	}
	
	// ***node 1 always exists
	dfs(1, 0);
	memset(check, false, (V + 1)*sizeof(bool));
	
  // ***from leafNode, find real the longest distance
	dfs(leafNode, 0);

	cout << ans;

	return 0;
}
