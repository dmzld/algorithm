#include <iostream>
#include <vector>

using namespace std;

int H, W;
char map[1000][1000];
bool check[1000][1000] = { false, };
vector<pair<int, int>> v;
int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int ans = 0;

int adj(int y, int x){
	int cnt = 0;
	for (int i = 0; i < 8; i++){
		if (map[y + dy[i]][x + dx[i]] == '.')
			cnt++;
	}
	return cnt;
}

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
				if (adj(i,j) >= map[i][j] - '0'){ // 처음에 부서질 곳
					check[i][j] = true;
					v.push_back({ i, j });
				}
			}
		}
	}

	while (!v.empty()){
		ans++;
		vector<pair<int, int>> v2;

		for (int i = 0; i < v.size(); i++)
			map[v[i].first][v[i].second] = '.';

		for (int i = 0; i < v.size(); i++){
			int y = v[i].first, x = v[i].second;
			for (int j = 0; j < 8; j++){
				int cy = y + dy[j], cx = x + dx[j];
				if (map[cy][cx] != '.' && adj(cy, cx) >= map[cy][cx] - '0' && !check[cy][cx]){
					check[cy][cx] = true;
					v2.push_back({ cy, cx });
				}
			}
		}
		v = v2;
	}


	cout << ans;
	
	return 0;
}
