#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int TC;
	
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++){

		long long N;
		cin >> N;

		// 1. if infinite loop, there will be dup num
		// 2. if N/2 can be 1 in condition of (N%2 == 0), Yes
		//		because of 3*N+3 == 3(N+1)

		// method 2
		while (N % 2 == 0)
			N /= 2;

		if (N == 1)
			cout << "#" << tc << " YES" << "\n";
		else
			cout << "#" << tc << " NO" << "\n";

	}

	return 0;
}
