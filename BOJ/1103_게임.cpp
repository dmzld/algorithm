#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pos{
	int y, x;
};

int N, M;
char map[50][50];
pos d[4] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
bool check[50][50] = { false, };
int dp[50][50] = { 0, };
int ans = 0;

void dfs(int y, int x, int cnt){

	// cout << y << x << " : " << cnt << "\n";
	if (ans < cnt)
		ans = cnt;

	dp[y][x] = cnt;
	int dist = (int)(map[y][x] - '0');

	for (int i = 0; i < 4; i++){
		int ny = y + d[i].y * dist,
			nx = x + d[i].x * dist;

		if (ny < 0 || ny >= N || nx < 0 || nx >= M || map[ny][nx] == 'H'){
			if (ans < cnt + 1)
				ans = cnt + 1;
			continue;
		}
			
		if (check[ny][nx]){ // infinite cycle
			cout << -1;
			exit(0);
		}

		if (dp[ny][nx] >= cnt + 1)
			continue;

		check[ny][nx] = true;
		dfs(ny, nx, cnt + 1);
		check[ny][nx] = false;
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
		}
	}

	dfs(0, 0, 0);

	cout << ans;

	return 0;
}
