#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <algorithm>

using namespace std;

int N, K, coin[100], ans = 0;
long long dp[10001] = { 1, 0 };

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> coin[i];

	for (int i = 0; i < N; i++){
		for (int j = 1; j <= K; j++){
			if (coin[i] <= j)
				dp[j] += dp[j - coin[i]];
		}
	}

	cout << dp[K];

	return 0;
}
