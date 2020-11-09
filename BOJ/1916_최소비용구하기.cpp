#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

struct comp{
	bool operator()(pair<int, int> a, pair<int, int> b){
		return a.second > b.second;
	}
};

int N, M, s, d, c;
vector<vector<pair<int, int>>> e;
int dp[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	e.resize(N + 1);
	for (int i = 1; i <= N; i++)
		dp[i] = 987654321;
	
	for (int i = 0; i < M; i++){
		cin >> s >> d >> c;
		e[s].push_back({ d, c });
	}
	cin >> s >> d; // src, dest

	dp[s] = 0;
	pq.push({ s, 0 });

	while (!pq.empty()){
		int src = pq.top().first, cost = pq.top().second;
		pq.pop();

		if (dp[src] < cost)
			continue;

		for (int i = 0; i < e[src].size(); i++){
			int dest = e[src][i].first, ccost = dp[src] + e[src][i].second;

			if (dp[dest] > ccost){
				pq.push({ dest, ccost });
				dp[dest] = ccost;
			}
		}
	}

	cout << dp[d];

	return 0;
}
