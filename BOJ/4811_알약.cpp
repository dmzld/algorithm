#include <iostream>

using namespace std;

int N;
long long pill[31][31]; // # of W, H

long long dp(int W, int H){
	if (W < 0 || H < 0)
		return 0;

	if (W == 0) // && H == 0 : no more W, then just add H continuous
		return 1;

	if (pill[W][H] != 0)
		return pill[W][H];
	else
		pill[W][H] = dp(W - 1, H + 1) + dp(W, H - 1);

	return pill[W][H];
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	dp(30, 0);

	for (int tc = 0; tc < 1000; tc++){
		cin >> N;

		if (N == 0) break;

		cout << pill[N][0] << "\n";
	}

	return 0;
}
