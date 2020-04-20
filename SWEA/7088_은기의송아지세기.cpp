#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int cow[100001], ans[100001][4];

int main(){

	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++){

		int N, Q, L, R;
		int c1 = 0, c2 = 0, c3 = 0;

		cin >> N >> Q;

		for (int i = 1; i <= N; i++){
			cin >> cow[i];
			if (cow[i] == 1)
				c1++;
			else if (cow[i] == 2)
				c2++;
			else if (cow[i] == 3)
				c3++;
			
			ans[i][1] = c1, ans[i][2] = c2, ans[i][3] = c3; // ans[i][n] == i번째까지 누적된 고유번호 n의 송아지 수
		}

		cout << "#" << tc << "\n";
		for (int i = 1; i <= Q; i++){
			cin >> L >> R;
			if (L == 0)
				cout << ans[R][1] - ans[0][1] << " " << ans[R][2] - ans[0][2] << " " << ans[R][3] - ans[0][3] << "\n";
			else
				cout << ans[R][1] - ans[L - 1][1] << " " << ans[R][2] - ans[L - 1][2] << " " << ans[R][3] - ans[L - 1][3] << "\n";
		}
	}


	return 0;
}
