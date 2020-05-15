#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int INF = 987654321;

int N;
int map[101][101];
int island[101][101] = { 0, };
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int ans;

void bfs(int num){

	queue<pair<int, int>> q;
	bool check[101][101] = { false, };
	int min = INF, len = 0;

	// push 'num' island to queue ---> this is point of problem that can shorten the time
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++)
			if (island[i][j] == num)
				q.push(make_pair(i, j));
	}

	// make bridge
	while (!q.empty()){
		if (ans < len)
			break;

		int qSize = q.size();
		for (int i = 0; i < qSize; i++){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++){
				int cy = y + dy[j];
				int cx = x + dx[j];

				if (cy < 0 || cy >= N || cx < 0 || cy >= N)
					continue;
				if (check[cy][cx])
					continue;

				if (map[cy][cx] == 1 && num != island[cy][cx]){
					if (min > len)
						min = len;
				}
				else if (map[cy][cx] == 0){
					q.push(make_pair(cy, cx));
					check[cy][cx] = true;
				}
			}
		}
		len++;
	}
	
	if (ans > min)
		ans = min;
}

void numbering(int y, int x, int num){
	island[y][x] = num;

	for (int i = 0; i < 4; i++){
		int cy = y + dy[i];
		int cx = x + dx[i];

		if (cy < 0 || cy >= N || cx < 0 || cx >= N)
			continue;
		if (map[cy][cx] == 0 || island[cy][cx] != 0)
			continue;

		numbering(cy, cx, num);
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
		}
	}
	ans = INF;

	// numbering island
	int num = 1;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (map[i][j] == 1 && island[i][j] == 0){
				numbering(i, j, num);
				num++;
			}
		}
	}

	// make bridge
	for (int i = 1; i <= num; i++){
		bfs(i);
	}

	cout << ans;

	return 0;
}
