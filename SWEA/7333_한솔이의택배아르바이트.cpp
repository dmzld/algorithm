#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++){
		
		int N, W[100], idx, ans = 0;
		bool check[100] = { false, };

		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> W[i];

		sort(W, W + N, cmp);
		idx = N - 1;

		for (int i = 0; i < N; i++){
			if (check[i])
				break;
			
			bool flag = true;
			int cnt = 1;
			while (W[i] * cnt < 50)
				cnt++;

			check[i] = true;
			for (int j = idx; j > idx - (cnt - 1); j--){
				if (!check[j])
					check[j] = true;
				else{
					flag = false;
					break;
				}
			}

			if (flag){
				idx -= (cnt - 1);
				ans++;
			}
		}

		cout << "#" << tc << " " << ans << "\n";

	}


	return 0;
}
