#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int T, N, M;
int snack[1000];
int ans;

int main(){

	cin >> T;
	for (int i = 0; i < T; i++){
		cin >> N >> M;
		
		memset(snack, 0, 4 * N);
		ans = -1;

		for (int j = 0; j < N; j++){
			cin >> snack[j];
		}

		sort(snack, snack + N);
		
		for (int j = 0; j < N - 1; j++){
			if (snack[j] > M)
				break;

			for (int k = N - 1; k > j; k--){
				if (snack[j] + snack[k] <= M && ans < snack[j] + snack[k]){
					ans = snack[j] + snack[k];
					break;
				}
			}
		}


		cout << "#" << i + 1 << " " << ans << "\n";
	}
	
	return 0;
}
