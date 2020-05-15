#include <iostream>

using namespace std;

int N;
int map[16][16];
int cnt = 0;
pair<int, int> pipe[2] = { make_pair(0, 0), make_pair(0, 1) };
pair<int, int> curPipe[2];

void init(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			scanf("%d", &map[i][j]);
		}
	}
}

void bfs(int sr, int sc, int er, int ec) {

	if (sr < 0 || sr >= N || sc < 0 || sc >= N || er < 0 || er >= N || ec < 0 || ec >= N)
		return;

	if (er == N - 1 && ec == N - 1){
		cnt++;
		return;
	}

	// 가로
	if (sr == er&&sc < ec){
		if (!map[er][ec + 1]){
			bfs(sr, sc + 1, er, ec + 1);
			if (!map[er + 1][ec + 1] && !map[er + 1][ec])
				bfs(sr, sc + 1, er + 1, ec + 1);
		}
	}
	// 세로
	else if (sr < er&&sc == ec){
		if (!map[er + 1][ec]){
			bfs(sr + 1, sc, er + 1, ec);
			if (!map[er + 1][ec + 1] && !map[er][ec + 1])
				bfs(sr + 1, sc, er + 1, ec + 1);
		}
	}
	// 대각선
	else if (sr < er&&sc < ec){
		if (!map[er][ec + 1])
			bfs(sr + 1, sc + 1, er, ec + 1);
		if (!map[er + 1][ec])
			bfs(sr + 1, sc + 1, er + 1, ec);
		if (!map[er + 1][ec] && !map[er][ec + 1] && !map[er + 1][ec + 1])
			bfs(sr + 1, sc + 1, er + 1, ec + 1);
	}
	return;
}

int main(){

	init();

	bfs(0,0,0,1);

	printf("%d", cnt);

	return 0;
}
