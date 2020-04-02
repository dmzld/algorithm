#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int val[1000000];

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int TC;
	
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++){

		int N, max = 0;
		long ans = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> val[i];

		for (int i = N - 1; i >= 0; i--){
			if (max < val[i])
				max = val[i];
			
			if (max > val[i])
				ans += (max - val[i]);
		}

		cout << "#" << tc << " " << ans << "\n";

	}

	return 0;
}
