#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int N, M, A, B, C;
vector<pair<int, long long>> G[501]; // G[from] = { to, time }
vector<long long> ans;

vector<long long> bellmanFord(int src){
	vector<long long> D(501, LLONG_MAX);
	bool update = false;
	D[src] = 0;

	for (int i = 0; i < N; i++){ // # of vertex
		update = false;
		for (int from = 1; from <= N; from++){
			if (D[from] == LLONG_MAX) continue;

			for (int j = 0; j < G[from].size(); j++){ // from * j == # of edge (j == # of adjcent vertex with from)
				int to = G[from][j].first;
				long long time = G[from][j].second;

				if (D[to] > D[from] + time){
					update = true;
					D[to] = D[from] + time;
				}
			}
		}
		if (!update) break;
	}

	if (update) // if D was updated until iteration N(# of vertex), it means graph has cycle of minus
		return vector<long long>(1, -1);
	else
		return D;
}

int main(){

	cin >> N >> M;
	for (int i = 0; i < M; i++){
		cin >> A >> B >> C;
		G[A].push_back({ B, C });
	}

	ans = bellmanFord(1);

	if (ans.size() == 1)
		cout << -1;
	else{
		for (int i = 2; i <= N; i++){ // src == 1
			if (ans[i] == LLONG_MAX)
				cout << "-1\n";
			else
				cout << ans[i] << "\n";
		}
	}

	return 0;
}
