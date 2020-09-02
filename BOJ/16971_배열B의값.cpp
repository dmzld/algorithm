#include <iostream>
#include <algorithm>

using namespace std;

int N, M, map[1000][1000];
int r[1000] = { 0, }, c[1000] = { 0, }; // only for comparing
int minR = 987654321, minRidx = 1, minC = 987654321, minCidx = 1;
int maxERidx = 0, maxECidx = 0;
int ans = 0;

void changeR(int r1, int r2){
	for (int i = 0; i < M; i++)
		swap(map[r1][i], map[r2][i]);
	return;
}

void changeC(int c1, int c2){
	for (int i = 0; i < N; i++)
		swap(map[i][c1], map[i][c2]);
	return;
}

int B(){
	int res = 0;
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < M - 1; j++)
			res += map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i][j + 1];
	return res;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++){
			r[i] += map[i][j];
			c[j] += map[i][j];
		}


	// no change
	ans = B();

	// sum by row, col
	for (int i = 0; i < N; i++){
		r[i] *= 4;
		r[i] -= (map[i][0] + map[i][M - 1]) * 2;

		if (i != 0 && i != (N - 1) &&minR > r[i]){
			minR = r[i];
			minRidx = i;
		}
	}
	maxERidx = r[0] > r[N - 1] ? 0 : N - 1;


	for (int j = 0; j < M; j++){
		c[j] *= 4;
		c[j] -= (map[0][j] + map[N - 1][j]) * 2;

		if (j != 0 && j != (M - 1) && minC > c[j]){
			minC = c[j];
			minCidx = j;
		}
	}
	maxECidx = c[0] > c[M - 1] ? 0 : M - 1;

	changeR(maxERidx, minRidx);
	ans = max(ans, B());
	changeR(maxERidx, minRidx);

	changeC(maxECidx, minCidx);
	ans = max(ans, B());
	// changeC(maxECidx, minCidx);


	cout << ans;

	return 0;
}
