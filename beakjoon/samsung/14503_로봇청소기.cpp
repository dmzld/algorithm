#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, r, c, d;
int map[50][50];
bool check[50][50] = { false, };
pair<int, int> dir[4] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
int ans = 0;

void dfs(int y, int x){
	if (!check[y][x]){
		check[y][x] = true;
		ans++;
	}

  // find place to clean
	int cDir = d;
	for (int i = 0; i < 4; i++){
		cDir = (cDir + 3) % 4;
		
		if (y + dir[cDir].first < 0 || y + dir[cDir].first >= N || x + dir[cDir].second < 0 || x + dir[cDir].second >= M)
			continue;
		if (check[y + dir[cDir].first][x + dir[cDir].second] || map[y + dir[cDir].first][x + dir[cDir].second] == 1)
			continue;

		int tmp = d;
		d = cDir;
		dfs(y + dir[cDir].first, x + dir[cDir].second);
		d = tmp;
	}
	
  // if no place to clean, go back by current direction
	d = cDir; // maintain cur dir
	cDir = (cDir + 2) % 4; // and back
	if (map[y + dir[cDir].first][x + dir[cDir].second] == 1){
		cout << ans;
		exit(0); //  exit(1) => runtime error
	}
	else
		dfs(y + dir[cDir].first, x + dir[cDir].second);
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	dfs(r, c);

	cout << ans;

	return 0;
}
