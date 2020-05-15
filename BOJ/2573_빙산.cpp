#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

/*
	전부 녹았는지 검증 -> 녹임 -> 나뉘어졌는지 검증 (반복)
	검증 단계가 아쉬움
*/

int N, M;
int map[300][300] = { 0, };
int cmap[300][300] = { 0, };
bool check[300][300];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int ans = 0;

void dfs(int y, int x){
	check[y][x] = true;
	
	for (int i = 0; i < 4; i++){
		int cy = y + dy[i], cx = x + dx[i];
		
		if (cy < 0 || cy >= N || cx < 0 || cx >= M)
			continue;
		if (cmap[cy][cx] == 0 || check[cy][cx])
			continue;
		
		dfs(cy, cx);
	}
}

bool validation(){
	bool flag = false;
	memset(check, false, sizeof(check));

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (cmap[i][j] != 0){
				if (!flag){ // run dfs just 1 time
					dfs(i, j); 
					flag = true;
				}
				else if (flag && check[i][j] == 0) // if find not checked iceberg after 1 dfs, it means iceberg is divided more than 2 pieces
					return true; // divided
			}
		}
	}
	return false;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
		}
	}

	while (1){
		ans++;
		bool over = true;

		// is melting over?
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				if (map[i][j] != 0){
					over = false;
					break;
				}
			} if (!over) break;
		}
		if (over) break;

		// melting
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++){
				if (map[i][j] != 0){
					int d = 0;
					for (int k = 0; k < 4; k++){
						int cy = i + dy[k], cx = j + dx[k];

						if (cy < 0 || cy >= N || cx < 0 || cx >= M)
							continue;
						if (map[cy][cx] != 0)
							continue;

						d++;
					}
					cmap[i][j] = map[i][j] - d;
					if (cmap[i][j] < 0)
						cmap[i][j] = 0;
				}
				else
					cmap[i][j] = map[i][j];
			}
		}

		//validation
		if (validation()){
			cout << ans;
			return 0;
		}

		// cmap -> map
		for (int i = 0; i < N; i++){
			for (int j = 0; j < M; j++)
				map[i][j] = cmap[i][j];
		}
	}

	// not divided until melting is over
	cout << 0;
	return 0;
}
