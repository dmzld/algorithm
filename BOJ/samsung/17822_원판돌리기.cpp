#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

int N, M, T, x, d, k;
int circle[50][50];
bool check[50][50] = { false, };
stack<pair<int, int>> same;
int ans = 0;

void rotate(int n, int d, int k){
	int tmp[50];
	for (int i = 0; i < M; i++)
		tmp[i] = circle[n][i];

	if (d == 0){ // clock
		for (int i = 0; i < M; i++)
			circle[n][i] = tmp[(i + M - k) % M];
	}
	else if (d == 1){ // counter clock
		for (int i = 0; i < M; i++)
			circle[n][i] = tmp[(i + k) % M];
	}
}

void findAdjSame(int n, int m){
	if (circle[n][m] == circle[n][(m + (M - 1)) % M] && !check[n][(m + (M - 1)) % M]) same.push({ n, (m + (M - 1)) % M });
	if (circle[n][m] == circle[n][(m + 1) % M] && !check[n][(m + 1) % M]) same.push({ n, (m + 1) % M });
	if (n - 1 >= 0 && circle[n][m] == circle[n - 1][m] && !check[n - 1][m]) same.push({ n - 1, m });
	if (n + 1 < N && circle[n][m] == circle[n + 1][m] && !check[n + 1][m]) same.push({ n + 1, m });
}

void calculation(){
	memset(check, false, sizeof(check));
	float mid = 0;
	int tot = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++){
			if (circle[i][j] > 0){ // circle[i][j] == 0 means the number was erased
				findAdjSame(i, j);

				tot++;
				mid += circle[i][j];
			}
		}
	
	mid /= tot;

	if (same.empty()){ // there isn't adjacent & same number
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++){
				// is there nothing for equal?
				if (circle[i][j] > 0){
					if (circle[i][j] < mid) circle[i][j]++;
					else if (circle[i][j]>mid) circle[i][j]--;
				}
			}
	}
	else{
		while (!same.empty()){
			circle[same.top().first][same.top().second] = 0;
			same.pop();
		}
	}
}

void solution(int x, int d, int k){
	for (int i = 0; i < N; i++)
		if ((i + 1) % x == 0)  // rotate the circle of the 'x' multiple in the direction 'd' by 'k'
			rotate(i, d, k);

	calculation();
}

int main(){

	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> T;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> circle[i][j];

	for (int i = 0; i < T; i++){
		cin >> x >> d >> k;
		solution(x, d, k);
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			ans += circle[i][j];

	cout << ans;

	return 0;
}
