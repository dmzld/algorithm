#include <iostream>
#include <algorithm>

using namespace std;

int N, A[21][21], tot, ans;

void calculate(int y, int x, int d1, int d2){
	int diff, d[6] = { 0, }, maxD = 0, minD = tot;

	diff = 0;
	// dist1 : 1 <= r < x+d1 , 1 <= c <=y
	for (int r = 1; r < y + d1; r++){
		if (r >= y) diff++;
		for (int c = 1; c <= x - diff; c++)
			d[1] += A[r][c];
	}
	
	diff = 0;
	// dist2 : 1 <= r <= x+d2 , y < c <= N
	for (int r = 1; r <= y + d2; r++){
		if (r > y) diff++;
		for (int c = x + 1 + diff; c <= N; c++)
			d[2] += A[r][c];
	}

	diff = 0;
	// dist3 : x+d1 <= r <= N , 1 <= c < y-d1+d2
	for (int r = N; r >= y + d1; r--){
		if (r < y + d1 + d2) diff++;
		for (int c = 1; c < x - d1 + d2 - diff; c++)
			d[3] += A[r][c];
	}
	
	diff = 0;
	// dist4 : x+d2 < r <=N , y-d1+d2 <= c <= N
	for (int r = N; r > y + d2; r--){
		if (r <= y + d1 + d2) diff++;
		for (int c = x - d1 + d2 + diff; c <= N; c++)
			d[4] += A[r][c];
	}		

	// dist5 : tot - (sum of dist 1~4)
	d[5] = tot - (d[1] + d[2] + d[3] + d[4]);


	for (int i = 1; i <= 5; i++){
		minD = min(minD, d[i]);
		maxD = max(maxD, d[i]);
	}

	ans = min(ans, maxD - minD);
}

void divide(int y, int x){
	for (int d1 = 1; d1 < N; d1++){
		for (int d2 = 1; d2 < N; d2++){
			if (y + d1 + d2 <= N && x - d1 >= 1 && x + d2 <= N){
				calculate(y, x, d1, d2);
			}
		}
	}
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++){
			cin >> A[i][j];
			tot += A[i][j];
		}
	ans = tot;
			
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			divide(i, j); // y, x

	cout << ans;
	
	return 0;
}
