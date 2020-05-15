#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int map[50][50];
vector<pair<int, int>> v;

int cmap[50][50];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int ans = 987654321;

bool validation(){

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (cmap[i][j] == 0)
				return false;
		}
	}

	return true;
}

void bfs(){
	queue<pair<int, int>> q;

	// init cmap
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++){
			cmap[i][j] = map[i][j]; // 0, wall : 1, inactive virus : 2, active virus : 3
			if (cmap[i][j] == 3)
				q.push({ i, j }); // can diffuse
		}

	int time = 0;
	while (!q.empty() && time < ans){
		if (validation()){ // is room full of virus?
			if (ans > time){
				ans = time;
			}
			return;
		}

		time++;
		int qSize = q.size();
		for (int i = 0; i < qSize; i++){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++){
				int cy = y + dy[j];
				int cx = x + dx[j];

				if (cy < 0 || cy >= N || cx < 0 || cx >= N)
					continue;
				if (cmap[cy][cx] == 1 || cmap[cy][cx] == 3) // wall, active virus
					continue;

				cmap[cy][cx] = 3;
				q.push({ cy, cx });
			}
		}
	}

}

void placeVirus(int cnt, int n){
	if (cnt == M){
		bfs();
		return;
	}

	for (int i = n; i < v.size(); i++){
		int y = v[i].first, x = v[i].second;
		map[y][x] = 3; // 2 -> 3

		placeVirus(cnt + 1, i + 1);

		map[y][x] = 2; // 3 -> 2	
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> map[i][j]; // 0,1,2
			if (map[i][j] == 2)
				v.push_back({ i, j }); // virus position
		}
	}

	placeVirus(0, 0);

	if (ans == 987654321)
		cout << -1;
	else
		cout << ans;

	return 0;
}
