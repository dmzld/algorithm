#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int N, map[500][500], K;
int check[500][500] = { 0, };
pair<int, int> dir[4] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };

int dp(int y, int x){
	if (check[y][x] != 0) return check[y][x];

	check[y][x] = 1;

	for (int i = 0; i < 4; i++){
		int ny = y + dir[i].first, nx = x + dir[i].second;

		if (ny < 0 || ny >= N || nx < 0 || nx >= N || map[y][x] >= map[ny][nx])
			continue;

		check[y][x] = max(check[y][x], dp(ny, nx) + 1);
	}

	return check[y][x];
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	K = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			K = max(K, dp(i, j));
	
	cout << K;

	return 0;
}
