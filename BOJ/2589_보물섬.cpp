#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int R, C;
char map[50][50]; // L : land, W : water
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
int ans = 0;

void bfs(int y, int x){
	bool update = false;
	int cnt = 0;
	queue<pair<int, int>> q;
	int check[50][50] = { 0, };
	check[y][x] = 1; // start from 1 to use bfs
	q.push({ y, x });

	while (!q.empty()){		
		int qSize = q.size();
		for (int i = 0; i < qSize; i++){
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			ans = max(ans, check[cy][cx] - 1); // time = check[][] - 1

			for (int j = 0; j < 4; j++){
				int ny = cy + dy[j];
				int nx = cx + dx[j];
				
				if (ny < 0 || ny >= R || nx < 0 || nx >= C)
					continue;
				if (check[ny][nx] > 0 || map[ny][nx] != 'L')
					continue;

				check[ny][nx] = check[cy][cx] + 1;
				q.push({ ny, nx });
			}
		}
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			if (map[i][j] == 'L')
				bfs(i, j);
		}
	}

	cout << ans;

	return 0;
}
