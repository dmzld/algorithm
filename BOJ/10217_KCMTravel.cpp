#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

// DP & Dijkstra

int T, N, M, K;
int u, v, c, d;
vector<pair<int, pair<int, int>>> G[101]; // G[from] = { cost, { distance, to }}
int ans = INT_MAX;

void dijkstra(int src){
	int distanceByCost[101][10001]; // distance = timeByCost[vertex][Cost]
	priority_queue< pair<int, pair<int, int>>,
		vector<pair<int, pair<int, int>>>,
		greater<pair<int, pair<int, int>>>> pq; // { cost, { distance, final vertex }}
	
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= M; j++)
			distanceByCost[i][j] = INT_MAX;

	distanceByCost[1][0] = 0;
	pq.push({ 0, { 0, src } });

	while (!pq.empty()){
		int cost = pq.top().first;
		int distance = pq.top().second.first;
		int from = pq.top().second.second;
		pq.pop();

		if (distanceByCost[from][cost] < distance)
			continue;

		for (int i = 0; i < G[from].size(); i++){
			int totalCost = cost + G[from][i].first;
			int totalDistance = distance + G[from][i].second.first;
			int to = G[from][i].second.second;

			if (totalCost > M)
				continue;

			if (distanceByCost[to][totalCost] > totalDistance){
				for (int i = totalCost; i <= M; i++)
					if (distanceByCost[to][i] > totalDistance)
						distanceByCost[to][i] = totalDistance;
				pq.push({ totalCost, { totalDistance, to } });
			}
		}
	}

	int ans = INT_MAX;
	for (int i = 0; i <= M; i++)
		ans = min(ans, distanceByCost[N][i]);

	if (ans == INT_MAX)
		cout << "Poor KCM\n";
	else
		cout << ans << "\n";
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int tc = 1; tc <= T; tc++){
		cin >> N >> M >> K;

		for (int i = 0; i <= N; i++)
			G[i].clear();

		for (int i = 0; i < K; i++){
			cin >> u >> v >> c >> d;
			G[u].push_back({ c, { d, v } });
		}

		dijkstra(1);
	}

	return 0;
}
