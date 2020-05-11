#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, num[501][501], ans = 0;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= i; j++)
			cin >> num[i][j];
			
	for (int i = 2; i <= N; i++){
		for (int j = 1; j <= i; j++){
			if (j == 1) num[i][j] += num[i - 1][1];
			else if (j == i) num[i][j] += num[i - 1][i - 1];
			else num[i][j] += max(num[i - 1][j - 1], num[i - 1][j]);
		}
	}

	for (int i = 1; i <= N; i++)
		if (ans < num[N][i]) ans = num[N][i];

	cout << ans;

	return 0;
}
