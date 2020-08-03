#include <iostream>
#include <queue>

using namespace std;

int M, N, map[501][501] = { 0, }, dp[501][501];
int dy[4] = { 1, -1, 0, 0 }, dx[4] = { 0, 0, 1, -1 };

int dfs(int y, int x){
	if (y == 0 && x == 0)
		return 1;
	
	if (dp[y][x] == -1){
		dp[y][x] = 0;
		for (int i = 0; i < 4; i++){
			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || ny >= M || nx < 0 || nx >= N)
				continue;
			if (map[y][x] < map[ny][nx])
				dp[y][x] += dfs(ny, nx);
		}
	}
	return dp[y][x];
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
			dp[i][j] = -1;
		}

	cout << dfs(M - 1, N - 1);

	return 0;
}
