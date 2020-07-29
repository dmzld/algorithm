#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
bool check[10] = { false, };
long long SB[10][2], ans;

void dfs(int cnt){
	if (cnt == N){
		bool flag = false;
		long long S = 1, B = 0;

		for (int i = 0; i < N; i++){
			if (check[i]){
				flag = true;
				S *= SB[i][0];
				B += SB[i][1];
			}
		}

		if (!flag)
			return;
		else
			if (ans > abs(S - B))
				ans = abs(S - B);

		return;
	}

	dfs(cnt + 1);
	check[cnt] = true;
	dfs(cnt + 1);
	check[cnt] = false;
}

int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> SB[i][0] >> SB[i][1];

	ans = abs(SB[0][0] - SB[0][1]);

	dfs(0);
	
	cout << ans;

	return 0;
}
