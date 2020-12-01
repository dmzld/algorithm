#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

struct state{
	int y, x, t, m;
};

struct comp{
	bool operator()(state a, state b){
		return a.t > b.t;
	}
};

int N, M, map[10][10];
priority_queue<state, vector<state>, comp> pq;
bool check[10][10][2] = { false, };
pair<int, int> dir[4] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
int ans = INT_MAX;

void bfs(){
	// init
	pq.push({ 0, 0, 0, 1 });
	for (int i = 0; i < 2; i++)
		check[0][0][i] = true;

	// search
	while (!pq.empty()){
		state s = pq.top();
		pq.pop();

		if (s.y == N - 1 && s.x == N - 1){
			if (ans > s.t)
				ans = s.t;
			continue;
		}

		for (int i = 0; i < 4; i++){
			int ny = s.y + dir[i].first, nx = s.x + dir[i].second;

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;

			if (map[ny][nx] == -1)
				continue;

			if (map[ny][nx] == 1 && !check[ny][nx][s.m]){ // just go
				pq.push({ ny, nx, s.t + 1, s.m });
				check[ny][nx][s.m] = true;
			}
			else if (map[ny][nx] == 0 && !check[ny][nx][0]){ // make new bridge
				if (s.m == 0 || map[s.y][s.x] != 1) // 절벽인데 (이미 오작교를 만들었거나 || 바로 이전에도 절벽(오작교)일 때)
					continue;

				int nt = 0;
				while (nt < s.t + 1)
					nt += M;

				pq.push({ ny, nx, nt, 0 });
				check[ny][nx][0] = true;
			}
			else if (map[ny][nx] > 1 && !check[ny][nx][s.m]){ // cross the bridge
				if (map[s.y][s.x] != 1) // 바로 이전에도 절벽(오작교)일때
					continue;

				int nt = map[ny][nx];
				while (nt < s.t + 1)
					nt += map[ny][nx];

				pq.push({ ny, nx, nt, s.m });
				check[ny][nx][s.m] = true;
			}
		}
	}
	return;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

  // mark map where can't be built bridge
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++){
			if (map[i][j] == 0){
				bool ver = false, hor = false;
				for (int k = 0; k < 2; k++){
					int y = i + dir[k].first, x = j + dir[k].second;

					if ((y >= 0 && y < N&&x >= 0 && x < N) && map[y][x] != 1){
						hor = true;
						break;
					}
				}
				for (int k = 2; k < 4; k++){
					int y = i + dir[k].first, x = j + dir[k].second;

					if ((y >= 0 && y < N&&x >= 0 && x < N) && map[y][x] != 1){
						ver = true;
						break;
					}
				}

				if (ver&&hor)
					map[i][j] = -1;
			}
		}

	bfs();

	cout << ans;

	return 0;
}
