#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

int N, M, V;
int v[1001];
int e[1001][1001] = { 0, };
int d_visited[1001] = { 0, };
int b_visited[1001] = { 0, };
queue<int> q;

void dfsFunc(int start){

	printf("%d ", start);
	d_visited[start] = 1;

	for (int i = 0; i <= N; i++){
		if (e[start][i] == 1 && d_visited[i] == 0){
			d_visited[i] = 1;
			dfsFunc(i);
		}
	}
	return;
}
void bfsFunc(int start){

	q.push(start);
	b_visited[start] = 1;
	while (!q.empty()){
		printf("%d ", q.front());
		int cur = q.front();
		q.pop();
		for (int i = 0; i <= N; i++){
			if (e[cur][i] == 1 && b_visited[i] == 0){
				b_visited[i] = 1;
				q.push(i);
			}
		}

	}
}


int main(){

	int dfs, bfs;
	scanf("%d %d %d", &N, &M, &V);
	for (int i = 0; i < M; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		e[x][y] = 1;
		e[y][x] = 1;
	}

	dfsFunc(V);
	printf("\n");
	bfsFunc(V);

	return 0;
}
