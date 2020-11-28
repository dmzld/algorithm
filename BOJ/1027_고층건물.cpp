#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <climits>
#include <cfloat>

using namespace std;

int N, ans = 0, h[50];
bool check[50][50];
const double INF = -1.0 * 1000000001;

int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> h[i];

	for (int i = 0; i < N; i++){
		int cnt = 0;
		double mArc = INF;

		for (int j = i + 1; j < N; j++){
			double cArc = 1.0 * (h[j] - h[i]) / (j - i);
			if (mArc < cArc){
				cnt++;
				mArc = cArc;
				check[i][j] = true;
			}
		}

		for (int j = 0; j < i; j++){
			if (check[j][i])
				cnt++;
		}

		if (ans < cnt)
			ans = cnt;
	}

	cout << ans;


	return 0;
}
