#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <utility>

using namespace std;

int N, M;
int maze[1000][1000];
// 이전에 벽을 뚫은 상태/아닌 상태로 지나갔는가
int visited[1000][1000][2]; // y, x, F/T
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
queue< pair< pair<int, int>, int> > q; // i, j, F/T

int func(){
	q.push(make_pair(make_pair(0, 0), 1));
	visited[0][0][1] = 1;

	while (!q.empty()){
    // x,col,M <-> y,row,N
		int x = q.front().first.second;
		int y = q.front().first.first;
		int can = q.front().second;
		q.pop();

		//printf("(%d, %d), time = %d\n", x, y, time);

		if (x == M - 1 && y == N - 1){
			return visited[y][x][can];
		}

		for (int i = 0; i < 4; i++){
			int cx = x + dx[i];
			int cy = y + dy[i];

			if (cx >= 0 && cx < M && cy >= 0 && cy < N){
				if (maze[cy][cx] == 1 && can){ // 벽, 뚫을수 있을 때
					q.push(make_pair(make_pair(cy, cx), 0));
					visited[cy][cx][can - 1] = visited[y][x][can] + 1; // 
				}
				else if (maze[cy][cx] == 0 && visited[cy][cx][can] == 0){ // 벽X, 방문X
					q.push(make_pair(make_pair(cy, cx), can));
					visited[cy][cx][can] = visited[y][x][can] + 1;
				}
			}
		}

	}
	return -1;
}

int main(){

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			scanf("%1d", &maze[i][j]);
		}
	}
	
	printf("%d", func());

	return 0;
}
