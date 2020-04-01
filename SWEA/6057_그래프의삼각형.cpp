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

		int N, M, v1, v2, ans = 0;
		bool arr[51][51] = { false, };
		
		cin >> N >> M;
		for (int i = 0; i < M; i++){
			cin >> v1 >> v2;
			arr[v1][v2] = true;
			arr[v2][v1] = true;
		}

		for (int i = 1; i < N - 1; i++){
			for (int j = i + 1; j < N; j++){
				if (arr[i][j]){
					for (int k = j + 1; k <= N; k++){
						if (arr[i][k] && arr[j][k]){
							ans++;
						}
					}
				}
			}
		}

		cout << "#" << tc << " " << ans << "\n";

	}

	return 0;
}
