#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, K, ans;


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	
	int l = 1, r = K;
	while (l <= r){
		int cnt = 0, mid = (l + r) / 2; // search B[k] using mid

		for (int i = 1; i <= N; i++){
			cnt += min(mid / i, N);
		}

		if (cnt < K)
			l = mid + 1;
		else{
			ans = mid;
			r = mid - 1;
		}
	}

	cout << ans;


	return 0;
}
