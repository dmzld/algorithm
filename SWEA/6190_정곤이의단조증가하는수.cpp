#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int TC;
	
	cin >> TC;
	
	for (int tc = 1; tc <= TC; tc++){

		bool flag = true;
		int N, num[1000], ans = -1;

		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> num[i];
		
		sort(num, num + N, cmp);

		for (int i = 0; i < N - 1; i++){
			if (ans >= num[i] * num[i + 1])
				continue;

			for (int j = i + 1; j < N; j++){
				flag = true;
				int tmp = num[i] * num[j];
				int n = 10;

				while (tmp > 0){
					if (n < tmp % 10){
						flag = false;
						break;
					}
					n = tmp % 10;
					tmp /= 10;
				}

				if (flag){
					if (ans < num[i] * num[j])
						ans = num[i] * num[j];
					break;
				}
			}
		}

		cout << "#" << tc << " " << ans << "\n";

	}

	return 0;
}
