#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int N, M;
// vector<vector<int>> P; // paper
// vector<vector<bool>> C; // checked
int P[500][500];
bool C[500][500];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int res = -1;

void solution(int y, int x, int cnt, int sum){ // dfs for normal shape
	if (cnt >= 4){
		if (res < sum)
			res = sum;
		return;
	}

	for (int i = 0; i < 4; i++){
		int cx = x + dx[i];
		int cy = y + dy[i];

		if (cx < 0 || cx >= M || cy < 0 || cy >= N)
			continue;
		if (C[cy][cx])
			continue;
		
		C[cy][cx] = true;
		solution(cy, cx, cnt + 1, sum + P[cy][cx]);
		C[cy][cx] = false;
	}
}

void extra_solution(int y, int x){ // for extra shape
	if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < M){ // ㅗ
		int sum = P[y][x] + P[y][x - 1] + P[y - 1][x] + P[y][x + 1];
		if (res < sum) res = sum;
	}
	if (y + 1 < N && y - 1 >= 0 && x + 1 < M){ // ㅏ
		int sum = P[y][x] + P[y + 1][x] + P[y - 1][x] + P[y][x + 1];
		if (res < sum) res = sum;
	}
	if (x - 1 >= 0 && y + 1 < N && x + 1 < M){ // ㅜ
		int sum = P[y][x] + P[y][x - 1] + P[y + 1][x] + P[y][x + 1];
		if (res < sum) res = sum;
	}
	if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < N){ // ㅓ
		int sum = P[y][x] + P[y][x - 1] + P[y - 1][x] + P[y + 1][x];
		if (res < sum) res = sum;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++){ // y
		for (int j = 0; j < M; j++){ // x
			cin >> P[i][j];
		}
	}

	for (int i = 0; i < N; i++){ // for different start point
		for (int j = 0; j < M; j++){
			memset(C, false, sizeof(C));
			C[i][j] = true;
			solution(i, j, 1, P[i][j]); // y, x, cnt, sum
			extra_solution(i, j);
			C[i][j] = false;
		}
	}

	cout << res;

	return 0;
}
