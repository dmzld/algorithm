#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int T; // test case
int n, m, t; // # of vertet, edge, candidate of destination
int s, g, h; // starting point, between g and h
int a, b, d; // distance d between a and b

vector<pair<int, int>> G[2001]; // graph[v1] = { v2, weight}
int C[2001]; // candidates
vector<int> sD, gD, hD;

vector<int> dijkstra(int s){
	vector<int> D(n + 1, -1); // shortest distance s to index vertex
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq; // pair<weight, next vertex>

	D[s] = 0;
	pq.push({ 0, s });

	while (!pq.empty()){
		int from = pq.top().second;
		int weight = pq.top().first;
		pq.pop();

		if (D[from] < weight)
			continue;

		for (int i = 0; i < G[from].size(); i++){
			int totalWeight = weight + G[from][i].second;
			int to = G[from][i].first;

			if (D[to] == -1 || D[to] > totalWeight){
				D[to] = totalWeight;
				pq.push({ totalWeight, to });
			}
		}
	}

	return D;
}

int main(){

	cin >> T;
	for (int tc = 0; tc < T; tc++){
		cin >> n >> m >> t;
		cin >> s >> g >> h;

		// init
		for (int i = 1; i <= n; i++)
			G[i].clear();


		for (int i = 0; i < m; i++){
			cin >> a >> b >> d;
			G[a].push_back({ b, d });
			G[b].push_back({ a, d });
		}

		for (int i = 0; i < t; i++)
			cin >> C[i];

		sD = dijkstra(s); // s to g, s to h, s to C
		gD = dijkstra(g); // g to h, g to C
		hD = dijkstra(h); // h to g, h to C

		// if s to C == ( s to g, g to h, h to C || s to h, h to g, g to C )
		// C can be determined as destination
		vector<int> ans;
		for (int i = 0; i < t; i++){
			if (sD[C[i]] == (sD[g] + gD[h] + hD[C[i]])
				|| sD[C[i]] == (sD[h] + hD[g] + gD[C[i]]))
				ans.push_back(C[i]);
		}
		sort(ans.begin(), ans.end());

		for (int i = 0; i < ans.size(); i++)
			cout << ans[i] << " ";
		cout << "\n";
		
	}


	return 0;
}
