#include <iostream>
#include <algorithm>

using namespace std;

int N, d[10000][6], ans = 0;


int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> d[i][0] >> d[i][1] >> d[i][2] >> d[i][4] >> d[i][5] >> d[i][3];
	}

	for (int i = 0; i < 6; i++){ // first bottom side
		int bot = i, cnt = 0, res = 0;

		while (cnt < N){
			// adding maximum value that is not bottom side & upper side
			int val = 0;
			for (int j = 0; j < 6; j++){
				if ((j != bot && j != (bot + 3) % 6) && val < d[cnt][j])
					val = d[cnt][j];
			}
			res += val;

			// finding next dice's bottom
			if (cnt < N - 1){
				int upp = d[cnt][(bot + 3) % 6];

				for (int j = 0; j < 6; j++){
					if (upp == d[cnt + 1][j]){
						bot = j;
						break;
					}
				}
			}
			cnt++;
		}

		ans = max(ans, res);
	}

	cout << ans;

	return 0;
}
