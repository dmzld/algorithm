#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

int V, E, a, b, c;
int e[401][401]; // distance, start point
int ans = INT_MAX;

int main(){

	cin >> V >> E;
	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
			e[i][j] = INT_MAX;

	for (int i = 0; i < E; i++){
		cin >> a >> b >> c;
		e[a][b] = { c };
	}

	for (int p = 1; p <= V; p++){
		for (int i = 1; i <= V; i++){
			for (int j = 1; j <= V; j++){
				if (e[i][p] == INT_MAX || e[p][j] == INT_MAX) continue;
				if (e[i][j] > e[i][p] + e[p][j])
					e[i][j] = e[i][p] + e[p][j];
			}
		}
	}

	for (int i = 1; i <= V; i++)
		ans = min(ans, e[i][i]);

	if (ans == INT_MAX)
		cout << -1;
	else
		cout << ans;

	return 0;
}
