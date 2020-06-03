#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <climits>

using namespace std;

int N, M, S, D;
int U, V, P, INF = 987654321;
vector<vector<pair<int,int>>> map; // <vertex, weight>
vector<vector<int>> route; // adjacent vertexes
vector<int> res;

vector<int> dijstra(int s, int d){
	vector<int> dp(N, INF);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // <weight, vertex>

	dp[s] = 0;
	pq.push({ 0, s });
	while (!pq.empty()){
		int from = pq.top().second;
		int weight = pq.top().first;
		pq.pop();

		if (dp[from] < weight)
			continue;

		for (int i = 0; i < map[from].size(); i++){
			if (map[from][i].second == -1) // erased edge
				continue;

			int to = map[from][i].first;
			int totalWeight = weight + map[from][i].second;

			if (dp[to] > totalWeight){
				dp[to] = totalWeight;
				pq.push({ totalWeight, to });

				route[to].clear();
				route[to].push_back(from);
			}
			else if (dp[to] == totalWeight)
				route[to].push_back(from);
		}
	}

	return dp;
}

void bfs(int v){
	bool check[500][500] = { false, };
	queue<int> q;
	q.push(v); // search from destination to start reversely

	while (!q.empty()){
		int to = q.front();
		q.pop();

		for (int i = 0; i < route[to].size(); i++){
			int from = route[to][i];
			if (!check[from][to]){
				check[from][to] = true;

				for (int j = 0; j < map[from].size();j++)
					if (map[from][j].first == to){
						map[from][j].second = -1; // erase edge
						break;
					}
				q.push(from);
			}
		}
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (1){
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;

		map = vector<vector<pair<int, int>>>(N);
		route = vector<vector<int>>(N);

		cin >> S >> D;
		for (int i = 0; i < M; i++){
			cin >> U >> V >> P;
			map[U].push_back({ V, P });
		}

		dijstra(S, D);

		bfs(D);

		res = dijstra(S, D);

		if (res[D] == INF)
			cout << "-1\n";
		else
			cout << res[D] << "\n";
	}

	return 0;
}
