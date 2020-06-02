#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C, map[20][20], ans = 0;
bool ABC[26] = { false, }, check[20][20] = { false, };
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };


void dfs(int y, int x, int cnt){
	ans = max(ans, cnt);
	
	for (int i = 0; i < 4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= R || nx < 0 || nx >= C)
			continue;
		if (check[ny][nx] || ABC[map[ny][nx]])
			continue;
		
		check[ny][nx] = true;
		ABC[map[ny][nx]] = true;

		dfs(ny, nx, cnt + 1);
		
		check[ny][nx] = false;
		ABC[map[ny][nx]] = false;
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			char tmp;
			cin >> tmp;
			map[i][j] = (int)(tmp - 'A');
		}
	}

	check[0][0] = true;
	ABC[map[0][0]] = true;
	dfs(0, 0, 1);

	cout << ans;

	return 0;
}
