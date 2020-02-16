#include <iostream>
#include <vector>

using namespace std;

int R, C, T;
int map[50][50];
vector<int> cleaner;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
int ans = 0;

void diffusion(){
	int tmp[50][50] = { 0, };

	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			if (map[i][j]>0){
				int cnt = 0;
				for (int k = 0; k < 4; k++){
					int cy = i + dy[k];
					int cx = j + dx[k];

					if (cy < 0 || cy >= R || cx < 0 || cx >= C)
						continue;
					if (map[cy][cx] < 0)
						continue;

					cnt++;
					tmp[cy][cx] += map[i][j] / 5;
				}
				map[i][j] -= (map[i][j] / 5)*cnt;
			}
		}
	}

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			map[i][j] += tmp[i][j];
}

void clear(){
	int y, x = 0;
	// topside cleaner
	y = cleaner[0];

	for (y = y - 2; y >= 0; y--)
		map[y + 1][x] = map[y][x];
	y++;
	for (x = x + 1; x < C; x++)
		map[y][x - 1] = map[y][x];
	x--;
	for (y = y + 1; y <= cleaner[0]; y++)
		map[y - 1][x] = map[y][x];
	y--;
	for (x = x - 1; x > 0; x--)
		map[y][x + 1] = map[y][x];
	
	map[y][1] = 0;


	// bottomside cleaner
	y = cleaner[1], x = 0;
	
	for (y = y + 2; y < R; y++)
		map[y - 1][x] = map[y][x];
	y--;
	for (x = x + 1; x < C; x++)
		map[y][x - 1] = map[y][x];
	x--;
	for (y = y - 1; y >= cleaner[1]; y--)
		map[y + 1][x] = map[y][x];
	y++;
	for (x = x - 1; x > 0; x--)
		map[y][x + 1] = map[y][x];
	
	map[y][1] = 0;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C >> T;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cin >> map[i][j];
			if (map[i][j] == -1)
				cleaner.push_back(i);
		}
	}

	for (int i = 0; i < T; i++){
		diffusion();

		clear();
	}

	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			ans += map[i][j];
		}
	}

	cout << ans + 2;

	return 0;
}
