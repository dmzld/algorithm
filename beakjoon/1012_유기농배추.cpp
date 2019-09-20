#include <iostream>
#include <utility>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main(){

	int T, M, N, K; // 시행 횟수, 가로, 세로, 배추 수
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };

	cin >> T;

	for (int i = 0; i < T; i++){
		int w = 0; // warm
		queue< pair<int,int> > q;

		cin >> M >> N >> K;

		vector< vector<int> > f(M, vector<int>(N, 0)); // farm
		vector< vector<int> > visited(M, vector<int>(N, 0));
		
		for (int j = 0; j < K; j++){
			int m, n;
			cin >> m >> n;
			f[m][n] = 1;
		}

		for (int j = 0; j < M; j++){
			for (int l = 0; l < N; l++){
				if (f[j][l] == 1 && visited[j][l]==0){ // 배추 단지 시작
					w++;
					// visited[j][l] = 1;
					q.push(make_pair(j, l));

					while (!q.empty()){
						int x = q.front().first;
						int y = q.front().second;
						// visited[x][y] = 1;

						q.pop();

						for (int m = 0; m < 4; m++){ // 상하좌우
							int cx = x + dx[m];
							int cy = y + dy[m];

							if (cx >= M || cx < 0 || cy >= N || cy < 0) // farm 밖
								continue;
							if (f[cx][cy] == 0 || visited[cx][cy] == 1) // 배추X or 이미 방문
								continue;
							visited[cx][cy] = 1;
							q.push(make_pair(cx, cy));
						}

					}
				}
			}
		}


		cout << w << "\n";
	}


	return 0;	
}
