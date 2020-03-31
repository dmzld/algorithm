#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int TC;

	cin >> TC;
	
	for (int tc = 1; tc <= TC; tc++){

		long long N, L, R; // 1 <= N <= 10^9 .. longlong
		cin >> N;
		

		L = (N - 1) * (N - 1) + 1;
		R = N * N;


		cout << "#" << tc << " " << 2 * L - 1 << " " << 2 * R  - 1<< "\n";
	}

	return 0;
}
