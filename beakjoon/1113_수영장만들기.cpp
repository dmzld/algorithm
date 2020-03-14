#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int map[50][50];
bool check[50][50] = { false, };
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
int ans = 0;

void bfs(int sy, int sx, int h){
	queue<pair<int, int>> q;
	queue<pair<int, int>> q2;
	memset(check, false, sizeof(check));
	int fence = 9;
	
	q.push({ sy, sx });
	q2.push({ sy, sx });
	check[sy][sx] = true;

	// collect block to q2
	while (!q.empty()){
		int qSize = q.size();
		for (int i = 0; i < qSize; i++){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++){
				int cy = y + dy[j];
				int cx = x + dx[j];

				if (cy < 0 || cy >= N || cx < 0 || cx >= M)
					continue;
				if (!check[cy][cx] && map[cy][cx] == h){
					if (cy == 0 || cy == N - 1 || cx == 0 || cx == M - 1) // if block have edge
						return;
					q.push({ cy, cx });
					q2.push({ cy, cx });
					check[cy][cx] = true;
				}
			}
		}
	}

	while (!q2.empty()){
		int y = q2.front().first;
		int x = q2.front().second;
		q.push(q2.front());
		q2.pop();

		for (int i = 0; i < 4; i++){
			int cy = y + dy[i];
			int cx = x + dx[i];

			if (map[cy][cx] < fence && !check[cy][cx])
				fence = map[cy][cx];
			if (fence < h) // like edge that have height 1
				return;
		}
	}

	while (!q.empty()){
		ans += (fence - map[q.front().first][q.front().second]);
		map[q.front().first][q.front().second] = fence;
		q.pop();
	}
}

void searchBlock(int h){
	// not edge
	for (int i = 1; i < N - 1; i++){ 
		for (int j = 1; j < M - 1; j++){
			if (map[i][j] == h){
				bfs(i, j, h);
			}
		}
	}
}

int main(){	

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &map[i][j]);

	for (int i = 1; i <= 8; i++){
		searchBlock(i);
	}

	printf("%d", ans);

	return 0;
}
