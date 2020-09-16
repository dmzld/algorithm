#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int T;
int N, M, L, R, C;
int map[50][50];
bool check[50][50];
vector<vector<pair<int, int>>> dir({
	vector<pair<int, int>>{},
	vector<pair<int, int>>{{-1, 0}, { 1, 0 }, { 0, -1 }, { 0, 1 }},
	vector<pair<int, int>>{{-1, 0}, { 1, 0 }},
	vector<pair<int, int>>{{0, -1}, { 0, 1 }},
	vector<pair<int, int>>{{-1, 0}, { 0, 1 }},
	vector<pair<int, int>>{{1, 0}, { 0, 1 }},
	vector<pair<int, int>>{{1, 0}, { 0, -1 }},
	vector<pair<int, int>>{{-1, 0}, { 0, -1 }}
	});
int cnt, ans;

void init(){
	cnt = 1, ans = 0;
	cin >> N >> M >> R >> C >> L;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	memset(check, false, sizeof(check));
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++){
		init();

		if (L == 0){
			cout << "#" << t << " " << 0 << "\n";
			continue;
		}

		queue<pair<int, int>> q;
		
		q.push({ R, C });
		check[R][C] = true;
		ans++;

		while (!q.empty() && cnt < L){
			cnt++;
			int qSize = q.size();

			for (int i = 0; i < qSize; i++){
				int y = q.front().first, x = q.front().second,
					d = map[y][x];
				q.pop();

				for (int j = 0; j < dir[d].size(); j++){
					int ny = y + dir[d][j].first, nx = x + dir[d][j].second,
						nr = dir[d][j].first, nc = dir[d][j].second;

					if (ny < 0 || ny >= N || nx < 0 || nx >= M || check[ny][nx] || map[ny][nx] == 0)
						continue;
					for (int k = 0; k < dir[map[ny][nx]].size(); k++){
						if (dir[map[ny][nx]][k].first == -nr &&dir[map[ny][nx]][k].second == -nc){
							q.push({ ny, nx });
							check[ny][nx] = true;
							ans++;
							break;
						}
					}

				}
			}
		}

		cout << "#" << t << " " << ans << "\n";
	}


	return 0;
}
