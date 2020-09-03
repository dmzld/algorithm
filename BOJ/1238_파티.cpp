#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

struct compare{
	bool operator()(pair<int, int> a, pair<int, int> b){
		return a.first > b.first;
	}
};

int N, M ,X;
vector <pair<int, int>> v[1001]; // v[src] = { time, dest }
vector<int> dist[1001];
int ans = 0;

vector<int> dijkstra(int src){
	vector<int> d(N + 1, 987654321); // cost to move from src to others
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq; // time, from
	pq.push({ 0, src });

	while (!pq.empty()){
		int from = pq.top().second, time = pq.top().first;
		pq.pop();

		for (int i = 0; i < v[from].size(); i++){
			int to = v[from][i].second;
			int totTime = time + v[from][i].first;

			if (totTime < d[to]){
				d[to] = totTime;
				pq.push({ totTime, to });
			}
		}
	}

	return d;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> X;
	for (int i = 0; i < M; i++){
		int s, d, t;
		cin >> s >> d >> t;
		v[s].push_back({ t, d });
	}

	for (int i = 1; i <= N; i++)
		dist[i] = dijkstra(i);

	for (int i = 1; i <= N; i++){
		if (i == X) continue;
		if (ans < dist[i][X] + dist[X][i])
			ans = dist[i][X] + dist[X][i];
	}

	cout << ans;

	return 0;
}
