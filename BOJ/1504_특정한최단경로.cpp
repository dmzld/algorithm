#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>

using namespace std;

int N, E, u, v, w, v1, v2;
vector<pair<int,int>> G[801]; //  pair<v, w> G[u]
vector<int> R1, R2, R3;
priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> pq; // for dijkstra
int A1, A2;

vector<int> dijkstra(int start){

	vector<int> D(N + 1, INT_MAX);
	D[start] = 0; // starting point
	
	pq.push({ 0, start }); // from starting point
	while (!pq.empty()){
		int weight = pq.top().first;
		int from = pq.top().second;
		pq.pop();

		if (D[from] < weight)
			continue;

		for (int i = 0; i < G[from].size(); i++){
			int to = G[from][i].first; // vertex can be arrived
			int nWeight = G[from][i].second;

			if (D[to] > nWeight + weight){ // distance of K ~ from ~ to
				D[to] = nWeight + weight; // update min distance K to to
				pq.push({ nWeight + weight, to });
			}
		}
	}	
	return D;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> E;

	for (int i = 0; i < E; i++){
		cin >> u >> v >> w;
		G[u].push_back({ v, w });
		G[v].push_back({ u, w });
	}
	cin >> v1 >> v2;

	R1 = dijkstra(1); // 1 to v1, 1 to v2
	R2 = dijkstra(v1); // v1 to v2, v1 to N
	R3 = dijkstra(v2); // v2 to v1, v2 to N
	
	A1 = (R1[v1] != INT_MAX && R2[v2] != INT_MAX && R3[N] != INT_MAX) ? R1[v1] + R2[v2] + R3[N] : INT_MAX;
	A2 = (R1[v2] != INT_MAX && R3[v1] != INT_MAX && R2[N] != INT_MAX) ? R1[v2] + R3[v1] + R2[N] : INT_MAX;

	if (A1 == INT_MAX&&A2 == INT_MAX)
		cout << -1;
	else
		cout << min(A1, A2);

	return 0;
}
