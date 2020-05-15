#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>

using namespace std;

int main(){

	int N, M;
	char c[100];
	int dx[4] = { 1, -1, 0, 0 };
	int dy[4] = { 0, 0, 1, -1 };


	cin >> N >> M;
	vector< vector<int> > maze(N, vector<int>(M, 0));
	vector< vector<int> > visited(N, vector<int>(M, 0));
	queue< pair<int, int> > q;

	
	for (int i = 0; i < N; i++){
		cin >> c;
		for (int j = 0; j < M; j++){
			maze[i][j] = c[j] - 48;
			if (maze[i][j]==1)
				visited[i][j] = 1;
		}
	}

	q.push(make_pair(0, 0));
	
	while (!q.empty()){

		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++){
			int cx = x + dx[i];
			int cy = y + dy[i];

			if (cx < 0 || cx >= N || cy < 0 || cy >= M)
				continue;
			if (visited[cx][cy] != 1)
				continue;

			q.push(make_pair(cx, cy));
			visited[cx][cy] += visited[x][y];
		}		
	}


	cout << visited[N - 1][M - 1];

	
	return 0;
	
}
