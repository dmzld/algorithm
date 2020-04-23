#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int T;
int N, h[50001]; 

int main(){

	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int tc = 1; tc <= T; tc++){
		int ans = 0;

		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> h[i];

		for (int i = 1; i <= N - 2; i++){
			if (h[i] < h[i + 1]){ // start
				int j = i, L = 0, R = 0; // 
				while (h[j] < h[j + 1] && j <= N - 2){
					L++;
					j++;
				}
				// j == pivot
				if (h[j] > h[j + 1]){
					while (h[j] > h[j + 1] && j <= N - 1){
						R++;
						j++;
					}
				}
				ans += R * L; // based on pivot, mutiply left and right
				i = j - 1;
			}
		}
		
		cout << "#" << tc << " " << ans << "\n";
		
	}


	return 0;
}
