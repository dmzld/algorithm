#include <iostream>
#include <queue>

using namespace std;

int H, W;
char map[1000][1000];
queue<pair<int, int>> q;
int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0};
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int ans = 0;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> H >> W;
	for (int i = 0; i < H; i++){
		cin >> map[i];
	}

	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			if (map[i][j] != '.'){
				int cnt = 0;
				for (int k = 0; k < 8; k++){
					int cy = i + dy[k], cx = j + dx[k];
					
					if (cy < 0 || cy >= H || cx < 0 || cx >= W)
						continue;
					if (map[cy][cx] == '.')
						cnt++;
				}
				if (cnt >= map[i][j] - '0'){
					q.push({ i, j });
				}
			}
		}
	}

	while (!q.empty()){
		ans++;
		queue<pair<int, int>> q2;
		bool check[1000][1000] = { false, };

		while(!q.empty()){ // 부순다
			int y = q.front().first, x = q.front().second;
			q.pop();
			map[y][x] = '.';

			for (int i = 0; i < 8; i++){
				int cy = y + dy[i], cx = x + dx[i]; // 부서진 곳의 주변 모래성
				if (cy >= 0 && cy < H && cx >= 0 && cx < W
					&& map[cy][cx] != '.' && !check[cy][cx]){
					check[cy][cx] = true;
					q2.push({ cy, cx });
				}
			}
		}

		while (!q2.empty()){ // 부순 뒤 상황에서
			int y = q2.front().first, x = q2.front().second; // 부서진 곳의 주변 모래성
			q2.pop();
			int cnt = 0;
			
			for (int j = 0; j < 8; j++){
				int cy = y + dy[j], cx = x + dx[j];
				
				if (cy < 0 || cy >= H || cx < 0 || cx >= W)
					continue;
				if (map[cy][cx] == '.')
					cnt++;
			}

			if (cnt >= map[y][x] - '0')
				q.push({ y, x }); // 조건이 바뀐 모래성들
		}
	}


	cout << ans;
	
	return 0;
}
