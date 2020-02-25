#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int map[10][10];
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
int num = 0; // # of island
int conn[7] = { 0, 1, 2, 3, 4, 5, 6 }; // 1 ~ 6 island connnets to conn[1 ~ 6]
vector<pair<int,pair<int,int>>> b; // len, v1, v2
int ans = 0;

void numbering(){
	bool check[10][10] = { false, };
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (map[i][j] == 1 && !check[i][j]){
				num++;
				map[i][j] = num;
				queue<pair<int, int>> q;
				q.push({ i, j });
				check[i][j] = true;

				while (!q.empty()){
					int qSize = q.size();
					for (int k = 0; k < qSize; k++){
						int y = q.front().first;
						int x = q.front().second;
						q.pop();

						for (int p = 0; p < 4; p++){
							int cy = y + dy[p];
							int cx = x + dx[p];

							if (cy < 0 || cy >= N || cx < 0 || cx >= M)
								continue;
							if (check[cy][cx] || map[cy][cx] == 0)
								continue;

							map[cy][cx] = num;
							check[cy][cx] = true;
							q.push({ cy, cx });
						}
					}
				}
			}
		}
	}
}

void makeBridge(){
	bool island[7] = { false, };
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			// for one island
			if (map[i][j] != 0 && !island[map[i][j]]){ // map[i][j] == island's number
				int cnum = map[i][j]; // current island's number
				int e[7] = { 0, }; // bridge length between cnum and idx(1 ~ 6)
				queue<pair<int, int>> q;
				queue<pair<int, int>> q2; // area of current island
				bool check[10][10] = { false, };

				island[map[i][j]] = true;
				q.push({ i, j });
				check[i][j] = true;

				// find area of current island to q2
				while (!q.empty()){
					int qSize = q.size();
					for (int k = 0; k < qSize; k++){
						int y = q.front().first;
						int x = q.front().second;
						q2.push({ y, x });
						q.pop();

						for (int l = 0; l < 4; l++){
							int cy = y + dy[l];
							int cx = x + dx[l];

							if (cy < 0 || cy >= N || cx < 0 || cx >= M)
								continue;
							if (map[cy][cx] != cnum || check[cy][cx])
								continue;

							q.push({ cy, cx });
							check[cy][cx] = true;
						}
					}
				}
				
				// based on area, make bridge with another island
				while (!q2.empty()){
					int y = q2.front().first, x = q2.front().second;
					q2.pop();

					for (int k = 0; k < 4; k++){ // dir
						int cy = y + dy[k], cx = x + dx[k];
						int len = 0;
						while (cy >= 0 && cy < N && cx >= 0 && cx < M){
							if (map[cy][cx] != cnum && map[cy][cx] != 0){ // arrive another island
								if (len > 1 && (e[map[cy][cx]] == 0 || e[map[cy][cx]] > len)){
									e[map[cy][cx]] = len;
								}
								break;
							}
							else if (map[cy][cx] == 0){
								len++;
								cy += dy[k];
								cx += dx[k];
							}
							else if (map[cy][cx] == cnum){
								break;
							}
						}
					}
				}
				
				// save bridge
				for (int i = 1; i < 7; i++){
					if (e[i] > 1){ // bridge length must be longer than 1
						if (cnum < i)
							b.push_back({ e[i], { cnum, i }});
						else
							b.push_back({ e[i], { i, cnum }});
					}
				} // it can make dup, need improve
			}
		}
	}
}

void selectBridge(){
	sort(b.begin(), b.end()); // for selecting shorten bridge

	for (int i = 0; i < b.size(); i++){
		// cycle check
		if (conn[b[i].second.first] != conn[b[i].second.second]){ // b[i].second.first < second
			// update conn 
			int u1 = conn[b[i].second.first];
			int u2 = conn[b[i].second.second];
			int u = (u1 < u2) ? u1 : u2; // u1, u2 will be u
			int tmp = (u1 < u2) ? u2 : u1;

			for (int j = 1; j <= num; j++){
				if (conn[j] == tmp) 
					conn[j] = u;
			}
			ans += b[i].first;
		}
	}
}

bool allConnected(){
	for (int i = 2; i <= num; i++)
		if (conn[i] != 1)
			return false;
	return true;
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

	numbering(); // bfs
	makeBridge(); // union&find
	selectBridge(); // find shortedt cycle with kruskal algorithm

	if (allConnected())
		cout << ans;
	else
		cout << -1;

	return 0;
}
