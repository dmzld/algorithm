#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N;
char map[100][100];
bool chk[100][100] = { false, };
pair<int, int> d[4] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
int cnt[2] = { 0, }; // for rgb, rb

void bfs(int sy, int sx, int idx){
	cnt[idx]++;
	char color = map[sy][sx];

	queue<pair<int, int>> q;
	chk[sy][sx] = true;
	q.push({ sy, sx });
	
	while (!q.empty()){
		int qSize = q.size();
		for (int i = 0; i < qSize; i++){
			int y = q.front().first, x = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++){
				int ny = y + d[j].first, nx = x + d[j].second;

				if (ny >= 0 && ny < N && nx >= 0 && nx < N && map[ny][nx] == color && !chk[ny][nx]){
					chk[ny][nx] = true;
					q.push({ ny, nx });
				}
			}
		}
	}
}

// if the top, bottom, left, and right colors are the same, they are the same area including the center
// not used
void merge(int y, int x, int idx){
	int c1 = map[y][x], c2 = map[y + d[0].first][x + d[0].second];
	if (c1 != c2){
		for (int i = 1; i < 4; i++){
			int ny = y + d[i].first, nx = x + d[i].second;

			if (ny < 0 || ny >= N || nx < 0 || nx >= N || c2 != map[ny][nx])
				return;
		}
			
		cnt[idx]--;
	}
	return;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> N;

	// rgb
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (!chk[i][j])
				bfs(i, j, 0);
		}
	}

	// rb
	memset(chk, false, sizeof(chk));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] == 'G')
				map[i][j] = 'R';

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (!chk[i][j])
				bfs(i, j, 1);
		}
	}

	cout << cnt[0] << " " << cnt[1] << "\n";

	return 0;
}
