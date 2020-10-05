#include <iostream>

using namespace std;

int R, C;
char map[10000][500];
int dir[3] = { -1, 0, 1 }; // 위에서부터 순서대로 탐색
bool check[10000][500] = { false, };
int ans = 0;

bool dfs(int y, int x){
	if (x == C - 1){
		ans++;
		return true; // 도달
	}

	for (int i = 0; i < 3; i++){
		int ny = y + dir[i], nx = x + 1;

		if (ny < 0 || ny >= R || map[ny][nx] == 'x' || check[ny][nx])
			continue;

		check[ny][nx] = true;

		if (dfs(ny, nx))
			return true;

		// 도달하지 못했다 해도 (ny, nx)는 어쩌피 도달못할 경로이기 때문에 false로 바꿀 필요 X
	}

	return false; // 다음 단계로 못나아간 경우
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> map[i][j];
	
	for (int i = 0; i < R; i++)
		dfs(i, 0);

	cout << ans;

	return 0;
}
