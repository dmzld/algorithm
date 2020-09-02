#include <iostream>
#include <cstring>

using namespace std;

int N, M;
char map[50][50];
bool check[50][50];
pair<int, int> dir[4] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

bool dfs(int sy, int sx, int y, int x, int cnt){
	bool cycle = false;

	for (int i = 0; i < 4; i++){
		int ny = y + dir[i].first, nx = x + dir[i].second;
		if (ny >= 0 && ny < N && nx >= 0 && nx < M){
			if (ny == sy && nx == sx && cnt >= 4)
				return true;
			
			if (!check[ny][nx] && map[ny][nx] == map[sy][sx]){
				check[ny][nx] = true;
				cycle = dfs(sy, sx, ny, nx, cnt + 1);
				check[ny][nx] = false;
				if (cycle)
					return true;
			}
		}
	}

	return cycle;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			memset(check, false, sizeof(check));

			check[i][j] = true;
			if (dfs(i, j, i, j, 1)){
				cout << "Yes\n";
				return 0;
			}
		}
	}

	cout << "No\n";
	return 0;
}
