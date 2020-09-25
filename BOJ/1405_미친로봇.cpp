#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <functional>
#include <cmath>

using namespace std;

int N;
bool check[30][30] = { false, };
double per[4];
pair<int, int> dir[4] = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };
double ans = 0.0;

void dfs(int y, int x, int cnt, double p){
	if (cnt == N){
		ans += p;
		return;
	}

	for (int i = 0; i < 4; i++){
		int ny = y + dir[i].first, nx = x + dir[i].second;

		if (check[ny][nx]) continue;

		check[ny][nx] = true;
		dfs(ny, nx, cnt + 1, p*per[i]);
		check[ny][nx] = false;
	}

	return;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < 4; i++){
		cin >> per[i];
		per[i] *= 0.01;
	}

	check[15][15] = true;
	dfs(15, 15, 0, 1.0);

	// 소수점 설정
	cout << fixed;
	cout.precision(9);
	cout << ans;
	
	return 0;
}
