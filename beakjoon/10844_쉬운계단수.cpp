#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int	N; 
long ans = 0; //, d[101][10]
long d[2][10];

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	d[1][0] = 0;
	for (int i = 1; i <= 9; i++)
		d[1][i] = 1;

	for (int i = 2; i <= N; i++){
		d[i % 2][0] = d[(i - 1) % 2][1];
		for (int j = 1; j < 9; j++){
			d[i % 2][j] = (d[(i - 1) % 2][j - 1] + d[(i - 1) % 2][j + 1]) % 1000000000;
		}
		d[i % 2][9] = d[(i - 1) % 2][8];
	}

	for (int i = 0; i <= 9; i++)
		ans = (ans + d[N % 2][i]) % 1000000000;

	cout << ans;

	return 0;
}
