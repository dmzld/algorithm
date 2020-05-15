#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int	K, N;
long long L[10000] = { 0, }, ans = 0, s, e;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> K >> N;
	for (int i = 0; i < K; i++)
		cin >> L[i];

	sort(L, L + K);

	s = 1, e = L[K - 1];
	while (s <= e){

		long long mid = (e + s) / 2, tot = 0;

		for (int i = K - 1; i >= 0; i--){
			if (L[i] / mid == 0)
				break;
			else
				tot += L[i] / mid;
		}
		
    // ** mid +1, -1 .....!!
		if (tot < N)
			e = mid - 1;
		else{
			s = mid + 1;
			if (ans < mid)
				ans = mid;
		}

	}

	cout << ans;

	return 0;
}
