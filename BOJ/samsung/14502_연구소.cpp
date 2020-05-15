#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int map[8][8];
vector<pair<int, int>> v;
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
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
			if (map[i][j] == 0)
				v.push_back({ i, j }); // this point reduce code & loop
		}

	for (int i = 0; i < v.size() - 2; i++){
		for (int j = i + 1; j < v.size() - 1; j++){
			for (int k = j + 1; k < v.size(); k++){
				map[v[i].first][v[i].second] = 1;
				map[v[j].first][v[j].second] = 1;
				map[v[k].first][v[k].second] = 1;

				bfs();
				
				map[v[i].first][v[i].second] = 0;
				map[v[j].first][v[j].second] = 0;
				map[v[k].first][v[k].second] = 0;
			}
		}
	}

	cout << ans;

	return 0;
}
