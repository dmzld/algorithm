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

		long long N, X, ans = -1;
		cin >> N;

		X = pow(N, 1.0 / 3.0); // because X is integer, pow(N, 1.0/3.0) is saved as floor of pow(N, 1.0/3.0) in X 
		for (long long i = X - 1; i <= X + 1; i++)
			if (pow(i, 3) == N){
				ans = i;
				break;
			}

		cout << "#" << tc << " " << ans << "\n";

	}

	return 0;
}
