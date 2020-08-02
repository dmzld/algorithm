#include <iostream>
#include <vector>

using namespace std;

int N, K;
long long num[201][201] = { 0, };

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 0; i <= N; i++)
		num[1][i] = 1;

	for (int k = 2; k <= K; k++){
		for (int n = 0; n <= N; n++){
			
			for (int i = 0; i <= n; i++){
				num[k][n] += num[k - 1][i];
			}
			num[k][n] %= 1000000000;
		}
	}

	cout << num[K][N];

	return 0;
}
