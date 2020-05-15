#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, D;
int map[15 + 1][15] = { 0, };
int cmap[15 + 1][15] = { 0, };
int dy[3] = { 0, -1, 0 }; // not need to bottomside
int dx[3] = { -1, 0, 1 };

int ans = 0;

bool allKill(){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (cmap[i][j] == 1)
				return false;

	return true;
}

void solution(){
	int res = 0;
	vector<pair<int, int>> v; // position of arhcer
	for (int i = 0; i <= N; i++) // N == archer
		for (int j = 0; j < M; j++){
			cmap[i][j] = map[i][j];
			if (cmap[i][j] == 2){
				v.push_back({ i, j }); // save position of archer
			}
		}
		
	for (int i = 0; i < N; i++){ // while every enemy comes castle
		if (allKill()){ // 
			if (ans < res)
				ans = res;
			return;
		}
		
		queue<pair<int, int>> kill[3]; // enemy who will killed by 'i'th archer
		queue<pair<int, int>> q[3]; // bfs
		for (int j = 0; j < 3; j++)
			q[j].push({ v[j].first, v[j].second });

		for (int j = 0; j < 3; j++){ // each archer
			
			bool check[15][15] = { false, };
			int distance = 0;

			while (distance < D && !q[j].empty() && kill[j].size() == 0){ // for jth archer
				int qSize = q[j].size();
				distance++;
				
				for (int p = 0; p < qSize; p++){
					int y = q[j].front().first;
					int x = q[j].front().second;
					q[j].pop();

					for (int k = 0; k < 3; k++){
						int cy = y + dy[k];
						int cx = x + dx[k];

						if (cy < 0 || cy >= N || cx < 0 || cx >= M)
							continue;
						if (check[cy][cx])
							continue;
						if (cmap[cy][cx] == 1){
							kill[j].push({ cy, cx });
							break;
						}
						else{
							q[j].push({ cy, cx });
							check[cy][cx] = true;
						}
					}
				}
			}
		}

		// kill enemies
		for (int j = 0; j < 3; j++){
			if (kill[j].size() > 0){ // if jth archer can kill
				if (cmap[kill[j].front().first][kill[j].front().second] == 1){ // if not dup
					cmap[kill[j].front().first][kill[j].front().second] = 0;
					res++; // total kill++
				}
			}
		}
		// enemies come to castle
		for (int k = N - 1; k > 0; k--)
			for (int j = 0; j < M; j++)
				cmap[k][j] = cmap[k - 1][j];
		for (int j = 0; j < M; j++)
			cmap[0][j] = 0;
	}


	if (ans < res)
		ans = res;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> D;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
		}
	}

	// archer 1,2,3
	for (int i = 0; i < M; i++){
		for (int j = i + 1; j < M; j++){
			for (int k = j + 1; k < M; k++){
				map[N][i] = 2;
				map[N][j] = 2;
				map[N][k] = 2;
				solution();
				map[N][i] = 0;
				map[N][j] = 0;
				map[N][k] = 0;
			}
		}
	}

	cout << ans;

	return 0;
}
