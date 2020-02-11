#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[8][8];
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
int ans = 0;

void bfs(){
	int tmp[8][8];
	bool check[8][8] = { false, };
	queue<pair<int, int>> q;
	int res = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++){
			tmp[i][j] = map[i][j];
			if (map[i][j] == 2){
				check[i][j] = true;
				q.push({ i, j });
			}
		}

	while (!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int j = 0; j < 4; j++){
			int cy = y + dy[j];
			int cx = x + dx[j];

			if (cy < 0 || cy >= N || cx < 0 || cx >= M)
				continue;
			if (check[cy][cx] || tmp[cy][cx] == 1)
				continue;

			tmp[cy][cx] = 2;
			check[cy][cx] = true;
			q.push({ cy, cx });
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (tmp[i][j] == 0)
				res++;

	if (ans < res)
		ans = res;
}


int main(){

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (map[i][j] == 0){
				map[i][j] = 1; // wall 1
				for (int p = 0; p < N; p++){
					for (int q = 0; q < M; q++){
						if (map[p][q] == 0){
							map[p][q] = 1; //  wall 2
							for (int r = 0; r < N; r++){
								for (int s = 0; s < M; s++){
									if (map[r][s] == 0){
										map[r][s] = 1; // wall 3
										bfs();
										map[r][s] = 0;
									}
								}
							}
							map[p][q] = 0;
						}
					}
				}
				map[i][j] = 0;
			}
		}
	}

	cout << ans;

	return 0;
}
